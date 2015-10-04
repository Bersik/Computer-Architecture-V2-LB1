#include <iostream>
#include <fstream>
#include "lzw.h"

using namespace std;
int main(){
    string path = "/home/bersik/ClionProjects/Lab1/files/";

    LZW lzw;

    ifstream fin(path + "in.txt");
    ofstream fout(path + "out.txt");

    lzw.compress(fin,fout);
    fin.close();
    fout.close();

    ifstream fin2(path + "out.txt");
    ofstream fout2(path + "out_new.txt");
    lzw.decompress(fin2,fout2);

    fin2.close();
    fout2.close();

    return 0;
}