#include "./ZA256/ZA256.h"
#include "./functions.h"

int main(int argc, char *argv[]) {
    if (argc == 3) { // read from arguments
		string input = readFile(argv[2]);

		cout << argv[1] << " - " << zygisau::ZA256::hash(input) << endl;
    } else  if (argc == 2) {
		cout << argv[1] << " - " << zygisau::ZA256::hash(argv[1]) << endl;
	} else {
        cout << "No arguments were passed OR failed to parse them. Exiting..." << endl;
    }
    return 0;
}