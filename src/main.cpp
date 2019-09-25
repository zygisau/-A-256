#include "./ZA256/ZA256.h"

int main(int argc, char *argv[]) {
    if (argc == 2) { // read from arguments
        cout << argv[1] << " - " << zygisau::ZA256::hash(argv[1]) << endl;
    } else {
        cout << "No arguments were passed or failed to parse them. Exiting..." << endl;
    }
    return 0;
}