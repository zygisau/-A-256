#include "main.h"
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc == 2) { // read from arguments
        cout << argv[1] << " - " << hex << encodeInput(argv[1]) << endl;
    } else {
        cout << "No arguments were passed or failed to parse them. Exiting..." << endl;
    }
    return 0;
}