#ifndef BOARD_H
#define BOARD_H

#include "engine/piece/Piece.h"
#include "engine/util/Position.h"

class Board {
  public:
	Board();

	/**
	 * Print this board to standard output
	 */
	void print();

	/**
	 * Move a piece from one position to another
	 * If there is a piece at the @a to position, and it is from a different
	 * color, and the move is legal, then the piece @a to position is destroyed
	 * @param from the current position of the piece
	 * @param to the targeted position for the piece
	 * @return true on success
	 */
	bool move(Position const &from, Position const &to);

	/**
	 * Remove the piece at a given position
	 * @param position of the piece to remove
	 */
	void remove_piece(Position const &position);

	/**
	 * Set a piece at a given position
	 * @param position the position to put the piece on
	 * @param piece a pointer to the piece. Do nothing if null
	 */
	void set(Position const &position, Piece *piece);
	/**
	 * Get the piece at a given position
	 * @param position the position of targeted piece
	 * @return pointer to the piece. Can be null
	 */
	Piece *get(Position const &position) const;

	/**
	 * Check if the straight line formed by the two positions is empty.
	 * The two position must form a straight line
	 * @param from first position of line
	 * @param to second position of line
	 * @return true if clear
	 */
	bool is_straight_path_clear(Position const &from, Position const &to) const;

	/**
	 * Check if the diagonal line formed by the two positions is empty.
	 * The two position must form a straight line
	 * @param from first position of diagonal line
	 * @param to second position of diagonal line
	 * @return true if clear
	 */
	bool is_diag_path_clear(Position const &from, Position const &to) const;

	Piece *get_king(Color color);

	bool do_roque(bool big_roque, Color color);

	/**
	 * @param color the king color
	 * @return whether the king is in checked or not
	 */
	bool is_king_checked(Color color);

  private:
	Piece *grid[8][8];
	Piece *white_king;
	Piece *black_king;
};

#endif