#include "engine/piece/Pawn.h"

Pawn::Pawn(Color color, Position position) : Piece(color, position) {
}

string Pawn::get_name() const {
	if (this->get_color() == WHITE) {
		return "\u2659";
	}
	return "\u265F";
}