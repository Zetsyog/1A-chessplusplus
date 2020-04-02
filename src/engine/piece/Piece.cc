#include "engine/piece/Piece.h"
#include "engine/piece/Color.h"

Piece::Piece(Color color, Position position)
	: color(color), position(position), moved(false) {
}

Position Piece::get_position() {
	return this->position;
}

void Piece::set_position(Position const &position) {
	this->position.set(position);
}

Color Piece::get_color() const {
	return this->color;
}

void Piece::move() {
	this->moved = true;
}

bool Piece::was_moved() {
	return this->moved;
}

Piece::~Piece() {
}
