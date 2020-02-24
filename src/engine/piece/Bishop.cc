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

bool Bishop::is_move_legal(Position const &pos, bool target_empty) {
	if (abs(pos.get_x() - get_position().get_x()) ==
		abs(pos.get_y() - get_position().get_y())) {
		return true;
	}
	return false;
}