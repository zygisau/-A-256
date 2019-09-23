//
// Created by zygisau on 2019-09-23.
//

#ifndef HASH_ZA256_H
#define HASH_ZA256_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
using std::cin; using std::cout; using std::string; using std::endl;
using std::ifstream; using std::ofstream; using std::stringstream; using std::hex;
using std::ceil; using std::vector;

namespace zygisau {
	class ZA256 {
	private:
		explicit ZA256() = default;

		static unsigned long convertAndShift(char &character, unsigned long ind, unsigned long mixer) {
			return (ind % 2 == 0
					? (unsigned int) character << ind
					: (unsigned int) character >> ind) ^ mixer;
		}

		static void populateString(string &str) {
			unsigned long index = str.length();
			do {
				str += std::to_string(str.length() >> index);
			} while (str.length() < 64);
		}

		static void stringToIntArray(string &str, vector<unsigned long> &array) {
			populateString(str);
			array.reserve((unsigned long) ceil((double) str.length() / 2));
			unsigned long mixer = 0;
			for (unsigned long i = 0; i < str.length() / 2; ++i) {
				array.push_back(
						convertAndShift(str[i], i, mixer) | convertAndShift(str[str.length() - 1 - i], i, mixer));
				mixer = mixer ^ array.back();
			}
			if (str.length() % 2 != 0) {
				array.push_back(convertAndShift(str[str.length() / 2 + 1], str.length() / 2 + 1, mixer));
			}
			array.shrink_to_fit();
		}

		static string resizeAndConvert(vector<unsigned long> &array) {
			string hash;
			std::stringstream stream;
			for (auto &integer: array) {
				stream << hex << integer;
				hash += stream.str();
				if (hash.length() >= 64) {
					break;
				}
			}
			return hash.substr(hash.length() - 64, 64);
		}

	public:
		static string hash(string str) {
			vector<unsigned long> array;
			stringToIntArray(str, array);
			return resizeAndConvert(array);
		}
	};
}


#endif //HASH_ZA256_H
