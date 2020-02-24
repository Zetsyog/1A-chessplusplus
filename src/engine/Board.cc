#include "engine/Board.h"
#include "engine/piece/Pawn.h"
#include "engine/util/Position.h"
#include <iostream>

using namespace std;

Board::Board() : grid() {
	for (size_t i = 0; i < 8; i++) {
		this->grid[i][1] = new Pawn(WHITE, Position(i, 1));
		this->grid[i][6] = new Pawn(BLACK, Position(i, 7));
	}
}

void Board::print() {
	string space5 = string(5, ' ');
	cout << endl;
	cout << "     a     b     c     d     e     f     g     h   " << endl;
	cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
	for (int y(8 - 1); y >= 0; y--) {
		cout << y + 1 << " ";
		for (int x(0); x < 8; x++) {
			cout << "|";
			if (this->grid[x][y] != nullptr) {
				cout << "\u0020\u0020"; // U+0020 est un esapce utf-8 taille
										// police
				cout << this->grid[x][y]->get_name();
				cout << "\u0020"
					 << " ";
			} else {
				cout << space5; // 2 ascii spaces
			}
		}
		cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
		cout << endl;
	}
}
