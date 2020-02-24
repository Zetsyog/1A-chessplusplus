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

bool Queen::is_move_legal(Position const &dest, Board const &board,
						  bool target_empty) {
	if (get_position().get_x() == dest.get_x() ||
		get_position().get_y() == dest.get_y()) {
		return true;
	}
	if (abs(dest.get_x() - get_position().get_x()) ==
		abs(dest.get_y() - get_position().get_y())) {
		return true;
	}
	return false;
}