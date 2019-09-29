//
// Created by zygisau on 2019-09-27.
//

#include "ZA256/ZA256.h"

string readFile(const string& fileName) {
	string str;

	ifstream fd(fileName);
	if (fd.fail()) {
		cout << "Failed to open the file. Exiting..." << endl;
	} else {
		str.assign( (std::istreambuf_iterator<char>(fd) ),
							 (std::istreambuf_iterator<char>()    ) );
	}

	return str;
}