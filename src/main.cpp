#include "./ZA256/ZA256.h"
#include "./functions.h"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << zygisau::ZA256::hash("") << endl;
	} else if (argc == 2) {
		if (hasEnding(argv[1], ".txt")) {
			string input = readFile(argv[1]);
			cout << zygisau::ZA256::hash(input) << endl;
		} else {
			cout << zygisau::ZA256::hash(argv[1]) << endl;
		}
	}
    return 0;
}