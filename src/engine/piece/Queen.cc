#include "engine/piece/Queen.h"
#include <cstdlib>

using namespace std;

Queen::Queen(Color color, Position position)
	: Piece(color, position), Rook(color, position), Bishop(color, position) {
}

Queen::Queen(Color color) : Queen(color, Position(0, 0)) {
}

string Queen::get_name() const {
	if (Bishop::get_color() == WHITE) {
		return "\u2655";
	}
	return "\u265B";
}

bool Queen::is_move_legal(Position const &dest, Board *board,
						  bool target_empty) {
	return Bishop::is_move_legal(dest, board, target_empty) ||
		   Rook::is_move_legal(dest, board, target_empty);
}