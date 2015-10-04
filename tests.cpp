//
// Created by marina on 04.10.15.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LZW_tests

#include <boost/test/unit_test.hpp>
#include "lzw.h"

BOOST_AUTO_TEST_CASE(testing_LZW_class) {
    LZW lzw;
    const long int minc = lzw.min_limit();
    const long int maxc = lzw.max_limit();
    string inp = "a";

    istringstream is(inp);
    ostringstream os;
    lzw.compress(is,os);
    BOOST_CHECK_EQUAL((int)os.str()[0],minc + inp[0]);

    is.str("");
    is.clear();
    is.str(os.str());
    os.str("");
    os.clear();
    lzw.decompress(is,os);
    BOOST_CHECK_EQUAL(inp,os.str());

    is.str("");
    is.clear();
    is.str("asf rsgf dsfg");
    os.str("");
    os.clear();
    BOOST_CHECK_THROW(lzw.decompress(is,os),std::runtime_error);

    std::map<std::vector<char>, CodeType> dictionary;
    lzw.reset_dictionary_compress(dictionary);
    BOOST_CHECK_EQUAL(dictionary.at({static_cast<char> (minc)}),0);
    BOOST_CHECK_EQUAL(dictionary.at({static_cast<char> (maxc)}),dictionary.size()-1);

    std::vector<std::vector<char>> dictionary2;
    lzw.reset_dictionary_decompress(dictionary2);
    vector<char> r1 = dictionary2.at(dictionary2.size()-1);
    vector<char> r2 = {static_cast<char> (maxc)};
    BOOST_CHECK_EQUAL_COLLECTIONS(r1.begin(),r1.end(),r2.begin(),r2.end());
    r1 = dictionary2.at(0);
    r2 = {static_cast<char> (minc)};
    BOOST_CHECK_EQUAL_COLLECTIONS(r1.begin(),r1.end(),r2.begin(),r2.end());

}
