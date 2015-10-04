//
// Created by bersik on 03.10.15.
//

#ifndef LAB1_LZW_CPP_H
#define LAB1_LZW_CPP_H

#include <cstdint>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <limits>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

using CodeType = std::uint16_t;

namespace globals {
    const CodeType dms {std::numeric_limits<CodeType>::max()};
}

class LZW {
private:
public:
    LZW();
    void compress(string in, string out);
    void compress(istream &is, ostream &os);
    void decompress(string in, string out);
    void decompress(istream &is, ostream &os);
    void reset_dictionary_decompress(vector<vector<char>> &dictionary);
    void reset_dictionary_compress(map<vector<char>, CodeType> &dictionary);
    const long min_limit();
    const long max_limit();
};

#endif //LAB1_LZW_CPP_H
