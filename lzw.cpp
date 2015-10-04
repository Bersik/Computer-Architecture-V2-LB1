//
// Created by bersik on 03.10.15.
//

#include "lzw.h"


LZW::LZW(){}


std::vector<char> operator + (std::vector<char> vc, char c)
{
    vc.push_back(c);
    return vc;
}


const long int LZW::min_limit(){
    return std::numeric_limits<char>::min();
}


const long int LZW::max_limit(){
    return std::numeric_limits<char>::max();
}


void LZW::reset_dictionary_compress(std::map<std::vector<char>, CodeType> &dictionary){
    dictionary.clear();

    for (long int c = min_limit(); c <= max_limit(); ++c)
    {
        const CodeType dictionary_size = (const CodeType) dictionary.size();
        dictionary[{static_cast<char> (c)}] = dictionary_size;
    }
}

void LZW::compress(std::istream &is, std::ostream &os)
{
    std::map<std::vector<char>, CodeType> dictionary;
    reset_dictionary_compress(dictionary);
    std::vector<char> s; // String
    char c;

    while (is.get(c))
    {
        // dictionary's maximum size was reached
        if (dictionary.size() == globals::dms)
            reset_dictionary_compress(dictionary);

        s.push_back(c);

        if (dictionary.count(s) == 0)
        {
            const CodeType dictionary_size = (const CodeType) dictionary.size();

            dictionary[s] = dictionary_size;
            s.pop_back();
            os.write(reinterpret_cast<const char *> (&dictionary.at(s)), sizeof (CodeType));
            s = {c};
        }
    }

    if (!s.empty())
        os.write(reinterpret_cast<const char *> (&dictionary.at(s)), sizeof (CodeType));
}


void LZW::reset_dictionary_decompress(std::vector<std::vector<char>> &dictionary)
{
    dictionary.clear();
    dictionary.reserve(globals::dms);

    for (long int c = min_limit(); c <= max_limit(); ++c)
        dictionary.push_back({static_cast<char> (c)});
}

void LZW::decompress(std::istream &is, std::ostream &os)
{
    std::vector<std::vector<char>> dictionary;

    reset_dictionary_decompress(dictionary);

    std::vector<char> s; // String
    CodeType k; // Key

    while (is.read(reinterpret_cast<char *> (&k), sizeof (CodeType)))
    {
        // dictionary's maximum size was reached
        if (dictionary.size() == globals::dms)
            reset_dictionary_decompress(dictionary);

        if (k > dictionary.size())
            throw std::runtime_error("invalid compressed code");

        if (k == dictionary.size())
            dictionary.push_back(s + s.front());
        else
        if (!s.empty())
            dictionary.push_back(s + dictionary.at(k).front());

        os.write(&dictionary.at(k).front(), dictionary.at(k).size());
        s = dictionary.at(k);
    }

    if (!is.eof() || is.gcount() != 0)
        throw std::runtime_error("corrupted compressed file");
}
