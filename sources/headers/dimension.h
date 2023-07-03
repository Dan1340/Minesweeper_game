#pragma once

//	The size of the field
constexpr unsigned int CELL_SIZE = 64;
constexpr unsigned int FRAME_THICK = 32;
constexpr unsigned int FRAME_HEAD = 128;

//	Guy button coordinates
constexpr unsigned int GUY_X = 384;
constexpr unsigned int GUY_Y = 48;
constexpr unsigned char THINKING_GUY = 0;
constexpr unsigned char QUIZZICAL_GUY = 2;
constexpr unsigned char LOSER_GUY = 4;
constexpr unsigned char WINNER_GUY = 6;

//	The size of digits
constexpr unsigned int DIGIT_HEIGHT = 64;
constexpr unsigned int DIGIT_WIDTH = 32;
constexpr unsigned char EMPTY_SEGMENT = 10;

//	Timer coordinates
constexpr unsigned int TIMER_MIN_X = 621;
constexpr unsigned int TIMER_SEC_X = 703;
constexpr unsigned int TIMER_Y = 48;

//	Counter coordinates
constexpr unsigned int COUNTER_X = 65;
constexpr unsigned int COUNTER_Y = 48;

//	Number of columns and rows
constexpr unsigned char COLUMNS = 12;
constexpr unsigned char ROWS = 12;

//	Number of mines
constexpr unsigned char MINES = 15;

//	Texture coordinates
constexpr unsigned char VIEW_CLOSE = 9;
constexpr unsigned char VIEW_CLOSE_LOSE = 10;
constexpr unsigned char VIEW_FLAG_LOSE = 11;
constexpr unsigned char VIEW_FLAG = 12;
constexpr unsigned char VIEW_MINE = 13;
constexpr unsigned char VIEW_MINE_LOSE = 14;