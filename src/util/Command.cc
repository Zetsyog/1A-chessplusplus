#include "util/Command.h"
#include <regex>

bool is_valid_input(string const &cmd) {
	regex mouvmtpattern("[a-h][1-8][a-h][1-8]");
	return cmd.length() == 4 && regex_match(cmd, mouvmtpattern);
}

bool is_valid_roque(string const &cmd) {
	regex mouvmtpattern("(O|o|0)-(O|o|0)");
	return regex_match(cmd, mouvmtpattern);
}

Command::Command() : roque(NONE), from(0, 0), to(0, 0) {
}

bool Command::parse() {
	do {
		cin >> str;
	} while (str.at(0) == '#');
	roque = NONE;

	if (is_valid_roque(str)) {
		if (str.at(0) == 'o') {
			roque = LITTLE_ROQUE;
		} else {
			roque = BIG_ROQUE;
		}
		return true;
	}

	if (str != "/quit" && !is_valid_input(str)) {
		return false;
	}

	from.set(str[0] - 'a', str[1] - '1');
	to.set(str[2] - 'a', str[3] - '1');

	return true;
}