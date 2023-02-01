#define _GLIBCXX_USE_CXX11_ABI 0 / 1
#include "bachelor.hpp"

int main() {
  string mant;
  string expo;
  cout << "Bitte nennen sind Sie erst die Anzahl an Bits, die Sie fuer den Exponenten und dann für die Mantisse verwenden wollen" << endl;
  cin >> expo >> mant ;
  if (expo == "" || mant == "") {
    cout << "Bitte schreiben Sie die Zahlen wie folgt auf 5 5 auf.\n";
    return 0;
  }
  for (int i = 0; i < 1; i++) {

    start(expo,mant);    
    int status = system("z3 code.smt2 > out.txt");
  }
  return 0;
}

