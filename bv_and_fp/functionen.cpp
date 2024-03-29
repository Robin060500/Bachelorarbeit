#define _GLIBCXX_USE_CXX11_ABI 0 / 1
#include "bachelor.hpp"
#include <math.h>

void start(string expo, string mant) {

	int expo_bit = stoi(expo);
	int mantis_bit = stoi(mant);
	int length = 1 + expo_bit + mantis_bit + 6;
	int or_bit = pow(2, expo_bit + 1) - 1;
	int type = 0;
	fstream write;
	write.open("code"+expo+"_"+mant+".smt2", ios::out);
		write << ";;;Beginning of the Dokument of Robins bachelor thesis" << endl;
	write << endl;
	//header
	write << ";;;header" << endl;
	write << "(set-info :source |Robin Trueby Bachelorthesis|)" << endl;
	write << "(set-option :produce-models true)" << endl;
	write << "(set-logic QF_BVFP)" << endl;
	
	write << endl;
	//set the variables
	write << ";;;set the variables" << endl;
	write << "(declare-fun x () (_ BitVec " << length - 6 << " ))" << endl;
	write << "(declare-fun y () (_ BitVec " << length - 6 << " ))" << endl;
	write << "(declare-fun null () (_ BitVec 1))" << endl;
	write << "(declare-fun x_p () (_ BitVec " << length - 7 << "))" << endl;
	write << "(declare-fun y_p () (_ BitVec " << length - 7 << "))" << endl;
	write << "(declare-fun x_use () (_ BitVec " << length << " ))" << endl;
	write << "(declare-fun y_use () (_ BitVec " << length << " ))" << endl;
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
	write << "(declare-fun z_expo_finaaal () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun z_mant_final () (_ BitVec " << mantis_bit << " ))" << endl;
	write << "(declare-fun z_mant () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun mant () (_ BitVec " << mantis_bit + 7 << " ))" << endl;
	write << "(declare-fun mant_short () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun other_mant () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun other_man () (_ BitVec " << mantis_bit + 7 << " ))" << endl;
	write << "(declare-fun z_mant_over () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun z_mant_good () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun z_mant_good2 () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun z_mant_good3 () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun mant_good2 () (_ BitVec " << mantis_bit + 4 << " ))" << endl;
	write << "(declare-fun expo_diff () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun expo_diff_2 () (_ BitVec " << expo_bit << " ))" << endl;
	write << "(declare-fun expo_diff_long () (_ BitVec " << mantis_bit + 7 << " ))" << endl;
	write << "(declare-fun expo_diff_long_long () (_ BitVec " <<or_bit << " ))" << endl;
	write << "(declare-fun g () (_ BitVec 1))" << endl;
	write << "(declare-fun r () (_ BitVec 1))" << endl;
	write << "(declare-fun s () (_ BitVec 1))" << endl;
	write << "(declare-fun lsb () (_ BitVec 1))" << endl;
	write << "(declare-fun ori () (_ BitVec 1))" << endl;
	write << "(declare-fun ori1 () (_ BitVec 1))" << endl;
	write << "(declare-fun ori2 () (_ BitVec 1))" << endl;
	write << "(declare-fun ori3 () (_ BitVec 1))" << endl;
	write << "(declare-fun ori4 () (_ BitVec 1))" << endl;
	write << "(declare-fun mant_long () (_ BitVec " << or_bit << " ))" << endl;
	write << "(declare-fun mant_long2 () (_ BitVec " << or_bit << " ))" << endl;
	write << "(declare-fun mant_right () (_ BitVec " << or_bit - mantis_bit - 4 << " ))" << endl;
	write << "(declare-fun over1 () (_ BitVec 1))" << endl;
	write << "(declare-fun over2 () (_ BitVec 1))" << endl;
	write << "(declare-fun over3 () (_ BitVec 1))" << endl;
	write << "(declare-fun over4 () (_ BitVec 1))" << endl;
	write << "(declare-fun over5 () (_ BitVec 1))" << endl;
	write << "(declare-fun over7 () (_ BitVec 1))" << endl;
	write << "(declare-fun over8 () (_ BitVec 1))" << endl;
	write << "(declare-fun over9 () (_ BitVec 1))" << endl;
	write << "(declare-fun over10 () (_ BitVec 1))" << endl;
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
	string bin_num2;
	bin_num2 = num_gen_str(bin_num2, length - 6);
	write << ";;;(assert (= x #b" << bin_num1 << "))" << endl;
	write << ";;;(assert (= y #b" << bin_num2 << "))" << endl;

	write << endl;

	write << "(assert (= x (concat null x_p)))" << endl;
	write << "(assert (= y (concat null y_p)))" << endl;
	write << "(assert (= null #b0))" << endl;


	//add the 6 zeros
	write << ";;;add the 6 zeros" << endl;
	write << "(assert (= x_use (concat x #b000000)))" << endl;
	write << "(assert (= y_use (concat y #b000000)))" << endl;

	write << endl;
	//extract sign mantissa expo
	write << ";;;extract sign mantissa expo" << endl;
	write << "(assert (= x_sign ((_ extract " << length - 1 << " " << length - 1 << ") x_use)))" << endl;
	write << "(assert (= y_sign ((_ extract " << length - 1 << " " << length - 1 << ") y_use)))" << endl;
	write << "(assert (= x_expo ((_ extract " << length - 2 << " " << length - 1 - expo_bit << ") x_use)))" << endl;
	write << "(assert (= y_expo ((_ extract " << length - 2 << " " << length - 1 - expo_bit << ") y_use)))" << endl;
	write << "(assert (= x_man ((_ extract " << mantis_bit + 5 << " 0) x_use)))" << endl;
	write << "(assert (= y_man ((_ extract " << mantis_bit + 5 << " 0) y_use)))" << endl;
	
	write << endl;
	//check vor nan and inf
	write << ";;;check for nan and inf" << endl;
	string n0_str = "#b";
	for (int n = 0; n < expo_bit; n++) {
		n0_str = n0_str + "1";
	}
	write << "(assert (= nan1 (ite (bvuge x_expo " << n0_str << ") (ite (bvuge x_man (_ bv1 " << mantis_bit + 6 << ")) #b1 #b0 ) #b0 )))" << endl;
	write << "(assert (= inf1 (ite (bvuge x_expo " << n0_str << ") (ite (bvuge x_man (_ bv1 " << mantis_bit + 6 << ")) #b0 #b1 ) #b0 )))" << endl;

	write << "(assert (= nan2 (ite (bvuge y_expo " << n0_str << ") (ite (bvuge y_man (_ bv1 " << mantis_bit + 6 << ")) #b1 #b0 ) #b0 )))" << endl;
	write << "(assert (= inf2 (ite (bvuge y_expo " << n0_str << ") (ite (bvuge y_man (_ bv1 " << mantis_bit + 6 << ")) #b0 #b1 ) #b0 )))" << endl;
	write << "(assert (= inf(ite (or (= inf1 #b1) (= inf2 #b1)) #b1 #b0 )))" << endl;
	write << "(assert (= nan(ite (or (= nan1 #b1) (= nan2 #b1)) #b1 #b0 )))" << endl;

	write << endl;
	//add hidden bit/ check for denormal
	
	write << ";;;add hidden bit/ check for denormal" << endl;
	write << "(assert (= x_mant(ite (bvuge (_ bv0 " << expo_bit << ") x_expo)(concat #b0 x_man)( concat #b1 x_man))))" << endl;
	write << "(assert (= denormalx(ite (bvuge (_ bv0 " << expo_bit << ") x_expo) #b1 #b0 )))" << endl;
	write << "(assert (= y_mant(ite (bvuge (_ bv0 " << expo_bit << ") y_expo)(concat #b0 y_man)( concat #b1 y_man))))" << endl;
	write << "(assert (= denormaly(ite (bvuge (_ bv0 " << expo_bit << ") y_expo) #b1 #b0 )))" << endl;

	write << endl;
	//compare expo
	write << ";;;compare expo" << endl;
	write << "(assert (= z_expo (ite (bvuge x_expo y_expo ) x_expo y_expo )))" << endl;
	write << "(assert (= expo_diff (ite (bvuge x_expo y_expo) (bvsub x_expo y_expo) (bvsub y_expo x_expo))))" << endl;
	write << "(assert (= expo_diff_2 (ite (xor (= denormalx #b1) (= denormaly #b1)) (bvsub expo_diff (_ bv1 " << expo_bit << ")) expo_diff )))" << endl;
	string expo_diff = "#b";
	for (int m = mantis_bit + 7 - expo_bit; m > 0; m--) {
		expo_diff = expo_diff + "0";
	}
	if (mantis_bit + 7 > expo_bit) {
		write << "(assert (= expo_diff_long (concat " << expo_diff << " expo_diff_2)))" << endl;
	}
	else if (mantis_bit + 7 == expo_bit) {
		write << "(assert (= expo_diff_long exp_diff_2))" << endl;
	} 
	else {
		write << "(assert (= expo_diff_long ((_ extract " <<  mantis_bit + 6<< " 0) expo_diff_2))) " << endl;
	}
	

	write << endl;
	//shift the smaller mantissa
	write << ";;;shift the smaller mantissa" << endl;
	write << "(assert (= mant(ite (bvuge x_expo y_expo) (ite (= x_expo y_expo) (ite (bvuge x_man y_man) y_mant x_mant )(bvlshr y_mant expo_diff_long))(bvlshr x_mant expo_diff_long))))" << endl;
	write << "(assert (= other_man (ite (bvuge x_expo y_expo) (ite (= x_expo y_expo) (ite (bvuge x_man y_man) x_mant y_mant ) x_mant ) y_mant )))" << endl;

	

	write << endl;

	

	//new part
	write << "(assert (= mant_long(ite (bvuge x_expo y_expo) (ite (= x_expo y_expo) (ite (bvuge x_man y_man) (concat y_mant (_ bv0 " << or_bit - mantis_bit - 7<<"))";
	write << "(concat x_mant(_ bv0 " << or_bit - mantis_bit - 7 << ")))(concat y_mant(_ bv0 " << or_bit - mantis_bit - 7 << ")))(concat x_mant(_ bv0 " << or_bit - mantis_bit - 7 << ")))))" << endl;
	write << "(assert (= expo_diff_long_long (concat (_ bv0 " << or_bit - mantis_bit - 7 << ") expo_diff_long)))" << endl;
	write << "(assert (= mant_long2 (bvlshr mant_long expo_diff_long_long)))" << endl;
	write << "(assert (= mant_right ((_ extract " << or_bit - mantis_bit - 5 << " 0) mant_long2)))" << endl;
	write << "(assert (= ori2 (ite (bvuge mant_right (_ bv1 " << or_bit - mantis_bit - 4 << ")) #b1 #b0)))" << endl;
	write << "(assert (= ori3 ((_ extract 0 0)mant_short)))" << endl;
	write << "(assert (= mant_good2 (ite (and (= ori2 #b1)(= ori3 #b0)) (bvadd mant_short (_ bv1 " << mantis_bit + 4 <<")) mant_short)))" << endl;



	//shorten mant 3 bits
	write << ";;;shorten the mant by 3 bits" << endl;
	write << "(assert (and (= other_mant ((_ extract " << mantis_bit + 6 << " 3)";
	write << " other_man)) (= mant_short ((_ extract " << mantis_bit + 6 << " 3) mant))))" << endl;


	write << endl;
	//decide add or sub
	write << ";;;decide add or sub" << endl;
	write << "(assert (= z_mant (ite (= x_sign y_sign) (bvadd other_mant mant_short)(bvsub other_mant mant_short))))" << endl;

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
	write << "(assert (= z_expo2 (ite (and (= den #b1) (and (= denormalx #b1) (= denormaly #b1)))(bvadd z_expo (_ bv1 " << expo_bit << ")) z_expo )))" << endl;

	write << endl;
	//check for overflow
	write << ";;;check for overflow" << endl;
	write << "(assert (= over1 ((_ extract " << mantis_bit + 2 << " " << mantis_bit + 2 << ") other_mant)))" << endl;
	write << "(assert (= over2 ((_ extract " << mantis_bit + 2 << " " << mantis_bit + 2 << ") mant_short)))" << endl;
	write << "(assert (= over3 ((_ extract " << mantis_bit + 2 << " " << mantis_bit + 2 << ") z_mant)))" << endl;
	write << "(assert (= over4 ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") mant_short)))" << endl;
	write << "(assert (= over5 ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") other_mant)))" << endl;
	write << "(assert (= overflow1 (ite (or (and (= den #b0) (xor (= denormalx #b0) (= denormaly #b0)))(and (or (or (and (= over1 #b1) (= over2 #b1)) (and (= over4 #b1) (= over5 #b1))) (and (xor (= over1 #b1) (= over2 #b1)) (= over3 #b0))) (= x_sign y_sign))) #b1 #b0 )))" << endl;
	write << "(assert (= z_mant_over (ite (and (= overflow1 #b1) (or (= denormalx #b0) (= denormaly #b0)))(bvlshr z_mant (_ bv1 " << mantis_bit + 4 << ")) z_mant )))" << endl;
	string n3_str = "#b1";
	for (int n = 0; n < mantis_bit + 3; n++) {
		n3_str = n3_str + "0";
	}
	write << "(assert (= z_mant_good(ite (and (= overflow1 #b1) (or (= denormalx #b0) (= denormaly #b0)))(bvadd z_mant_over " << n3_str << ") z_mant_over )))" << endl;
	write << "(assert (= z_expo_final(ite (and (= overflow1 #b1) (or (= denormalx #b0) (= denormaly #b0)))(bvadd z_expo2 (_ bv1 " << expo_bit << ")) z_expo2 )))" << endl;
	write << "(assert (= ori ((_ extract 0 0) z_mant)))" << endl;
	write << "(assert (= ori4 ((_ extract 0 0) z_mant_good)))" << endl;
	write << "(assert (= z_mant_good3 (ite (and (or (= ori2 #b1) (= ori3 #b1)) (= ori4 #b0)) (bvadd z_mant_good (_ bv1 " << mantis_bit + 4 <<")) z_mant_good)))" << endl;


	write << endl;


	write << ";;;put all together" << endl;
	string n4_str = "#b0";
	string n5_str = "#b";
	string n6_str = "#b1";
	string n9_str = "#b";
	for (int m = 0; m < length - 8; m++) {
		n4_str = n4_str + "0";
		if (m < expo_bit) {
			n5_str = n5_str + "1";
			n6_str = n6_str + "1";
			n9_str = n9_str + "1";
		}
		else {
			n5_str = n5_str + "0";
			n6_str = n6_str + "0";
		}
	}
	n5_str = n5_str + "0";
	//expo overflow
	write << ";;;expo overflow" << endl;
	write << "(assert (= over7 ((_ extract " << expo_bit - 1 << " " << expo_bit - 1 << ") z_expo2)))" << endl;
	write << "(assert (= over8 ((_ extract " << expo_bit - 1 << " " << expo_bit - 1 << ") z_expo_final)))" << endl;
	write << "(assert (= overflow2 (ite (or (= z_expo_final " << n9_str<< ")(and (= over7 #b1) (= over8 #b0))) #b1 #b0 )))" << endl;


	write << endl;
	//mant/ expo underflow (schleife ausgeschrieben)
	write << ";;;mant/ expo underflow (schleife ausgeschrieben" << endl;
	write << "(assert (= m1 ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant_good3)))" << endl;
	write << "(assert (= z_mant_2 (ite (and (= m1 #b0) (and (= denormalx #b0) (= denormaly #b0)))(bvshl z_mant_good3 (_ bv1 " << mantis_bit + 4 << "))  z_mant_good3 )))" << endl;
	write << "(assert (= z_expo_2 (ite (and (= m1 #b0) (and (= denormalx #b0) (= denormaly #b0)))(bvsub z_expo_final (_ bv1 " << expo_bit << ")) z_expo_final )))" << endl;

	for (int m = 2; m <= mantis_bit + 2; m++) {
		write << "(assert (= m" << m << " ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant_" << m << ")))" << endl;
		write << "(assert (= z_mant_" << m + 1 << " (ite (and (= m" << m << " #b0) (and (= denormalx #b0) (= denormaly #b0)))(bvshl z_mant_" << m << " (_ bv1 " << mantis_bit + 4<< ")) z_mant_" << m << " )))" << endl;
		write << "(assert (= z_expo_" << m + 1 << " (ite (and (= m" << m << " #b0) (and (= denormalx #b0) (= denormaly #b0)))(bvsub z_expo_" << m << " (_ bv1 " << expo_bit << ")) z_expo_" << m << " )))" << endl;
	}
	write << "(assert (= m" << mantis_bit + 3 << " ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= underflow1 (ite (and (= m" << mantis_bit + 3 << " #b0) (and (= denormalx #b0) (= denormaly #b0))) #b1 #b0 )))" << endl;

	write << endl;
	//round
	write << ";;;round" << endl;
	write << "(assert (= lsb ((_ extract 3 3) z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= g ((_ extract 2 2) z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= r ((_ extract 1 1) z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= s ((_ extract 0 0) z_mant_" << mantis_bit + 3 << ")))" << endl;

	write << "(assert (= z_mant_good2 (ite (or (and (= g #b1) (or (= r #b1) (= s #b1))) (and (= g #b1) (= lsb #b1)))(bvadd z_mant_" << mantis_bit + 3 << " " << n2_str << ") z_mant_" << mantis_bit + 3 << " )))" << endl;

	write << endl;
	//decide the sign
	write << ";;;decide the sign" << endl;
	string n10 = "#b";
	for (int m = 0; m < mantis_bit; m++) {
		n10 = n10 + "0";
	}
	write << "(assert (= z_sign (ite(bvuge x_expo y_expo) (ite(= x_expo y_expo) (ite(bvuge x_man y_man) x_sign y_sign ) x_sign ) y_sign )))" << endl;

	write << endl;
	//put all together
	
	write << "(assert (= z_mant_final ((_ extract " << mantis_bit + 2 << " " << "3" << " ) z_mant_good2)))" << endl;

	// check over again
	write << "(assert (= over9 ((_ extract " << mantis_bit + 3 << " " << mantis_bit +3<< ") z_mant_" << mantis_bit + 3 << ")))" << endl;
	write << "(assert (= over10 ((_ extract " << mantis_bit + 3 << " " << mantis_bit + 3 << ") z_mant_good2)))" << endl;
	write << "(assert (= z_expo_finaaal (ite (and (= over9 #b1) (= over10 #b0)) (bvadd z_expo_" << mantis_bit + 3 << "(_ bv1 " << expo_bit << ")) z_expo_" << mantis_bit + 3 << ")))" << endl;

	write << "(assert (= z_short(ite (= nan #b0) (ite (= inf #b0)";
	write << "(ite (= overflow2 #b0) (ite (= underflow1 #b0)(concat z_expo_finaaal z_mant_final)(_ bv0 " << length - 7 << ")) " << n5_str << " ) " << n5_str << " ) " << n6_str << " )))" << endl;

	write << "(assert (= z (concat z_sign z_short)))" << endl;


	
	//float
	write << "(declare-const a (_ FloatingPoint " << expo_bit << " " << mantis_bit + 1 << "))" << endl;
	write << "(declare-const b (_ FloatingPoint " << expo_bit << " " << mantis_bit + 1 << "))" << endl;
	write << "(declare-const c (_ FloatingPoint " << expo_bit << " " << mantis_bit + 1 << "))" << endl;
	write << "(declare-const xs (_ FloatingPoint " << expo_bit << " " << mantis_bit + 1 << "))" << endl;
	write << "(declare-const ys (_ FloatingPoint " << expo_bit << " " << mantis_bit + 1 << "))" << endl;
	
	//write << "(assert(= true (fp.isNormal a)))" << endl;
	write << "(assert(= true (fp.isPositive a)))" << endl;
	//write << "(assert(= true (fp.isNormal b)))" << endl;
	write << "(assert(= true (fp.isPositive b)))" << endl;
		
	write << "(assert (= c (fp.add RNE b a)))" << endl;

	write << "(assert (= xs ((_ to_fp " << expo_bit << " " << mantis_bit + 1 << ") x)))" << endl;
	write << "(assert (= ys ((_ to_fp " << expo_bit << " " << mantis_bit + 1 << ") y)))" << endl;

	write << "(assert (= ys a))" << endl;
	write << "(assert (= xs b))" << endl;
	write << "(assert (distinct ((_ to_fp " << expo_bit << " " << mantis_bit + 1 << ") z) c))";

	write << "(check-sat)" << endl;
	write << "(get-model)" << endl;
	write << "(exit)" << endl;

	write << endl;

	

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
