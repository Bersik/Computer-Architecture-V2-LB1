//
// Created by marina on 04.10.15.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LZW_tests

#include <boost/test/unit_test.hpp>
#include "lzw.h"

BOOST_AUTO_TEST_CASE(testing_LZW_class) {
    LZW lzw;
    string inp = "a";
    istringstream is(inp);
    ostringstream os;
    lzw.compress(is,os);

    istringstream is2(os.str());
    ostringstream os2;
    lzw.decompress(is2,os2);
    BOOST_CHECK_EQUAL(inp,os2.str());
    cout << os2.str();

    std::map<std::vector<char>, CodeType> dictionary;
    lzw.reset_dictionary_compress(dictionary);
    //BOOST_CHECK_EQUAL(dictionary[],0);


}