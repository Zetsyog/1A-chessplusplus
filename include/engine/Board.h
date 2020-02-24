#ifndef BOARD_H
#define BOARD_H

#include "engine/piece/Piece.h"

class Board {
  public:
	Board();

  private:
	Piece *grid[8][8];
};

#endif