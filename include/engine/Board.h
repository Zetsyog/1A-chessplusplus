#ifndef BOARD_H
#define BOARD_H

#include "engine/piece/Piece.h"
#include "engine/util/Position.h"

class Board {
  public:
	Board();
	void print();
	bool move(Position const &from, Position const &to);
	void remove_piece(Position const &position);
	void set(Position const &position, Piece *piece);
	Piece *get(Position const &position);

  private:
	Piece *grid[8][8];
};

#endif