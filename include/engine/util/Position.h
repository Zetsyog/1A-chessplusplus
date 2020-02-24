#ifndef POSITION_H
#define POSITION_H

#include <iostream>

using namespace std;
class Position {
  public:
	Position(int x, int y);
	int get_x() const;
	int get_y() const;
	void set(int x, int y);
	void set(Position const &position);

  private:
	int x, y;
};

const Position operator+(Position const &pos1, Position const &pos2);
const bool operator==(Position const &pos1, Position const &pos2);
const bool operator!=(Position const &pos1, Position const &pos2);
ostream &operator<<(ostream &out, Position const &pos);

#endif