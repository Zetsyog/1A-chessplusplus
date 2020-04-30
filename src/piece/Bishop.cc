#include "piece/Bishop.h"
#include <cstdlib>

using namespace std;

Bishop::Bishop(Color color, Position position) : Piece(color, position) {
}

Bishop::Bishop(Color color) : Bishop(color, Position(0, 0)) {
}

string Bishop::get_name() const {
	if (this->get_color() == BLACK) {
		return "\u265D";
	}
	return "\u2657";
}

bool Bishop::is_move_legal(Position const &dest, Board *board,
						   bool target_empty) {
	if (abs(dest.get_x() - get_position().get_x()) ==
		abs(dest.get_y() - get_position().get_y())) {
		return board->is_diag_path_clear(this->get_position(), dest);
	}
	return false;
}