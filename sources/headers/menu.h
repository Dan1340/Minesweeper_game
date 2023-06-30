#pragma once

class Menu
{
	int guy_state;
	int start_time;
	int finish_time;
	int flag_counter;

public:
	Menu();
	void add_guy_state();
	void set_flag_counter(int flags);
	void check_timer(bool game_state);
	int get_guy_state();
	int get_digit(int index);
	int get_flag_counter();
	void restart();
};