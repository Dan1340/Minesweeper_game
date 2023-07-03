#pragma once

#include "headers/cell.h"

class Field
{
	std::vector < Cell > cells;
	bool game_over;
	bool victory;
	char flags;

public:
	Field();
	void generate();
	void flag_cell(int i_x, int i_y);
	void open_cell(int i_x, int i_y);
	char get_view(int i_x, int i_y);
	void check_victory();
	bool get_game_over();
	bool get_victory();
	char get_flags();
};