#include "engine/piece/Bishop.h"
#include <cstdlib>

using namespace std;

Bishop::Bishop(Color color, Position position) : Piece(color, position) {
}

Bishop::Bishop(Color color) : Bishop(color, Position(0, 0)) {
}

string Bishop::get_name() const {
	if (this->get_color() == WHITE) {
		return "\u2657";
	}
	return "\u265D";
}

bool Bishop::is_move_legal(Position const &dest, Board const &board,
						   bool target_empty) {
	if (abs(dest.get_x() - get_position().get_x()) ==
		abs(dest.get_y() - get_position().get_y())) {
		return true;
	}
	return false;
}