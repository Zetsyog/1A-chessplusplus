#ifndef PAWN_H
#define PAWN_H

#include "engine/piece/Piece.h"

class Pawn : public Piece {
  public:
	Pawn(Color color, Position position);
	Pawn(Color color);
	string get_name() const;
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty);
};

#endif