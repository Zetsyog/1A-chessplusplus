#include "engine/util/Position.h"

Position::Position(unsigned int x, unsigned int y) : x(x), y(y) {
}

unsigned int Position::get_x() {
	return this->x;
}

unsigned int Position::get_y() {
	return this->y;
}