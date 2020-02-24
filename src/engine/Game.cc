#include "engine/Game.h"
#include <iostream>

using namespace std;

Game::Game() {
}

bool Game::is_running() {
	return false;
}

void Game::print() {
	this->board.print();
}

void Game::play() {
}