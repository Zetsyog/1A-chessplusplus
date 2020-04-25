#ifndef COMMAND_H
#define COMMAND_H

#include "util/Position.h"
#include <iostream>

using namespace std;

#define NONE 0
#define BIG_ROQUE 1
#define LITTLE_ROQUE 2

/**
 * Represents a command input from the user
 */
class Command {
  public:
	Command();

	/**
	 * The string command that was parsed
	 */
	string str;

	/**
	 * true if the parsed command is a roque
	 */
	int roque;

	/**
	 * The positions once they have been parsed
	 */
	Position from, to;

	/**
	 * try to parse a command from standard input
	 * @return true if a valid command was found
	 */
	bool parse();

  private:
};

#endif