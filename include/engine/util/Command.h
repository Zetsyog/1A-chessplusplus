#ifndef COMMAND_H
#define COMMAND_H

#include "engine/util/Position.h"
#include <iostream>

using namespace std;

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