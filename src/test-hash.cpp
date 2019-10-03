//
// Created by zygim on 2019-10-02.
//

#include "ZA256/ZA256.h"
#include <fstream>
#include <chrono>
#include <random>
#include <set>
#include <bitset>

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

void testData(const string &fileName, int filesCount, ofstream &writeStream, bool wholeFile = false) {
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
			data.assign((std::istreambuf_iterator<char>(fd)),
						(std::istreambuf_iterator<char>()));
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
	ifstream fd("../test-data/konstitucija.txt");
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

// https://stackoverflow.com/a/440147
string generateRandomString(size_t len) {
	char *s = new char[len];
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937_64 rng(seed);
	std::uniform_int_distribution<> random(1, 10);

	for (size_t i = 0; i < len; ++i) {
		int randomChar = random(rng) % (26 + 26 + 10);
		if (randomChar < 26)
			s[i] = (char) ('a' + randomChar);
		else if (randomChar < 26 + 26)
			s[i] = (char) ('A' + randomChar - 26);
		else
			s[i] = (char) ('0' + randomChar - 26 - 26);
	}
	s[len] = 0;
	return string(s);
}

int oneMilTest() {
	std::set<string> generatedInstances;
	int collisionCount = 0;
	string dataA;
	string dataB;

	for (int i = 0; i < 1000000; i++) {
		dataA = zygisau::ZA256::hash(generateRandomString(5));
		dataB = zygisau::ZA256::hash(generateRandomString(5));

		if (generatedInstances.find(dataB) != generatedInstances.end() ||
			generatedInstances.find(dataA) != generatedInstances.end()) {
			--i;
			continue;
		}

		if (dataA == dataB) {
			generatedInstances.insert(dataA);
			generatedInstances.insert(dataB);
			collisionCount++;
		}
	}
	return collisionCount;
}

string stringToBin(const string &str) {
	string binaryString;
	for (char character : str) {
		binaryString += std::bitset<8>(character).to_string();
	}
	return binaryString;
}

double bitCompare(const std::string &a, const std::string &b) {
	double ratio = 0;
	std::string binaryA = stringToBin(a);
	std::string binaryB = stringToBin(b);
	for (unsigned int i = 0; i < binaryA.length(); i++) {
		if (binaryA[i] != binaryB[i])
			ratio++;
	}
	return ratio / binaryA.length();

}

void differenceAnalyses(ofstream &fileStream) {
	std::set<string> generatedInstances;
	string dataA = zygisau::ZA256::hash(generateRandomString(4));
	string dataB = zygisau::ZA256::hash(generateRandomString(4));
	string hashA;
	string hashB;
	std::vector<double> ratios;

	for (int i = 0; i < 10000; i++) {
		hashA = zygisau::ZA256::hash(dataA + generateRandomString(1));
		hashB = zygisau::ZA256::hash(dataB + generateRandomString(1));

		if (generatedInstances.find(hashB) != generatedInstances.end() ||
			generatedInstances.find(hashA) != generatedInstances.end()) {
			--i;
			continue;
		}

		// Už pagalbines konvertavimo funkcijas ir apskaičiavimo idėją dėkingas https://github.com/gitguuddd (Mindaugui Kasiuliui)
		ratios.push_back(bitCompare(hashA, hashB) * 100);
		//

		generatedInstances.insert(hashA);
		generatedInstances.insert(hashB);
		dataA.substr(0, dataA.size() - 1);
		dataB.substr(0, dataB.size() - 1);
	}
	cout << "Minimalus skirtingumas: " << *std::min_element(ratios.begin(), ratios.end()) << "%" << endl;
	cout << "Maksimalus skirtingumas: " << *std::max_element(ratios.begin(), ratios.end()) << "%" << endl;
	cout << "Vidutinis skirtingumas: " << std::accumulate(ratios.begin(), ratios.end(), 0.0) / ratios.size() << "%" << endl;
}

int main() {
	std::ofstream fr("../test-data/test-data-results.txt");

	testData("../test-data/test-data-one-letter-", 5, fr);
	testData("../test-data/test-data-10K-", 3, fr, true);
	testData("../test-data/test-data-one-diff-", 10, fr, true);

	fr << "Konstitucija užhash'inta per " << readKonstitucija() << "s." << endl;

	fr << "Collision'ų skaičius (jei buvo): " << oneMilTest() << " / 1 000 000" << endl << endl;

	differenceAnalyses(fr);

	fr.close();
	return 0;
}