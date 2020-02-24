#ifndef COMMAND_H
#define COMMAND_H

#include "engine/util/Position.h"
#include <iostream>

using namespace std;

class Command {
  public:
	Command();
	string str;
	Position from, to;

	bool parse();

  private:
};

#endif