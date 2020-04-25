#include "piece/Pawn.h"

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

		if ((get_color() == BLACK && get_position().get_y() == 3) ||
			(get_color() == WHITE && get_position().get_y() == 4)) {

			if (pos ==
					this->get_position() + Position(1, this->get_color() * 1) ||
				pos == this->get_position() +
						   Position(-1, this->get_color() * 1)) {
				Pawn *pawn = dynamic_cast<Pawn *>(board->get(
					Position(pos.get_x(), pos.get_y() - get_color())));

				if (pawn != nullptr) {
					if (pawn->has_double_step()) {
						return true;
					}
				}
			}
		}
		return false;
	}

	return pos == this->get_position() + Position(1, this->get_color() * 1) ||
		   pos == this->get_position() + Position(-1, this->get_color() * 1);
}

void Pawn::set_position(Position const &position) {
	if (abs(get_position().get_y() - position.get_y()) == 2) {
		double_step = true;
	}
	Piece::set_position(position);
}

bool Pawn::has_double_step() {
	return double_step;
}

void Pawn::move(Board &board, Position last_pos, bool target_empty) {
	// Case of en passant : diag movement but no piece has been taken
	if (last_pos.get_x() != get_position().get_x() && target_empty) {
		// we take the piece below
		board.remove_piece(get_position() + Position(0, -get_color()), true);
	}
	Piece::move(board, last_pos, target_empty);
}