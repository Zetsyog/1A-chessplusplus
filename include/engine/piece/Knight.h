#ifndef KNIGHT_H
#define KNIGHT_H

#include "engine/piece/Piece.h"

class Knight : public Piece {
  public:
	Knight(Color color, Position position);
	Knight(Color color);
	string get_name() const;
	bool is_move_legal(Position const &dest, Board const &board,
					   bool target_empty);
};

#endif