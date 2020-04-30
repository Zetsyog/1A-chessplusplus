#include "piece/Rook.h"
#include <cstdlib>

using namespace std;

Rook::Rook(Color color, Position position) : Piece(color, position) {
}

Rook::Rook(Color color) : Rook(color, Position(0, 0)) {
}

string Rook::get_name() const {
	if (this->get_color() == BLACK) {
		return "\u265C";
	}
	return "\u2656";
}

bool Rook::is_move_legal(Position const &dest, Board *board,
						 bool target_empty) {

	if (get_position().get_x() == dest.get_x() ||
		get_position().get_y() == dest.get_y()) {
		if (board->is_straight_path_clear(get_position(), dest)) {
			return true;
		}
	}
	return false;
}