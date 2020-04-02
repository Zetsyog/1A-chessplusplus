#include "engine/Board.h"
#include "engine/piece/Bishop.h"
#include "engine/piece/King.h"
#include "engine/piece/Knight.h"
#include "engine/piece/Pawn.h"
#include "engine/piece/Queen.h"
#include "engine/piece/Rook.h"
#include "engine/util/Position.h"
#include <cstdlib>
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

Piece *Board::get(Position const &position) const {
	if (position.get_x() < 0 || position.get_x() > 7)
		return nullptr;
	if (position.get_y() < 0 || position.get_y() > 7)
		return nullptr;

	return this->grid[position.get_x()][position.get_y()];
}

void Board::remove_piece(Position const &position) {
	if (get(position) != nullptr)
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

	if (this->get(to) != nullptr &&
		target->get_color() == this->get(to)->get_color()) {
		return false;
	}

	if (!target->is_move_legal(to, this, this->get(to) == nullptr)) {
		cerr << "illegal move" << endl;
		return false;
	}

	this->remove_piece(to);
	this->set(to, target);
	this->set(from, nullptr);

	return true;
}

bool Board::is_straight_path_clear(Position const &from,
								   Position const &to) const {
	if (from.get_x() != to.get_x() && from.get_y() != to.get_y()) {
		return false;
	}

	if (from.get_y() == to.get_y()) {
		int distance = abs(to.get_x() - from.get_x());
		int dir = (to.get_x() - from.get_x()) / distance;

		for (int i = 1; i < distance; i++) {
			if (this->get(from + Position(dir * i, 0)) != nullptr) {
				return false;
			}
		}
	} else {
		int distance = abs(to.get_y() - from.get_y());
		int dir = (to.get_y() - from.get_y()) / distance;

		for (int i = 1; i < distance; i++) {
			if (this->get(from + Position(dir * i, 0)) != nullptr) {
				return false;
			}
		}
	}
	return true;
}

bool Board::is_diag_path_clear(Position const &from, Position const &to) const {
	if (abs(to.get_x() - from.get_x()) != abs(to.get_y() - from.get_y())) {
		return false;
	}

	int distance = abs(to.get_x() - from.get_x());
	int x_dir = (to.get_x() - from.get_x()) / distance;
	int y_dir = (to.get_y() - from.get_y()) / distance;

	for (int i = 1; i < distance; i++) {
		if (this->get(from + Position(x_dir * i, y_dir * i)) != nullptr) {
			return false;
		}
	}

	return true;
}
