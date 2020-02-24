#include "engine/piece/Rook.h"
#include <cstdlib>

using namespace std;

Rook::Rook(Color color, Position position) : Piece(color, position) {
}

Rook::Rook(Color color) : Rook(color, Position(0, 0)) {
}

string Rook::get_name() const {
	if (this->get_color() == WHITE) {
		return "\u2656";
	}
	return "\u265C";
}

bool Rook::is_move_legal(Position const &dest, Board const &board,
						 bool target_empty) {
	return get_position().get_x() == dest.get_x() ||
		   get_position().get_y() == dest.get_y();
}