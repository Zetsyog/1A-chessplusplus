#ifndef ROOK_H
#define ROOK_H

#include "engine/piece/Piece.h"

class Rook : public Piece {
  public:
	Rook(Color color, Position position);
	Rook(Color);
	string get_name() const;
	bool is_move_legal(Position const &dest, Board const &board,
					   bool target_empty);
};

#endif