#ifndef KING_H
#define KING_H

#include "engine/piece/Piece.h"

class King : public Piece {
  public:
	King(Color color, Position position);
	King(Color color);
	/**
	 * @see Piece::get_name()
	 */
	string get_name() const;

	/**
	 * @see Piece::is_move_legal()
	 */
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty);
};

#endif