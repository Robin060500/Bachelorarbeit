#define _GLIBCXX_USE_CXX11_ABI 0 / 1
#include "bachelor.hpp"

int main() {
  string mant;
  string expo;
  cout << "Bitte nennen sind Sie erst die Anzahl an Bits, die Sie fuer den Exponenten und dann für die Mantisse verwenden wollen" << endl;
  cin >> expo >> mant ;
  cout << mant << " " << expo << endl;
  if (expo == "" || mant == "") {
    cout << "Bitte schreiben sie genau einen Typen hinter den Aufruf (Float16, "
            "Float32...!\n";
    return 0;
  }
  /*if (typ != "Float16" && typ != "Float32" && typ != "Float64" &&
      typ != "Bfloat16") {
    cout << "No valid datatyp!";
    return 0;
  }*/
  for (int i = 0; i < 1; i++) {

    start(expo,mant);    
    int status = system("z3 code.smt2 > out.txt");
  }
  return 0;
}
