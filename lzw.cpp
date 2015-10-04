//
// Created by bersik on 03.10.15.
//

#include "lzw.h"


LZW::LZW(){}


vector<char> operator + (vector<char> vc, char c)
{
    vc.push_back(c);
    return vc;
}


const long int LZW::min_limit(){
    return numeric_limits<char>::min();
}


const long int LZW::max_limit(){
    return numeric_limits<char>::max();
}


void LZW::reset_dictionary_compress(map<vector<char>, CodeType> &dictionary){
    dictionary.clear();

    for (long int c = min_limit(); c <= max_limit(); ++c)
    {
        dictionary[{static_cast<char> (c)}] = (const CodeType) dictionary.size();;
    }
}

void LZW::compress(string in, string out) {
    ifstream fin(in);
    ofstream fout(out);
    compress(fin, fout);
    fin.close();
    fout.close();
}

void LZW::compress(istream &is, ostream &os)
{
    map<vector<char>, CodeType> dictionary;
    reset_dictionary_compress(dictionary);
    vector<char> s;
    char c;

    while (is.get(c))
    {
        if (dictionary.size() == globals::dms)
            reset_dictionary_compress(dictionary);

        s.push_back(c);

        if (dictionary.count(s) == 0)
        {
            dictionary[s] = (const CodeType) dictionary.size();
            s.pop_back();
            os.write(reinterpret_cast<const char *> (&dictionary.at(s)), sizeof (CodeType));
            s = {c};
        }
    }

    if (!s.empty())
        os.write(reinterpret_cast<const char *> (&dictionary.at(s)), sizeof (CodeType));
}


void LZW::reset_dictionary_decompress(vector<vector<char>> &dictionary)
{
    dictionary.clear();
    dictionary.reserve(globals::dms);

    for (long int c = min_limit(); c <= max_limit(); ++c)
        dictionary.push_back({static_cast<char> (c)});
}

void LZW::decompress(string in, string out) {
    ifstream fin(in);
    ofstream fout(out);
    decompress(fin, fout);
    fin.close();
    fout.close();
}

void LZW::decompress(istream &is, ostream &os)
{
    vector<vector<char>> dictionary;

    reset_dictionary_decompress(dictionary);

    vector<char> s;
    CodeType k;

    while (is.read(reinterpret_cast<char *> (&k), sizeof (CodeType)))
    {
        if (dictionary.size() == globals::dms)
            reset_dictionary_decompress(dictionary);

        if (k > dictionary.size())
            throw runtime_error("invalid compressed code");

        if (k == dictionary.size())
            dictionary.push_back(s + s.front());
        else if (!s.empty())
            dictionary.push_back(s + dictionary.at(k).front());

        os.write(&dictionary.at(k).front(), dictionary.at(k).size());
        s = dictionary.at(k);
    }

    if (!is.eof() || is.gcount() != 0)
        throw runtime_error("corrupted compressed file");
}
