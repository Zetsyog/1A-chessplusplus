#ifndef PIECE_H
#define PIECE_H

#include "engine/piece/Color.h"
#include "engine/util/Position.h"
#include <iostream>

using namespace std;

class Piece {
  public:
	Piece(Color color, Position position);
	Color get_color() const;
	virtual string get_name() const = 0;

  private:
	Color color;
	Position position;
};

#endif