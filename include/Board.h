#ifndef BOARD_H
#define BOARD_H

#include "piece/Piece.h"
#include "util/Position.h"
#include <vector>

using namespace std;

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
	bool move(Position const &from, Position const &to, bool move_effective);

	/**
	 * Remove the piece at a given position
	 * @param position of the piece to remove
	 * @param free if true
	 */
	void remove_piece(Position const &position, bool free);

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

	/**
	 * @param color of the wanted king
	 * @return the king of the given color
	 */
	Piece *get_king(Color color);

	/**
	 * Do the roque for a given player
	 * @param big_roque the direction of the roque
	 * @param color the player doing de roque
	 * @return true on success
	 */
	bool do_roque(bool big_roque, Color color);

	/**
	 * @param color the king color
	 * @return whether the king is in checked or not
	 */
	bool is_king_checked(Color color);

	/**
	 * @param color the wanted color of player
	 * @return the list of all pieces on board of the given player
	 */
	vector<Piece *> get_pieces(Color color);

	/**
	 * Updated logical position of all pieces on board with their current
	 * position on grid
	 */
	void update_position();

	/**
	 * Free memory of all pieces created
	 * called when the game end
	 */
	void dispose();

  private:
	Piece *grid[8][8];
	vector<Piece *> white_pieces;
	vector<Piece *> black_pieces;
	Piece *white_king;
	Piece *black_king;
};

#endif