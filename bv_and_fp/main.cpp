#define _GLIBCXX_USE_CXX11_ABI 0 / 1
#include "bachelor.hpp"

int main() {
  string mant;
  string expo;
  cout << "Please enter the amount of bits you want to store for the exponent and the significand (x y):" << endl;
  cin >> expo >> mant ;
  if (expo == "" || mant == "") {
    cout << "Bitte schreiben Sie die Zahlen wie folgt auf 5 5 auf.\n";
    return 0;
  }
  start(expo,mant); 
  //string text = string("boolector code") + expo + string("_") + mant + string(".smt2 -dai|aigand|aigtocnf > code") + expo + string("_") + mant + string(".cnf");
  //const char* textc = text.c_str();
  //int status = system(textc);   
  
  return 0;
}
