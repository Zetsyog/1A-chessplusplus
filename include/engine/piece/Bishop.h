#ifndef BISHOP_H
#define BISHOP_H

#include "engine/piece/Piece.h"

class Bishop : public Piece {
  public:
	Bishop(Color color, Position position);
	Bishop(Color color);
	string get_name() const;
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty);
};

#endif