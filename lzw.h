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
/// Dictionary Maximum Size (when reached, the dictionary will be reset)
    const CodeType dms {std::numeric_limits<CodeType>::max()};
}

class LZW {
private:
    void reset_dictionary_decompress(vector<vector<char>> &dictionary);
    void reset_dictionary_compress(map<vector<char>, CodeType> &dictionary);
public:
    LZW();
    void compress(std::istream &is, std::ostream &os);
    void decompress(std::istream &is, std::ostream &os);
};

#endif //LAB1_LZW_CPP_H
