#include "engine/piece/Piece.h"
#include "engine/piece/Color.h"

Piece::Piece(Color color, Position position)
	: color(color), position(position) {
}

Color Piece::get_color() const {
	return this->color;
}