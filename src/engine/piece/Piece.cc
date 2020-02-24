#include "engine/piece/Piece.h"
#include "engine/piece/Color.h"

Color Piece::get_color() {
	return this->color;
}

char Piece::get_name() {
	return this->name;
}