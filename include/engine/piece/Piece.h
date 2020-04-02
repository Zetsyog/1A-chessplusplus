#ifndef PIECE_H
#define PIECE_H

#include "engine/piece/Color.h"
#include "engine/util/Position.h"
#include <iostream>

using namespace std;

class Board;

/**
 * @class Piece
 * @brief represents a piece on the board
 */
class Piece {
  public:
	Piece(Color color, Position position);

	/**
	 * @return this piece position
	 */
	Position get_position();
	/**
	 * @brief set this piece logical position
	 * Position must also be changed on the board to be effective
	 */
	void set_position(Position const &position);

	/**
	 * @return whether this piece was moved since the beginning of the game
	 */
	bool was_moved();

	/**
	 * mark this piece as moved
	 */
	void move();

	/**
	 * @return the piece color
	 * @see Color
	 */

	Color get_color() const;
	/**
	 * @return the piece name
	 */
	virtual string get_name() const = 0;

	/**
	 * Tell whether the targeted movement is allowed for that piece or not
	 *
	 * @param target the targeted position
	 * @param board the board where the piece is
	 * @param target_empty true if the target cell is empty
	 * @return true if movement to position is allowed
	 */
	virtual bool is_move_legal(Position const &target, Board *board,
							   bool target_empty) = 0;

	/**
	 * a destructor
	 */
	virtual ~Piece();

  private:
	Color color;
	Position position;
	bool moved;
};

#include "engine/Board.h"

#endif