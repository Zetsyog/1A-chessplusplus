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

	cout << (next_team == WHITE ? "White" : "Black") << " team, your move."
		 << endl;

	while (!command.parse() || !this->execute_command(command)) {
		cerr << "Invalid command. Please try again." << endl;
	}

	next_team = next_team == WHITE ? BLACK : WHITE;
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

	return this->board.move(command.from, command.to);
}