#ifndef ROOK_H
#define ROOK_H

#include "engine/piece/Piece.h"

class Rook : public virtual Piece {
  public:
	Rook(Color color, Position position);
	Rook(Color);

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