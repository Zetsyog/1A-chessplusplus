#include "engine/piece/King.h"
#include <cstdlib>

using namespace std;

King::King(Color color, Position position) : Piece(color, position) {
}

King::King(Color color) : King(color, Position(0, 0)) {
}

string King::get_name() const {
	if (this->get_color() == WHITE) {
		return "\u2654";
	}
	return "\u265A";
}

bool King::is_move_legal(Position const &pos, bool target_empty) {
	if (abs(pos.get_x() - get_position().get_x()) <= 1 &&
		abs(pos.get_y() - get_position().get_y()) <= 1) {
		return true;
	}
	return false;
}