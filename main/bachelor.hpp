#ifndef _MY_CLASS_
#define _MY_CLASS_

//#define _GLIBCXX_USE_CXX11_ABI 0/1

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::fstream;
using namespace std;

// creating the smt-lib2 code for floating point addition
void start(std::string mant, std::string expo);

// generate a random number
string num_gen_str(string bin_num, int type);

// calculates the exponent
float calc_exp(string num, int type);

// calculates the fraction
float calc_frac(string num, int type);

// calculates the number
float print_num(string num, int type);

//changes floatto binary
char* bits(unsigned u);

//encodes a float to bin
char* encode(float f);

#endif
