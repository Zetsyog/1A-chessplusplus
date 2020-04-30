#include "piece/King.h"
#include <cstdlib>

using namespace std;

King::King(Color color, Position position) : Piece(color, position) {
}

King::King(Color color) : King(color, Position(0, 0)) {
}

string King::get_name() const {
	if (this->get_color() == BLACK) {
		return "\u265A";
	}
	return "\u2654";
}

bool King::is_move_legal(Position const &dest, Board *board,
						 bool target_empty) {
	if (abs(dest.get_x() - get_position().get_x()) <= 1 &&
		abs(dest.get_y() - get_position().get_y()) <= 1) {
		return true;
	}
	return false;
}