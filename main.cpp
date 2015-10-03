#include <iostream>
#include <fstream>
#include "lzw.h"

using namespace std;
int main(){
    string path = "/home/bersik/A/lab1/";
    LZW lzw;

    ifstream fin(path + "in.txt");
    ofstream fout(path + "out.txt");

    lzw.compress(fin,fout);
    /*LZW* lzw = new LZW();
    cout << lzw->CompressFile(f_in,f_out) << endl;*/
    fin.close();
    fout.close();

    ifstream fin2(path + "out.txt");
    ofstream fout2(path + "out_new.txt");
    lzw.decompress(fin2,fout2);
/*
    cout << lzw->DecompressFile(f_in,f_out)<<endl;

    */
    fin2.close();
    fout2.close();

    return 0;
}