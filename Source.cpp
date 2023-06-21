#include"Rec.h"
#include"Skup.h"
#include"Stih.h"
#include"Strofa.h"
#include"Katren.h"
#include<iostream>

using namespace std;

int main() {

	Stih s1, s2, s3, s4;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	cin >> s4;
	//cout << ~s1 << endl;
	//cout << ~s2 << endl;
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << ~s3 << endl;
	//cout << ~s4 << endl;
	Katren k;
	k += s1;
	k += s2;
	k += s3;
	k += s4;
	k += s1;
	cout << k << endl;
	cout << *k << endl;
	cout << k.Oznaka()<<endl;
	/*Rec r1("grlce");
	Rec r2("nesto");
	Rec r3("3a.b=e");
	Stih s,s2;
	Rec r4("yey");
	Rec r5("besno");
	Rec r6("ace");
	Stih s3;

	s += r1;
	s += r2;
	s += r3;
	s3 += r4;
	s3 += r5;
	s3 += r6;

	cin >> s;
	cout << s << endl;
	cout << *s[2] << endl;
	s(2);
	s(r4, 2);
	cout << s << endl;
	cin >> s2;
	cout << s2<<endl;
	cout << *s2[2] << endl;

	cout << (s ^ s3) << endl;
	cout << +s<< endl;
	cout << ~s << endl;
	cout << *s[0] << endl;
	cout << *s[1] << endl;
	cout << *s[2] << endl;
	cout << s << endl;
	
	cin >> r2;
	cout << r3 << endl;
	cout <<+ r1<<endl;
	cout << ~r1 << endl;

	cout << r1(0) << endl;

	cout << r1(-1) << " " << r1 << " " << endl;
	cout << r1(-2) << endl;
	cout << r1(1) << endl;

	cout << (r1 ^ r2)<<endl;

	cout << r1<<endl;
	cout << r2;
	*/
	return 0;
}