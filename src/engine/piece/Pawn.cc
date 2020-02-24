#include "engine/piece/Pawn.h"

Pawn::Pawn(Color color, Position position) : Piece(color, position) {
}

Pawn::Pawn(Color color) : Pawn(color, Position(0, 0)) {
}

string Pawn::get_name() const {
	if (this->get_color() == WHITE) {
		return "\u2659";
	}
	return "\u265F";
}

bool Pawn::is_move_legal(Position const &pos, bool target_empty) {
	cout << this->was_moved() << endl;
	if (target_empty) {
		if (!this->was_moved() &&
			pos == this->get_position() + Position(0, this->get_color() * 2)) {
			cout << "pawn was never moved" << endl;
			return true;
		} else {
			return pos ==
				   this->get_position() + Position(0, this->get_color() * 1);
		}
	}
	return pos == this->get_position() + Position(1, this->get_color() * 1) ||
		   pos == this->get_position() + Position(-1, this->get_color() * 1);
}