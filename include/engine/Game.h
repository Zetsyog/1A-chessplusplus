#ifndef GAME_H
#define GAME_H

#include "engine/Board.h"
#include "engine/util/Command.h"

class Game {
  public:
	Game();
	bool is_running();
	void print();
	void play();

  private:
	Board board;
	bool running;

	bool execute_command(Command const &command);
};

#endif