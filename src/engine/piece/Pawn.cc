#include "engine/piece/Pawn.h"

Pawn::Pawn(Color color, Position position) : Piece(color, position) {
}

Pawn::Pawn(Color color) : Pawn(color, Position(0, 0)) {
}

string Pawn::get_name() const {
	if (this->get_color() == BLACK) {
		return "\u2659";
	}
	return "\u265F";
}

bool Pawn::is_move_legal(Position const &pos, Board *board, bool target_empty) {
	if (target_empty) {
		if (!this->was_moved()) {
			if (pos ==
				this->get_position() + Position(0, this->get_color() * 2)) {
				return board->is_straight_path_clear(get_position(), pos);
			}
		}
		if (pos == this->get_position() + Position(0, this->get_color() * 1)) {
			return board->is_straight_path_clear(get_position(), pos);
		}
		return false;
	}

	return pos == this->get_position() + Position(1, this->get_color() * 1) ||
		   pos == this->get_position() + Position(-1, this->get_color() * 1);
}