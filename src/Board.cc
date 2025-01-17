#include "Board.h"
#include "piece/Bishop.h"
#include "piece/King.h"
#include "piece/Knight.h"
#include "piece/Pawn.h"
#include "piece/Queen.h"
#include "piece/Rook.h"
#include "util/Position.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

Board::Board() : grid() {
	this->black_king = new King(BLACK);
	this->white_king = new King(WHITE);

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
	this->set(Position(4, 0), white_king);

	this->set(Position(7, 7), new Rook(BLACK));
	this->set(Position(0, 7), new Rook(BLACK));
	this->set(Position(1, 7), new Knight(BLACK));
	this->set(Position(6, 7), new Knight(BLACK));
	this->set(Position(2, 7), new Bishop(BLACK));
	this->set(Position(5, 7), new Bishop(BLACK));
	this->set(Position(3, 7), new Queen(BLACK));
	this->set(Position(4, 7), black_king);

	Piece *tmp;
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			tmp = get(Position(i, j));
			if (tmp != nullptr) {
				if (tmp->get_color() == WHITE) {
					this->white_pieces.push_back(tmp);
				} else {
					this->black_pieces.push_back(tmp);
				}
			}
		}
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

void Board::remove_piece(Position const &position, bool mem_free) {
	if (get(position) != nullptr) {
		if (get(position)->get_color() == WHITE) {
			vector<Piece *>::iterator vec_position =
				find(white_pieces.begin(), white_pieces.end(), get(position));
			if (vec_position != white_pieces.end())
				white_pieces.erase(vec_position);
		} else {
			vector<Piece *>::iterator vec_position =
				find(black_pieces.begin(), black_pieces.end(), get(position));
			if (vec_position != black_pieces.end())
				black_pieces.erase(vec_position);
		}
		if (mem_free)
			delete get(position);
	}
	set(position, nullptr);
}

bool Board::move(Position const &from, Position const &to,
				 bool move_effective) {
	Piece *target = this->get(from);

	if (target == nullptr) {
		cerr << "invalid target" << endl;
		return false;
	}

	target->set_position(from);

	if (this->get(to) != nullptr &&
		target->get_color() == this->get(to)->get_color()) {
		return false;
	}

	bool target_empty = this->get(to) == nullptr;
	if (!target->is_move_legal(to, this, target_empty)) {
		return false;
	}

	this->remove_piece(to, move_effective);
	this->set(to, target);
	this->set(from, nullptr);

	if (move_effective)
		target->move(*this, from, target_empty);

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
			if (this->get(from + Position(0, dir * i)) != nullptr) {
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

Piece *Board::get_king(Color color) {
	return color == WHITE ? white_king : black_king;
}

bool Board::do_roque(bool big_roque, Color color) {
	Piece *tower;

	if (big_roque) {
		tower = get(Position(color == WHITE ? 0 : 7, color == WHITE ? 0 : 7));
	} else {
		tower = get(Position(color == WHITE ? 7 : 0, color == WHITE ? 0 : 7));
	}

	if (get_king(color)->was_moved())
		return false;

	if (tower == nullptr || tower->was_moved())
		return false;

	if (!this->is_straight_path_clear(tower->get_position(),
									  get_king(color)->get_position()))
		return false;

	int king_dir =
		tower->get_position().get_x() - get_king(color)->get_position().get_x();
	king_dir /= abs(king_dir);
	int tower_dir = -king_dir;

	set(get_king(color)->get_position(), nullptr);
	set(get_king(color)->get_position() + Position(2 * king_dir, 0),
		get_king(color));

	set(tower->get_position(), nullptr);
	set(get_king(color)->get_position() + Position(tower_dir, 0), tower);
	return true;
}

bool Board::is_king_checked(Color color) {
	Piece *king = get_king(color);

	Piece *tmp;
	Position pos = Position(0, 0);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			pos.set(i, j);
			tmp = get(pos);

			if (tmp == nullptr)
				continue;
			// ignore piece of same king color
			if (tmp->get_color() == color)
				continue;

			if (tmp->is_move_legal(king->get_position(), this, false)) {
				return true;
			}
		}
	}
	return false;
}

vector<Piece *> Board::get_pieces(Color color) {
	return color == BLACK ? black_pieces : white_pieces;
}

void Board::update_position() {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (grid[i][j] != nullptr)
				grid[i][j]->set_position(Position(i, j));
		}
	}
}

void Board::dispose() {
	for (auto const &piece : black_pieces) {
		delete piece;
	}
	for (auto const &piece : white_pieces) {
		delete piece;
	}
}