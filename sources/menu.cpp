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

void Menu::set_flag_counter(int flags)
{
	flag_counter = flags;
}

//  It's about time
void Menu::check_timer(bool game_over)
{
	if (game_over)
		finish_time = finish_time;
	else
		finish_time = time(0);
}

int Menu::get_guy_state()
{
	return guy_state;
}

//	Specifies a digit for the timer segment
int Menu::get_digit(int index)
{
	int timer = finish_time - start_time;
	int mod = pow(10, index+1);
	int div = pow(10, index);
	return (timer % mod) / div;
}

int Menu::get_flag_counter()
{
	return flag_counter;
}

//	Initial state of the menu
void Menu::restart()
{
	guy_state = 0;
	start_time = time(0);
	finish_time = time(0);
	flag_counter = 0;
}