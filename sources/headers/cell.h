#pragma once

class Cell
{
	bool is_mine;
	bool is_flag;
	bool is_open;
	int mines_around;

public:
	Cell();
	void set_is_mine();
	void set_is_flag();
	void set_is_open();
	void add_mines_around();
	bool get_is_mine();
	bool get_is_flag();
	bool get_is_open();
	int get_mines_around();
	void restart();
};