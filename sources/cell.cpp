#include "headers/cell.h"
#include "headers/dimension.h"

/*	Contains field cell parameters,
	such as state, presence of a flag or mines (in or around)	*/

Cell::Cell()
{
	this->restart();
}

void Cell::set_is_mine()
{
	is_mine = true;
}

void Cell::set_is_flag()
{
	is_flag = !is_flag;
}

void Cell::set_is_open()
{
	is_open = true;
}

void Cell::add_mines_around()
{
	mines_around++;
}

bool Cell::get_is_mine()
{
	return is_mine;
}

bool Cell::get_is_flag()
{
	return is_flag;
}

bool Cell::get_is_open()
{
	return is_open;
}

int Cell::get_mines_around()
{
	return mines_around;
}

//	Initial state of the cell
void Cell::restart()
{
	is_mine = false;
	is_flag = false;
	is_open = false;
	mines_around = 0;
}