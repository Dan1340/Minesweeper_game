#pragma once

//	The size of the field
constexpr unsigned int CELL_SIZE = 64;
constexpr unsigned int FRAME_THICK = 32;
constexpr unsigned int FRAME_HEAD = 128;

//	Guy button coordinates
constexpr unsigned int GUY_X = 384;
constexpr unsigned int GUY_Y = 48;

//	Timer coordinates
constexpr unsigned int TIMER_X = 639;
constexpr unsigned int TIMER_Y = 48;

//	Counter coordinates
constexpr unsigned int COUNTER_X = 65;
constexpr unsigned int COUNTER_Y = 48;

//	Number of columns
constexpr unsigned char COLUMNS = 12;

//	Number of rows
constexpr unsigned char ROWS = 12;

//	Number of mines
constexpr unsigned int MINES = 15;

//	Texture coordinates
constexpr unsigned char VIEW_MINE = 9;
constexpr unsigned char VIEW_CLOSE = 10;
constexpr unsigned char VIEW_FLAG = 11;