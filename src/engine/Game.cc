#include "engine/Game.h"
#include "engine/util/Command.h"
#include <iostream>

using namespace std;

Game::Game() : board(), running(true), next_team(WHITE) {
}

bool Game::is_running() {
	return this->running;
}

void Game::print() {
	this->board.print();
}

void Game::play() {
	Command command;

	if (board.is_king_checked(next_team)) {
		cout << "Echec aux " << (next_team == WHITE ? "blancs" : "noirs")
			 << endl;
	}

	cout << (next_team == WHITE ? "White" : "Black") << " team, your move."
		 << endl;

	bool end = false;
	while (!end) {
		if (command.parse()) {
			if (this->execute_command(command)) {
				end = true;
			}
		} else {
			cerr << "Invalid command. Please try again." << endl;
		}
	}

	if (!command.roque)
		cout << "Moved " << command.from << " to " << command.to << endl;

	next_team = next_team == WHITE ? BLACK : WHITE;

	if (is_check_mate(next_team)) {
		running = false;
		cout << "Winner is " << (next_team == WHITE ? "black " : "white ")
			 << "team." << endl;
	}
}

bool Game::is_check_mate(Color color) {
	vector<Piece *> pieces = board.get_pieces(color);

	if (!board.is_king_checked(color))
		return false;

	Board tmp_board;
	for (auto const &piece : pieces) {
		for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++) {
				tmp_board = Board(board);
				Position target_pos = Position(i, j);

				if (target_pos == Position(i, j))
					continue;

				tmp_board.update_position();
				if (piece->is_move_legal(target_pos, &tmp_board,
										 tmp_board.get(target_pos) ==
											 nullptr)) {
					if (tmp_board.move(piece->get_position(), target_pos,
									   false)) {
						if (!tmp_board.is_king_checked(color)) {
							return false;
						}
					}
				}
			}
		}
	}

	return true;
}

bool Game::execute_command(Command const &command) {
	if (command.str == "/quit") {
		this->running = false;
		return true;
	}

	if (command.roque != NONE) {
		return board.do_roque(command.roque == BIG_ROQUE, next_team);
	}

	if (this->board.get(command.from) != nullptr &&
		this->board.get(command.from)->get_color() != next_team) {
		return false;
	}

	Board tmp_board = Board(board);
	bool move_correct = tmp_board.move(command.from, command.to, false);

	if (move_correct) {
		if (tmp_board.is_king_checked(next_team)) {
			cerr << "king is still checked" << endl;
			return false;
		}
	} else {
		cerr << "illegal move" << endl;
	}
	return this->board.move(command.from, command.to, true);
}