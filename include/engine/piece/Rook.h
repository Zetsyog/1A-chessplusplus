#ifndef ROOK_H
#define ROOK_H

#include "engine/piece/Piece.h"

class Rook : public Piece {
  public:
	Rook(Color color, Position position);
	Rook(Color);
	string get_name() const;
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty);
};

#endif