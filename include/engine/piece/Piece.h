#ifndef PIECE_H
#define PIECE_H

#include "engine/piece/Color.h"
#include "engine/util/Position.h"
#include <iostream>

using namespace std;

class Board;

class Piece {
  public:
	Piece(Color color, Position position);
	virtual ~Piece();
	Color get_color() const;
	Position get_position();
	void set_position(Position const &position);
	bool was_moved();
	virtual string get_name() const = 0;
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty) = 0;

  private:
	Color color;
	Position position;
	bool moved;
};

#include "engine/Board.h"

#endif