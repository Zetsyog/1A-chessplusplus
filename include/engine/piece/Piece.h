#ifndef PIECE_H
#define PIECE_H

#include "engine/piece/Color.h"
#include "engine/util/Position.h"

class Piece {
  public:
	Piece(Color color, Position position);
	Color get_color();
	virtual char get_name() = 0;

  private:
	Color color;
};

#endif