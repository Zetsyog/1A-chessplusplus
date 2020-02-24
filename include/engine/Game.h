#ifndef GAME_H
#define GAME_H

#include "engine/Board.h"

class Game {
  public:
	Game();
	bool is_running();
	void print();
	void play();

  private:
	Board board;
};

#endif