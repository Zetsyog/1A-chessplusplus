#include "engine/util/Command.h"
#include <regex>

bool is_valid_input(string const &cmd) {
	regex mouvmtpattern("[a-h][1-8][a-h][1-8]");
	return cmd.length() == 4 && regex_match(cmd, mouvmtpattern);
}

Command::Command() : from(0, 0), to(0, 0) {
}

bool Command::parse() {
	cin >> str;

	if (str != "/quit" && !is_valid_input(str)) {
		return false;
	}

	from.set(str[0] - 'a', str[1] - '1');
	to.set(str[2] - 'a', str[3] - '1');

	return true;
}