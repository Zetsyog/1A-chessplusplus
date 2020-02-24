#include "engine/piece/Queen.h"
#include <cstdlib>

using namespace std;

Queen::Queen(Color color, Position position) : Piece(color, position) {
}

Queen::Queen(Color color) : Queen(color, Position(0, 0)) {
}

string Queen::get_name() const {
	if (this->get_color() == WHITE) {
		return "\u2655";
	}
	return "\u265B";
}

bool Queen::is_move_legal(Position const &pos, bool target_empty) {
	if (get_position().get_x() == pos.get_x() ||
		get_position().get_y() == pos.get_y()) {
		return true;
	}
	if (abs(pos.get_x() - get_position().get_x()) ==
		abs(pos.get_y() - get_position().get_y())) {
		return true;
	}
	return false;
}