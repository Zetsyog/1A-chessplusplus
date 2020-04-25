#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece/Piece.h"

class Knight : public Piece {
  public:
	Knight(Color color, Position position);
	Knight(Color color);

	/**
	 * @see Piece::get_name()
	 */
	virtual string get_name() const;

	/**
	 * @see Piece::is_move_legal()
	 */
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty);
};

#endif