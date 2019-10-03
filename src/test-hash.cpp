//
// Created by zygim on 2019-10-02.
//

#include "ZA256/ZA256.h"
#include <fstream>
#include <chrono>

class Timer { // paimta iš https://github.com/objprog/paskaitos2019/wiki/Laiko-matavimas
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	Timer() : start{std::chrono::high_resolution_clock::now()} {}
	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		return std::chrono::duration<double>
				(std::chrono::high_resolution_clock::now() - start).count();
	}
};

void testData(const string& fileName, int filesCount, ofstream& writeStream, bool wholeFile = false) {
	string data;
	std::ifstream fd;

	for (int i = 0; i < filesCount; i++) {
		data = "";
		fd.open(fileName + std::to_string(i) + ".txt");

		if (!fd.is_open()) {
			cout << "Nepavyko atidaryti failo: " << fileName << std::to_string(i) << ".txt" << endl;
			return;
		}

		if (!wholeFile) {
			fd >> data;
		} else {
			data.assign( (std::istreambuf_iterator<char>(fd) ),
						 (std::istreambuf_iterator<char>()    ) );
		}
		fd.close();
		writeStream << zygisau::ZA256::hash(data) << endl;
	}
	writeStream << endl;
}

double readKonstitucija() {
	Timer timer;
	double time = 0;
	string data;
	ifstream fd ("../test-data/konstitucija.txt");
	if (!fd.is_open()) {
		cout << "Nepavyko atidaryti failo: ../test-data/konstitucija.txt" << endl;
		return 0;
	}

	while (!fd.eof()) {
		data = "";
		std::getline(fd, data);

		timer.reset();
		zygisau::ZA256::hash(data);
		time += timer.elapsed();
	}
	return time;
}

int main() {
	std::ofstream fr("../test-data/test-data-results.txt");

	testData("../test-data/test-data-one-letter-", 5, fr);
	testData("../test-data/test-data-10K-", 3, fr, true);
	testData("../test-data/test-data-one-diff-", 10, fr);

	fr << "Konstitucija užhash'inta per " <<  readKonstitucija() << "s." << endl;

	fr.close();
	return 0;
}