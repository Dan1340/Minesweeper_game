#include <stdlib.h>
#include <ctime>
#include <vector>

#include "headers/field.h"
#include "headers/dimension.h"

/*	Controls the elements of the playing field 
	based on the actions of the player and the rules of the game	*/

Field::Field()
{
	for (int i = 0; i < COLUMNS * ROWS; i++)
		cells.push_back(Cell());
	
	this->generate();
}

//	Create or reset the playing field
void Field::generate()
{
	game_over = false;
	flags = 0;
	victory = false;

	for (int i = 0; i < cells.size(); i++)
		cells.at(i).restart();				//	Transfer cells to initial state

	srand(time(0));
	int mines = 0;
	while (mines < MINES) {					//	Throwing mines across the field
		int x = rand() % COLUMNS;
		int y = rand() % ROWS;

		if (cells.at(x * COLUMNS + y).get_is_mine())
			continue;									//	Cell is busy, try again

		cells.at(x * COLUMNS + y).set_is_mine();
		mines++;										// Mined!

		for (int a = -1; a < 2; a++) {					//	Notifying the empty cells around about the explosive neighbor
			for (int b = -1; b < 2; b++) {
				if (!(a == 0 && b == 0) && !(x + a < 0 || y + b < 0 || x + a == COLUMNS || y + b == ROWS) 
					&& !cells.at((x + a) * COLUMNS + (y + b)).get_is_mine())
						cells.at((x + a) * COLUMNS + (y + b)).add_mines_around();
			}
		}
	}
}

//	Putting or removing the flag on a closed cell
void Field::flag_cell(int i_x, int i_y)
{
	if (game_over)
		return;											//	Why?
	if (cells.at(i_x * COLUMNS + i_y).get_is_open())
		return;											//	What are you doing here?

	cells.at(i_x * COLUMNS + i_y).set_is_flag();
	if (cells.at(i_x * COLUMNS + i_y).get_is_flag())	//	Counting flags
		flags++;
	else
		flags--;


	this->check_victory();
}

//	Let's see Paul Allen's cell...
void Field::open_cell(int i_x, int i_y)
{
	if (game_over)
		return;											//	What are you looking for?
	if (cells.at(i_x * COLUMNS + i_y).get_is_open())
		return;											//	It's already done, turn back
	if (cells.at(i_x * COLUMNS + i_y).get_is_flag())
		return;											//	The flag is here, cancel operation

	cells.at(i_x * COLUMNS + i_y).set_is_open();		//	Sooooo...

	if (cells.at(i_x * COLUMNS + i_y).get_is_mine()) {
		game_over = true;								//	BOOM!
		return;
	}

	else if (cells.at(i_x * COLUMNS + i_y).get_mines_around() == 0)		//	Success, let's clean the field
		for (int a = -1; a < 2; a++) {
			for (int b = -1; b < 2; b++) {
				if (!(a == 0 && b == 0) && !(a + i_x < 0 || b + i_y < 0 || a + i_x == COLUMNS || b + i_y == ROWS))
						this->open_cell(i_x + a, i_y + b);				//	Let's party!
			}
		}

	this->check_victory();
}

//	Look at that subtle off-white coloring...
char Field::get_view(int i_x, int i_y)
{
	if (game_over && cells.at(i_x * COLUMNS + i_y).get_is_flag() && !cells.at(i_x * COLUMNS + i_y).get_is_mine())
		return VIEW_FLAG_LOSE;										//	Mine is not here
	else if (cells.at(i_x * COLUMNS + i_y).get_is_flag())
		return VIEW_FLAG;
	else if (game_over && !cells.at(i_x * COLUMNS + i_y).get_is_open() && cells.at(i_x * COLUMNS + i_y).get_is_mine())
		return VIEW_CLOSE_LOSE;										//	Mine is here
	else if (!cells.at(i_x * COLUMNS + i_y).get_is_open())
		return VIEW_CLOSE;
	else if (cells.at(i_x * COLUMNS + i_y).get_is_mine())
		return VIEW_MINE_LOSE;
	else
		return cells.at(i_x * COLUMNS + i_y).get_mines_around();	//	By number of neighbors
}

// You have a chance
void Field::check_victory()
{
	for (int i = 0; i < COLUMNS * ROWS; i++) {			//	Cells are clean, mines are flags
		if (cells.at(i).get_is_mine() != cells.at(i).get_is_open()
			&& cells.at(i).get_is_mine() == cells.at(i).get_is_flag())
				continue;
		else
			return;
	}
	game_over = true;
	victory = true;			//	BINGO!
}

bool Field::get_game_over()
{
	return game_over;
}

bool Field::get_victory()
{
	return victory;
}

char Field::get_flags()
{
	return flags;
}
