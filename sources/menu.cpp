#include <cmath>
#include <ctime>

#include "headers/menu.h"
#include "headers/dimension.h"

/*	Contains menu parameters,
	such as button, timer and flag counter	*/

Menu::Menu()
{
	this->restart();
}

void Menu::add_guy_state()
{
	guy_state++;
}

//  It's about time, it's about counter
void Menu::check_menu(bool game_over, int flags)
{
	if (game_over) {
		finish_time = finish_time;
		counter = counter;
	}
	else {
		finish_time = time(0);
		if (flags > MINES)
			counter = 0;
		else
			counter = MINES - flags;
	}
}

int Menu::get_guy_state()
{
	return guy_state;
}

//	Specifies a digit for the timer segment
int Menu::get_timer(int index)
{
	int timer = finish_time - start_time;
	int mod = pow(10, index+1);
	int div = pow(10, index);
	return (timer % mod) / div;
}

//	Specifies a digit for the counter segment
int Menu::get_counter(int index)
{
	int mod = pow(10, index + 1);
	int div = pow(10, index);
	return (counter % mod) / div;
}

//	Initial state of the menu
void Menu::restart()
{
	guy_state = 0;
	start_time = time(0);
	finish_time = time(0);
	counter = MINES;
}