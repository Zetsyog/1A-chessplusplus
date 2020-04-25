#include "piece/Knight.h"
#include <cstdlib>

using namespace std;

Knight::Knight(Color color, Position position) : Piece(color, position) {
}

Knight::Knight(Color color) : Knight(color, Position(0, 0)) {
}

string Knight::get_name() const {
	if (this->get_color() == BLACK) {
		return "\u2658";
	}
	return "\u265E";
}

bool Knight::is_move_legal(Position const &dest, Board *board,
						   bool target_empty) {
	if (abs(dest.get_x() - get_position().get_x()) == 1 &&
		abs(dest.get_y() - get_position().get_y()) == 2) {
		return true;
	}
	if (abs(dest.get_x() - get_position().get_x()) == 2 &&
		abs(dest.get_y() - get_position().get_y()) == 1) {
		return true;
	}
	return false;
}