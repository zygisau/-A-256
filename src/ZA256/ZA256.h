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
			return (unsigned int) character ^ mixer;
		}

		static void populateString(string &str) {
            string leftPart;
            string rightPart;
            unsigned char leftBound;
            unsigned long rightBound;
			if ((int)str.front() < 32) {
                leftBound = '\0';
                rightBound = 32 + (32 - (int)str.front());
			} else {
			    leftBound = str.front() - 32;
			    rightBound = 32;
			}

			for (unsigned char i = leftBound; i < str[0]; i++) {
                leftPart += i;
			}
			int i = 1;
            while (rightBound > i) {
            	rightPart += (char)(127 - i);
            	i++;
            }

			str.insert(0, leftPart);
            str += rightPart;
		}

		static void stringToIntArray(string &str, vector<unsigned long> &array) {
			populateString(str);
			mixUp(str, 0, (int)(str.front() + str.back()));
			array.reserve((unsigned long) ceil((double) str.length() / 2));
			unsigned long mixer = (unsigned long)str[0] ^ str.length();
			for (unsigned long i = 0; i < str.length() / 2; ++i) {
				array.push_back(
						convertAndShift(str[i], i, mixer) + convertAndShift(str[str.length() - 1 - i], i, mixer));
				mixer = array.back();
			}
			if (str.length() % 2 != 0) {
				array.push_back(convertAndShift(str[str.length() / 2 + 1], str.length() / 2 + 1, mixer));
			}
			array.shrink_to_fit();
		}

		static string convertAndResize(vector<unsigned long> &array) {
			string hash;
			std::stringstream stream;
			for (auto &integer: array) {
				stream << hex << integer; // or without hex
			}
			hash = stream.str();

			string payload = hash.substr(0, 64);
			string surplus = hash.substr(64);

			int i = 0;
			for (char& character : surplus) {
//				payload[i] = (char)((unsigned)payload[i] ^ (unsigned)character);
//				if (i < payload.length()) {
//					i++;
//				} else {
//					i = 0;
//				}
				std::for_each(payload.begin(), payload.end(), [character] (char &c) {
					c = (char)((unsigned)c ^ (unsigned)character);
				});
			}

			stream.str(std::string());
			for (auto &character: payload) {
				stream << hex << character;
			}
			hash = stream.str();
//			return hash.substr(hash.length() - 64, 64);
			return hash;
		}

		static void mixUp (string& str, unsigned long index, unsigned long sauce) {
			auto front = str.begin();
			auto back = str.end() - 1 - index;
			*front = (unsigned long)(*front) ^ sauce;
			*back = (unsigned long)*back ^ sauce;
			sauce += (unsigned long)*front ^ (unsigned long)*back;
			if (++index < str.length()) {
				mixUp(str, index, sauce);
			}
		}

		static void mixUp (vector<unsigned long>& array, unsigned long index, unsigned long sauce) {
			auto front = &array[index];
			auto back = array.end() - 1 - index;
			*front ^= sauce;
			*back ^= sauce;
			sauce += *front ^ *back;
			if (++index < array.size()) {
				mixUp(array, index, sauce);
			}
		}

	public:
		static string hash(string str) {
			vector<unsigned long> array;
			stringToIntArray(str, array);
			mixUp(array, 0, array.front() + array.back());
			return convertAndResize(array);
		}
	};
}


#endif //HASH_ZA256_H
