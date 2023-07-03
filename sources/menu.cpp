#include <cmath>
#include <ctime>

#include "headers/menu.h"
#include "headers/dimension.h"

/*	Contains menu parameters,
	such as guy-button, timer and flag counter	*/

Menu::Menu()
{
	this->restart();
}

void Menu::set_button_state(bool state)
{
	button_state = state;
}

//  It's about time, it's about counter
void Menu::check_menu(bool game_over, int flags, bool victory)
{
	if (game_over) {						//	Stop activity
		finish_time = finish_time;
		counter = counter;
		if (victory)
			guy_state = WINNER_GUY + button_state;
		else
			guy_state = LOSER_GUY + button_state;
	}
	else {									//	Continue activity
		finish_time = time(0);
		if (flags > MINES) {				//	How many?
			counter = 0;
			guy_state = QUIZZICAL_GUY + button_state;
		}
		else {
			counter = MINES - flags;
			guy_state = THINKING_GUY + button_state;
		}
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
	if (index < 2)
		timer %= 60;		//	seconds
	else
		timer /= 60;		//	minutes
	int mod = pow(10, (index % 2) + 1);
	int div = pow(10, (index % 2));
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
	button_state = false;
}