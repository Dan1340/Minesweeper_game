#pragma once

class Menu
{
	int guy_state;
	int start_time;
	int finish_time;
	int counter;

public:
	Menu();
	void add_guy_state();
	void check_menu(bool game_state, int flags);
	int get_guy_state();
	int get_timer(int index);
	int get_counter(int index);
	void restart();
};