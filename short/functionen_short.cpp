#define _GLIBCXX_USE_CXX11_ABI 0 / 1
#include "bachelor_short.h"
#include <math.h>

void start(string typ, ofstream& text) {

	int expo_bit = 0;
	int mantis_bit = 0;
	int length = 0;
	int type = 0;
	fstream write;
	if (typ == "Float16") {
		type = 4;
		write.open("t_f16.smt2", ios::out);
		expo_bit = 5;
		mantis_bit = 10;
		length = 16 + 6;
	}
	else if (typ == "Float32") {
		type = 2;
		write.open("t_f32.smt2", ios::out);
		expo_bit = 8;
		mantis_bit = 23;
		length = 32 + 6;
	}
	else if (typ == "Float64") {
		type = 3;
		write.open("t_f64.smt2", ios::out);
		expo_bit = 11;
		mantis_bit = 52;
		length = 64 + 6;
	}
	else if (typ == "Bfloat16") {
		type = 1;
		write.open("t_bf16.smt2", ios::out);
		expo_bit = 8;
		mantis_bit = 7;
		length = 16 + 6;
	}
	if (!write) {
		cout << "Problems open the file";
		return;
	}

	write << ";;;Beginning of the Dokument of Robins bachelor thesis" << endl;
	write << endl;
	//header
	write << ";;;header" << endl;
	write << "(set-info :source |Robin Trueby Bachelorthesis|)" << endl;
	write << "(set-option :produce-models true)" << endl;
	write << "(set-logic QF_BV)" << endl;
	
	write << endl;
	//set the variables
	write << ";;;set the variables" << endl;
	write << "(declare-fun x () (_ BitVec " << length << " ))" << endl;
	write << "(declare-fun y () (_ BitVec " << length << " ))" << endl;
	write << "(declare-fun x_sign () (_ BitVec 1))" << endl;
	write << "(declare-fun y_sign () (_ BitVec 1))" << endl;
	write << "(declare-fun x_expo () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun y_expo () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun x_mant () (_ BitVec " << mantis_bit+7 << " ))" << endl;
	write << "(declare-fun y_mant () (_ BitVec " << mantis_bit+7 << " ))" << endl;
	write << "(declare-fun x_man () (_ BitVec " << mantis_bit + 6 << " ))" << endl;
	write << "(declare-fun y_man () (_ BitVec " << mantis_bit + 6 << " ))" << endl;
	write << "(declare-fun z () (_ BitVec " << length-6 << " ))" << endl;
	write << "(declare-fun z_short () (_ BitVec " << length - 7 << " ))" << endl;
	write << "(declare-fun z_sign () (_ BitVec 1))" << endl;
	write << "(declare-fun z_expo () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun z_expo2 () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun z_expo_final () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun z_mant_final () (_ BitVec " << mantis_bit << " ))" << endl;
	write << "(declare-fun z_mant () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun mant () (_ BitVec " << mantis_bit + 7 << " ))" << endl;
	write << "(declare-fun mant_up () (_ BitVec " << mantis_bit + 7 << " ))" << endl;
	write << "(declare-fun mant_short () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun other_mant () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun z_mant_over () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun z_mant_good () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun z_mant_good2 () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun expo_diff () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun expo_diff_2 () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun expo_diff_long () (_ BitVec " << mantis_bit + 7 << " ))" << endl;
	write << "(declare-fun g () (_ BitVec 1))" << endl;
	write << "(declare-fun r () (_ BitVec 1))" << endl;
	write << "(declare-fun s () (_ BitVec 1))" << endl;
	write << "(declare-fun lsb () (_ BitVec 1))" << endl;
	write << "(declare-fun g2 () (_ BitVec 1))" << endl;
	write << "(declare-fun r2 () (_ BitVec 1))" << endl;
	write << "(declare-fun s2 () (_ BitVec 1))" << endl;
	write << "(declare-fun lsb2 () (_ BitVec 1))" << endl;
	write << "(declare-fun over1 () (_ BitVec 1))" << endl;
	write << "(declare-fun over2 () (_ BitVec 1))" << endl;
	write << "(declare-fun over3 () (_ BitVec 1))" << endl;
	write << "(declare-fun over4 () (_ BitVec 1))" << endl;
	write << "(declare-fun over5 () (_ BitVec 1))" << endl;
	write << "(declare-fun over7 () (_ BitVec 1))" << endl;
	write << "(declare-fun over8 () (_ BitVec 1))" << endl;
	write << "(declare-fun overflow1 () (_ BitVec 1))" << endl;
	write << "(declare-fun overflow2 () (_ BitVec 1))" << endl;
	write << "(declare-fun underflow1 () (_ BitVec 1))" << endl;
	write << "(declare-fun inf () (_ BitVec 1))" << endl;
	write << "(declare-fun inf1 () (_ BitVec 1))" << endl;
	write << "(declare-fun inf2 () (_ BitVec 1))" << endl;
	write << "(declare-fun nan () (_ BitVec 1))" << endl;
	write << "(declare-fun nan1 () (_ BitVec 1))" << endl;
	write << "(declare-fun nan2 () (_ BitVec 1))" << endl;
	write << "(declare-fun den () (_ BitVec 1))" << endl;
	write << "(declare-fun denormaly () (_ BitVec 1))" << endl;
	write << "(declare-fun denormalx () (_ BitVec 1))" << endl;
	write << "(declare-fun m1 () (_ BitVec 1))" << endl;
	write << "(declare-fun stop () (_ BitVec 1))" << endl;
	write << "(declare-fun none () (_ BitVec 1))" << endl;

	for (int i = 2; i <= mantis_bit + 3; i++) {
		write << "(declare-fun m"<<i<<"() (_ BitVec 1))" << endl;
		write << "(declare-fun z_mant_" << i << " () (_ BitVec " <<mantis_bit + 4<< "))" << endl;
		write << "(declare-fun z_expo_" << i << " () (_ BitVec " << expo_bit << "))" << endl;
	}
	write << endl;
	//example 
	write << ";;;example" << endl;
	string bin_num1;
	bin_num1 = num_gen_str(bin_num1, length - 6);
	float num1 = print_num(bin_num1, 2);
	//text << bin_num1 << "\t";
	string bin_num2;
	bin_num2 = num_gen_str(bin_num2, length - 6);
	float num2 = print_num(bin_num2, 2);
	//text << bin_num2 << "\t";
	write << ";;;(assert (= x #b" << bin_num1 << "))" << endl;
	write << ";;;(assert (= y #b" << bin_num2 << "))" << endl;

	write << endl;
	//extract sign mantissa expo
	write << ";;;extract sign mantissa expo" << endl;
	write << "(assert (= x_sign ((_ extract " << length - 1 << " " << length - 1 << ") x)))" << endl;
	write << "(assert (= y_sign ((_ extract " << length - 1 << " " << length - 1 << ") y)))" << endl;
	write << "(assert (= x_expo ((_ extract " << length - 2 << " " << length - 1 - expo_bit << ") x)))" << endl;
	write << "(assert (= y_expo ((_ extract " << length - 2 << " " << length - 1 - expo_bit << ") y)))" << endl;
	write << "(assert (= x_man ((_ extract " << mantis_bit + 5 << " 0) x)))" << endl;
	write << "(assert (= y_man ((_ extract " << mantis_bit + 5 << " 0) y)))" << endl;
	
	write << endl;
	//check vor nan and inf
	write << ";;;check for nan and inf" << endl;
	string n0_str = "#b";
	for (int n = 0; n < expo_bit; n++) {
		n0_str = n0_str + "1";
	}
	write << "(assert (ite (bvuge x_expo " << n0_str << ") (ite (bvuge x_man (_ bv1 " << mantis_bit + 6 << "))";
	write << "(= nan1 #b1) (and (= inf1 #b1) (= nan1 #b0))) (and (= nan1 #b0) (= inf1 #b0))))" << endl;

	write << "(assert (ite (bvuge y_expo " << n0_str << ") (ite (bvuge y_man (_ bv1 " << mantis_bit + 6 << "))";
	write << "(= nan2 #b1) (and (= inf2 #b1) (= nan2 #b0)))	(and (= nan2 #b0) (= inf2 #b0))))" << endl;

	write << "(assert (ite (or (= inf1 #b1) (= inf2 #b1)) (= inf #b1) (= inf #b0)))" << endl;
	write << "(assert (ite (or (= nan1 #b1) (= nan2 #b1)) (= nan #b1) (= nan #b0)))" << endl;

	write << endl;
	//add hidden bit/ check for denormal
	write << ";;;add hidden bit/ check for denormal" << endl;
	write << "(assert (ite (bvuge (_ bv0 " << expo_bit << ") x_expo) (and (= x_mant (concat #b0 x_man))";
	write << "(= denormalx #b1)) (and (= x_mant ( concat #b1 x_man)) (= denormalx #b0))))" << endl;
	write << "(assert (ite (bvuge (_ bv0 " << expo_bit << ") y_expo) (and (= y_mant (concat #b0 y_man))";
	write << "(= denormaly #b1)) (and (= y_mant ( concat #b1 y_man)) (= denormaly #b0))))" << endl;

	write << endl;
	//compare expo
	write << ";;;compare expo" << endl;
	write << "(assert (ite (bvuge x_expo y_expo) (= z_expo x_expo) (= z_expo y_expo)))" << endl;
	write << "(assert (ite (bvuge x_expo y_expo) (= expo_diff (bvsub x_expo y_expo)) (= expo_diff (bvsub y_expo x_expo))))" << endl;
	write << "(assert (ite (xor (= denormalx #b1) (= denormaly #b1)) (= expo_diff_2 (bvsub expo_diff (_ bv1 " << expo_bit << ")))";
	write << "(= expo_diff_2 expo_diff)))" << endl;
	string expo_diff = "#b";
	for (int m = mantis_bit + 7 - expo_bit; m > 0; m--) {
		expo_diff = expo_diff + "0";
	}
	write << "(assert (= expo_diff_long (concat " << expo_diff << " expo_diff_2)))" << endl;

	write << endl;
	//shift the smaller mantissa
	write << ";;;shift the smaller mantissa" << endl;
	write << "(assert (ite (bvuge x_expo y_expo) (= mant (bvlshr y_mant expo_diff_long)) (= mant (bvlshr x_mant expo_diff_long))))" << endl;
	write << "(assert (= lsb2 ((_ extract 3 3) mant)))" << endl;
	write << "(assert (= g2 ((_ extract 2 2) mant)))" << endl;
	write << "(assert (= r2 ((_ extract 1 1) mant)))" << endl;
	write << "(assert (= s2 ((_ extract 0 0) mant)))" << endl;
	string n1_str = "#b";
	for (int n = 0; n <= mantis_bit; n++) {
		n1_str = n1_str + "0";
	}
	n1_str = n1_str + "001000";
	write << "(assert (ite (and (= lsb2 #b0) (or (or (= g2 #b1) (= r2 #b1)) (= s2 #b1)))";
	write << "(= mant_up (bvadd mant " << n1_str << ")) (= mant_up mant)))" << endl;


	write << endl;

	//shorten mant 3 bits
	write << ";;;shorten the mant by 3 bits" << endl;
	write << "(assert (ite (bvuge x_expo y_expo) (= other_mant ((_ extract " << mantis_bit + 6 << " 3)";
	write << " x_mant)) (= other_mant ((_ extract " << mantis_bit + 6 << " 3) y_mant))))" << endl;
	write << "(assert (= mant_short ((_ extract " << mantis_bit + 6 << " 3) mant_up)))" << endl;

	write << endl;
	//decide add or sub
	write << ";;;decide add or sub" << endl;
	write << "(assert(ite (= x_sign y_sign) (= z_mant (bvadd other_mant mant_short)) (= z_mant (bvsub other_mant mant_short))))" << endl;

	write << endl;
	string n2_str = "#b";
	for (int n = 0; n < mantis_bit; n++) {
		n2_str = n2_str + "0";
	}
	n2_str = n2_str + "1000";

	write << endl;
	//care denormal numbers
	write << ";;;care denormal numbers" << endl;
	write << "(assert (= den ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant)))" << endl;
	write << "(assert (ite (and (= den #b1) (and (= denormalx #b1) (= denormaly #b1))) (= z_expo2 (bvadd z_expo (_ bv1 " << expo_bit;
	write << "))) (= z_expo2 z_expo)))" << endl;

	write << endl;
	//check for overflow
	write << ";;;check for overflow" << endl;
	write << "(assert (= over1 ((_ extract " << mantis_bit + 2 << " " << mantis_bit + 2 << ") other_mant)))" << endl;
	write << "(assert (= over2 ((_ extract " << mantis_bit + 2 << " " << mantis_bit + 2 << ") mant_short)))" << endl;
	write << "(assert (= over3 ((_ extract " << mantis_bit + 2 << " " << mantis_bit + 2 << ") z_mant)))" << endl;
	write << "(assert (= over4 ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") mant_short)))" << endl;
	write << "(assert (= over5 ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") other_mant)))" << endl;
	write << "(assert (ite (and (or (or (and (= over1 #b1) (= over2 #b1)) (and (= over4 #b1) (= over5 #b1))) ";
	write << "(and (xor (= over1 #b1) (= over2 #b1)) (= over3 #b0))) (= x_sign y_sign)) (= overflow1 #b1) (= overflow1 #b0)))" << endl;
	write << "(assert (ite (and (= overflow1 #b1) (and (= denormalx #b0) (= denormaly #b0))) (= z_mant_over (bvlshr z_mant (_ bv1 " << mantis_bit + 4 << "))) (= z_mant_over z_mant)))" << endl;
	string n3_str = "#b1";
	for (int n = 0; n < mantis_bit + 3; n++) {
		n3_str = n3_str + "0";
	}
	write << "(assert (ite (and (= overflow1 #b1) (and (= denormalx #b0) (= denormaly #b0))) (= z_mant_good (bvadd z_mant_over " << n3_str << ")) (= z_mant_good z_mant_over)))" << endl;
	write << "(assert (ite (and (= overflow1 #b1) (and (= denormalx #b0) (= denormaly #b0))) (= z_expo_final (bvadd z_expo2 (_ bv1 " << expo_bit << "))) (= z_expo_final z_expo2)))" << endl;


	write << endl;
	//expo overflow
	write << ";;;expo overflow" << endl;
	write << "(assert (= over7 ((_ extract " << expo_bit - 1 << " " << expo_bit - 1 << ") z_expo2)))" << endl;
	write << "(assert (= over8 ((_ extract " << expo_bit - 1 << " " << expo_bit - 1 << ") z_expo_final)))" << endl;
	write << "(assert (ite (and (= over7 #b1) (= over8 #b0)) (= overflow2 #b1) (= overflow2 #b0)))" << endl;

	write << endl;
	//mant/ expo underflow (schleife ausgeschrieben)
	write << ";;;mant/ expo underflow (schleife ausgeschrieben" << endl;
	write << "(assert (= m1 ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant_good)))" << endl;
	write << "(assert (ite (and (= m1 #b0) (and (= denormalx #b0) (= denormaly #b0))) (= z_mant_2 (bvshl z_mant_good (_ bv1 " << mantis_bit + 4 << "))) (= z_mant_2 z_mant_good)))" << endl;
	write << "(assert (ite (and (= m1 #b0) (and (= denormalx #b0) (= denormaly #b0))) (= z_expo_2 (bvsub z_expo_final (_ bv1 " << expo_bit << "))) (= z_expo_2 z_expo_final)))" << endl;

	for (int m = 2; m <= mantis_bit + 2; m++) {
		write << "(assert (= m" << m << " ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant_" << m << ")))" << endl;
		write << "(assert (ite (and (= m" << m << " #b0) (and (= denormalx #b0) (= denormaly #b0))) (= z_mant_" << m + 1 << " (bvshl z_mant_" << m << " (_ bv1 " << mantis_bit + 4;
		write << "))) (= z_mant_" << m + 1 << " z_mant_" << m << ")))" << endl;
		write << "(assert (ite (and (= m" << m << " #b0) (and (= denormalx #b0) (= denormaly #b0))) (= z_expo_" << m + 1 << "(bvsub z_expo_" << m << " (_ bv1 " << expo_bit;
		write << "))) (= z_expo_" << m + 1 << " z_expo_" << m << ")))" << endl;
	}
	write << "(assert (= m" << mantis_bit + 3 << " ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (ite (and (= m" << mantis_bit + 3 << " #b0) (and (= denormalx #b0) (= denormaly #b0))) (= underflow1 #b1) (= underflow1 #b0)))" << endl;

	write << endl;
	//round
	write << ";;;round" << endl;
	write << "(assert (= lsb ((_ extract 3 3) z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= g ((_ extract 2 2) z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= r ((_ extract 1 1) z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= s ((_ extract 0 0) z_mant_" << mantis_bit + 3 << ")))" << endl;

	write << "(assert (ite (or (and (= g #b1) (or (= r #b1) (= s #b1))) (and (= g #b1) (= lsb #b1)))";
	write << "(= z_mant_good2 (bvadd z_mant_" << mantis_bit + 3 << " " << n2_str << " )) (= z_mant_good2 z_mant_" << mantis_bit + 3 << ")))" << endl;

	write << endl;
	//decide the sign
	write << ";;;decide the sign" << endl;
	write << "(assert (ite (bvuge x_expo y_expo) (= z_sign x_sign) (= z_sign y_sign)))" << endl;

	write << endl;
	//put all together
	write << ";;;put all together" << endl;
	string n4_str = "#b0";
	string n5_str = "#b";
	string n6_str = "#b1";
	for (int m = 0; m < length - 8; m++) {
		n4_str = n4_str + "0";
		if (m < expo_bit) {
			n5_str = n5_str + "1";
			n6_str = n6_str + "1";
		}
		else {
			n5_str = n5_str + "0";
			n6_str = n6_str + "0";
		}
	}
	n5_str = n5_str + "0";
	write << "(assert (= z_mant_final ((_ extract " << mantis_bit + 2 << " " << "3" << " ) z_mant_good2)))" << endl;

	write << "(assert (ite (= nan #b0) (ite (= inf #b0) (ite (= overflow2 #b0) (ite (= underflow1 #b0)";
	write << "(= z_short (concat z_expo_" << mantis_bit + 3 << " z_mant_final))";
	write << "(= z_short (_ bv0 " << length - 7 << ")))";
	write << "(= z_short " << n5_str << "))";
	write << "(= z_short " << n5_str << "))";
	write << "(= z_short " << n6_str << ")))" << endl;

	write << "(assert (ite (bvuge x_expo y_expo) (= z (concat x_sign z_short)) (= z (concat y_sign z_short))))" << endl;	

	write << endl;
	//finish
	write << ";;;finish" << endl;
	float num3 = num1 + num2;
	char* num3_str;
	num3_str = encode(num3);
	text << num3_str << endl;
	write << "(assert (= z #b" << num3_str<< "))" << endl;
	write << "(check-sat)" << endl;
	write << "(get-model)" << endl;
	write << "(exit)" << endl;


	write.close();
}
string num_gen_str(string bin_num, int type) {
	int length_str = type;
	bool good = false;
	bool yesorno = false;
	for (int i = 0; i < length_str ; i++) {
		int num = 0;
		num = (rand() % 100);
		if (num >= 50) {
			
			yesorno = true;
		}
		else {
			yesorno = false;
		}
		if (yesorno) {
			bin_num = bin_num + "1";
		}
		else {
			bin_num = bin_num + "0";
		}
	}
	bin_num = bin_num + "000000";
	return bin_num;
}

