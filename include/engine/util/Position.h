#ifndef POSITION_H
#define POSITION_H

#include <iostream>

using namespace std;

/**
 * A cell position on the board
 */
class Position {
  public:
	Position(int x, int y);

	/**
	 * @return the x coordinate of position
	 */
	int get_x() const;

	/**
	 * @return the y coordinate of position
	 */
	int get_y() const;

	/**
	 * Set the x and y coordinates for this position
	 * @param x the new x coordinate
	 * @param y the new y coordiante
	 */
	void set(int x, int y);

	/**
	 * Set the coordinate of this position from another position
	 * @param position the new coordinates
	 */
	void set(Position const &position);

  private:
	int x, y;
};

const Position operator+(Position const &pos1, Position const &pos2);
const bool operator==(Position const &pos1, Position const &pos2);
const bool operator!=(Position const &pos1, Position const &pos2);
ostream &operator<<(ostream &out, Position const &pos);

#endif