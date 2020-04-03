#include "engine/util/Position.h"

Position::Position() : Position(0, 0) {
}

Position::Position(int x, int y) : x(x), y(y) {
}

int Position::get_x() const {
	return this->x;
}

int Position::get_y() const {
	return this->y;
}

void Position::set(int x, int y) {
	this->x = x;
	this->y = y;
}

void Position::set(Position const &position) {
	this->set(position.get_x(), position.get_y());
}

const Position operator+(Position const &pos1, Position const &pos2) {
	Position position(pos1.get_x() + pos2.get_x(), pos1.get_y() + pos2.get_y());
	return position;
}

const bool operator==(Position const &pos1, Position const &pos2) {
	return pos1.get_x() == pos2.get_x() && pos1.get_y() == pos2.get_y();
}

const bool operator!=(Position const &pos1, Position const &pos2) {
	return pos1.get_x() != pos2.get_x() || pos1.get_y() != pos2.get_y();
}

ostream &operator<<(ostream &out, Position const &pos) {
	out << "(" << pos.get_x() << " ; " << pos.get_y() << ")";
	return out;
}
