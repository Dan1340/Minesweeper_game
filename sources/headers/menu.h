#pragma once

class Menu
{
	char guy_state;
	int start_time;
	int finish_time;
	int blink_time;
	char counter;
	bool button_state;

public:
	Menu();
	void restart();
	char get_guy_state();
	char get_timer(int index);
	char get_counter(int index);
	void set_button_state(bool state);
	void check_menu(bool game_state, bool victory, char flags);
};