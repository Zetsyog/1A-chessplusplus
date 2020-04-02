#ifndef GAME_H
#define GAME_H

#include "engine/Board.h"
#include "engine/util/Command.h"

class Game {
  public:
	Game();

	/**
	 * @return whether the game is running or not
	 */
	bool is_running();

	/**
	 * Print the current state of the game in standard output
	 */
	void print();
	void play();

  private:
	Board board;
	bool running;
	Color next_team;

	bool execute_command(Command const &command);
};

#endif