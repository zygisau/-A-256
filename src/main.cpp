#include "./ZA256/ZA256.h"
#include "./functions.h"

int main(int argc, char *argv[]) {
    if (argc == 3 && strcmp(argv[1], "-f") == 0) {
		string input = readFile(argv[2]);

		cout << zygisau::ZA256::hash(input) << endl;
    } else if (argc == 1) {
		cout << zygisau::ZA256::hash("") << endl;
	} else if (argc == 2) {
    		cout << zygisau::ZA256::hash(argv[1]) << endl;
	} else {
        cout << "Failed to parse arguments. Exiting..." << endl;
    }
    return 0;
}