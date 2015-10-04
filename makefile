all:
		g++ -pg -std=c++11 -o main lzw.cpp lzw.h main.cpp

gprof:
		gprof main gmon.out -p > report.txt

