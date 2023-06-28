#pragma once

#include "headers/cell.h"

class Field
{
	std::vector < Cell > cells;

public:
	Field();
	void generate();
	void flag_cell(int i_x, int i_y);
	void open_cell(int i_x, int i_y);
	int get_view(int i_x, int i_y);
};