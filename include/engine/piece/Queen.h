#ifndef QUEEN_H
#define QUEEN_H

#include "engine/piece/Bishop.h"
#include "engine/piece/Piece.h"
#include "engine/piece/Rook.h"

class Queen : public Rook, public Bishop {
  public:
	Queen(Color color, Position position);
	Queen(Color color);

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