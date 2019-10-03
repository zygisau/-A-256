//
// Created by zygisau on 2019-09-27.
//

#include "ZA256/ZA256.h"

string readFile(const string& fileName) {
	string str;

	ifstream fd(fileName);
	if (fd.fail()) {
		// Failed to open the file. Hashing fileName as an input...
		str = fileName;
	} else {
		str.assign( (std::istreambuf_iterator<char>(fd) ),
							 (std::istreambuf_iterator<char>()    ) );
	}

	return str;
}

/* Big thanks to https://stackoverflow.com/a/874160 */
bool hasEnding (string const &fullString, string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
	} else {
		return false;
	}
}