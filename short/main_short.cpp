#define _GLIBCXX_USE_CXX11_ABI 0 / 1
#include "bachelor_short.h"

int main() {
    string typ = "Float32";
    ofstream text("zusammenfassung.txt");
    char buffer[200];
    //cout << "Bitte nennen sind einen Typen den sie addieren wollen:\n";
    //cin >> typ;
    
    if (typ == "") {
        cout << "Bitte schreiben sie genau einen Typen hinter den Aufruf (Float16, "
            "Float32...!\n";
        return 0;
    }
    if (typ != "Float16" && typ != "Float32" && typ != "Float64" &&
        typ != "Bfloat16") {
        cout << "No valid datatyp!";
        return 0;
    }
    for (int i = 0; i < 1000; i++) {

        start(typ, text);
        if (typ == "Float16") {
            int status = system("z3 t_f16.smt2 > out.txt");
        }
        else if (typ == "Float32") {
            int status = system("z3 t_f32.smt2 > out.txt");
        }
        else if (typ == "Float64") {
            int status = system("z3 t_f64.smt2 > out.txt");
        }
        else if (typ == "Bfloat16") {
            int status = system("z3 t_bf16.smt2 > out.txt");
        }
        fstream out("out.txt", ios::in);
        out.getline(buffer, 200);
        // if (status == -1){
        //	cout << "calling function failed" << endl;
        //}
        text << buffer << endl;
        out.close();
    }
    text.close();
    return 0;
}