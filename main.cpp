#include <iostream>
#include "lzw.h"

using namespace std;
int main(){
    string path = "/home/bersik/ClionProjects/Lab1/files/";
    LZW lzw;
    cout << "Start compression..." << endl;
    lzw.compress(path + "in.txt",path + "out.txt");
    cout << "Compression ended successfully!" << endl;
    cout << "Start decompression..." << endl;
    lzw.decompress(path + "out.txt",path + "out_new.txt");
    cout << "Deompression ended successfully!" << endl;
    return 0;
}