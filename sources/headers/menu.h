#pragma once

class Menu
{
	int guy_state;
	int start_time;
	int finish_time;
	int counter;
	bool button_state;

public:
	Menu();
	void set_button_state(bool state);
	void check_menu(bool game_state, int flags, bool victory);
	int get_guy_state();
	int get_timer(int index);
	int get_counter(int index);
	void restart();
};