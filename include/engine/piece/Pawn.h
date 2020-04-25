#ifndef PAWN_H
#define PAWN_H

#include "engine/piece/Piece.h"

class Pawn : public Piece {
  public:
	Pawn(Color color, Position position);
	Pawn(Color color);

	/**
	 * @see Piece::get_name()
	 */
	string get_name() const;

	/**
	 * @see Piece::is_move_legal()
	 */
	virtual bool is_move_legal(Position const &position, Board *board,
							   bool target_empty);

	/**
	 * @see Piece::set_position()
	 */
	virtual void set_position(Position const &position);

	/**
	 * Used for en passant
	 * @return whether this pawn did a double step
	 */
	bool has_double_step();

	/**
	 * @see Piece::move()
	 */
	virtual void move(Board &board, Position last_pos, bool target_empty);

  private:
	bool double_step = false;
};

#endif