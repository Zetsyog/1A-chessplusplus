#ifndef BISHOP_H
#define BISHOP_H

#include "piece/Piece.h"

class Bishop : public virtual Piece {
  public:
	Bishop(Color color, Position position);
	Bishop(Color color);
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