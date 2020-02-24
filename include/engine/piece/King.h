#ifndef KING_H
#define KING_H

#include "engine/piece/Piece.h"

class King : public Piece {
  public:
	King(Color color, Position position);
	King(Color color);
	string get_name() const;
	bool is_move_legal(Position const &dest, Board const &board,
					   bool target_empty);
};

#endif