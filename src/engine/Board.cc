#include "engine/Board.h"
#include "engine/piece/Pawn.h"
#include "engine/util/Position.h"
#include <iostream>

Board::Board() {
	for (size_t i = 0; i < 0; i++) {
		this->grid[i][1] = new Pawn(WHITE, Position(i, 1));
	}
}

