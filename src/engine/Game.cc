#include "engine/Game.h"
#include "engine/util/Command.h"
#include <iostream>

using namespace std;

Game::Game() : running(true) {
}

bool Game::is_running() {
	return this->running;
}

void Game::print() {
	this->board.print();
}

void Game::play() {
	Command command;

	cout << "Your move." << endl;

	while (!command.parse() || !this->execute_command(command)) {
		cout << "Invalid command. Please try again." << endl;
	}
}

bool Game::execute_command(Command const &command) {
	if (command.str == "/quit") {
		this->running = false;
		return true;
	}

	return this->board.move(command.from, command.to);
}