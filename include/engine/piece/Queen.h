#ifndef QUEEN_H
#define QUEEN_H

#include "engine/piece/Piece.h"

class Queen : public Piece {
  public:
	Queen(Color color, Position position);
	Queen(Color color);
	string get_name() const;
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty);
};

#endif