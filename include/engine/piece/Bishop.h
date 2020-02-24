#ifndef BISHOP_H
#define BISHOP_H

#include "engine/piece/Piece.h"

class Bishop : public Piece {
  public:
	Bishop(Color color, Position position);
	Bishop(Color color);
	string get_name() const;
	bool is_move_legal(Position const &dest, Board const &board,
					   bool target_empty);
};

#endif