float calc_exp(string num, int type) {
	int num_exp = 0;
	float exp_bias = 0;
	if (type == 0) {
		num_exp = 4;
		exp_bias = 7;
	}
	else if (type == 1) {
		num_exp = 8;
		exp_bias = 127;
	}
	else if (type == 2) {
		num_exp = 8;
		exp_bias = 127;
	}
	else if (type == 3) {
		num_exp = 11;
		exp_bias = 1023;
	}
	float real_exp = 0;
	int r = 0;
	int j = 0;
	for (int i = num_exp; i > 0; i--) {
		r = (int(num[i])%48) * pow(2, j);
		real_exp = real_exp + r;
		j++;
	}
	if (real_exp == 0) {
		real_exp = 1;
	}
	real_exp = real_exp - exp_bias;
	return real_exp;
}

float calc_frac(string num, int type) {
	float komma = 1.0;
	float p = 0.0;
	int j = 1;
	int num_exp = 0;
	int num_frac = 0;
	if (type == 0) {
		num_exp = 4;
		num_frac = 7;
	}
	else if (type == 1) {
		num_exp = 8;
		num_frac = 15;
	}
	else if (type == 2) {
		num_exp = 8;
		num_frac = 31;
	}
	else if (type == 3) {
		num_exp = 11;
		num_frac = 63;
	}
	float real_exp = 0;
	int r = 0;
	int l = 0;
	for (int i = num_exp; i > 0; i--) {
		r = (int(num[i]) % 48) * pow(2, l);
		real_exp = real_exp + r;
		l++;
	}
	//cout << real_exp << endl;
	if (real_exp == 0) {
		komma = 0.0;
	}
	//cout << komma << endl;
	for (int i = num_exp + 1; i < num_frac + 1; i++) {
		if (num[i] == '1') {
			p = 1 / pow(2, j);
			komma = komma + p;
		}
		j++;
	}
	return komma;
}

float print_num(string num, int type) {
	float exp = calc_exp(num, type);
	float frac = calc_frac(num, type);
	float sign = 1.0;
	float res;
	//cout << exp << " " << frac << endl;
	if (num[0] == '1') {
		sign = -1.0;
	}
	res = sign * pow(2, exp) * frac;
	return res;
}


char* bits(unsigned u) {
	static char bits[40];
	char* p = bits + sizeof bits;
	*--p = 0;
	for (unsigned i = 0; i != 32; i++) {
		//if (i && !(i & 3)) *--p = ',';
		*--p = ((1u << i) & u) ? '1' : '0';
	}
	//assert(p == bits);
	return p;
}

char* encode(float f) {
	unsigned u = *(unsigned*)&f;
	//printf("encode (%11g ) =  0x%08x = %s\n", f, u, bits(u));
	char* bit;
	bit = bits(u);
	return bit;
}
