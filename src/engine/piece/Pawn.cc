#include "engine/piece/Pawn.h"

Pawn::Pawn(Color color, Position position) : Piece(color, position) {
}

char Pawn::get_name() {
	if (this->get_color() == WHITE) {
		return '\u2659';
	}
	return '\u265F';
}