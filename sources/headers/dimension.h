#pragma once

//	The size of the field
constexpr unsigned int CELL_SIZE = 64;
constexpr unsigned int FRAME_THICK = 32;

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