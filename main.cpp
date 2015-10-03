#include <iostream>
#include <fstream>
#include "lzw.h"

using namespace std;
int main(){

    LZW lzw;

    ifstream fin("/home/bersik/A/lab1/in.txt");
    ofstream fout("/home/bersik/A/lab1/out.txt");

    lzw.compress(fin,fout);
    /*LZW* lzw = new LZW();
    cout << lzw->CompressFile(f_in,f_out) << endl;*/
    fin.close();
    fout.close();

    ifstream fin2("/home/bersik/A/lab1/out.txt");
    ofstream fout2("/home/bersik/A/lab1/out_new.txt");
    lzw.decompress(fin2,fout2);
/*
    cout << lzw->DecompressFile(f_in,f_out)<<endl;

    */
    fin2.close();
    fout2.close();

    return 0;
}