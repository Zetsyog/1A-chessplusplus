#ifndef QUEEN_H
#define QUEEN_H

#include "piece/Bishop.h"
#include "piece/Piece.h"
#include "piece/Rook.h"

class Queen : public Rook, public Bishop {
  public:
	Queen(Color color, Position position);
	Queen(Color color);

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