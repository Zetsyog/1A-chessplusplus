#include "engine/Board.h"
#include "engine/piece/Bishop.h"
#include "engine/piece/King.h"
#include "engine/piece/Knight.h"
#include "engine/piece/Pawn.h"
#include "engine/piece/Queen.h"
#include "engine/piece/Rook.h"
#include "engine/util/Position.h"
#include <iostream>

using namespace std;

Board::Board() : grid() {
	for (size_t i = 0; i < 8; i++) {
		this->set(Position(i, 1), new Pawn(WHITE));
		this->set(Position(i, 6), new Pawn(BLACK));
	}
	this->set(Position(0, 0), new Rook(WHITE));
	this->set(Position(7, 0), new Rook(WHITE));
	this->set(Position(1, 0), new Knight(WHITE));
	this->set(Position(6, 0), new Knight(WHITE));
	this->set(Position(2, 0), new Bishop(WHITE));
	this->set(Position(5, 0), new Bishop(WHITE));
	this->set(Position(3, 0), new Queen(WHITE));
	this->set(Position(4, 0), new King(WHITE));

	this->set(Position(7, 7), new Rook(BLACK));
	this->set(Position(0, 7), new Rook(BLACK));
	this->set(Position(1, 7), new Knight(BLACK));
	this->set(Position(6, 7), new Knight(BLACK));
	this->set(Position(2, 7), new Bishop(BLACK));
	this->set(Position(5, 7), new Bishop(BLACK));
	this->set(Position(4, 7), new Queen(BLACK));
	this->set(Position(3, 7), new King(BLACK));
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

void Board::set(Position const &position, Piece *piece) {
	this->grid[position.get_x()][position.get_y()] = piece;
	if (piece != nullptr) {
		piece->set_position(position);
	}
}

Piece *Board::get(Position const &position) {
	return this->grid[position.get_x()][position.get_y()];
}

void Board::remove_piece(Position const &position) {
	delete get(position);
	set(position, nullptr);
}

bool Board::move(Position const &from, Position const &to) {
	Piece *target = this->get(from);

	cout << "Moving " << from << " to " << to << endl;

	if (target == nullptr) {
		cerr << "invalid target" << endl;
		return false;
	}

	if (!target->is_move_legal(to, this->get(to) == nullptr)) {
		cerr << "illegal move" << endl;
		return false;
	}

	this->remove_piece(to);
	this->set(to, target);
	this->set(from, nullptr);

	return true;
}
