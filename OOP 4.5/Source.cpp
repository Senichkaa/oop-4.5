//Source.cpp
#include "Complex.h"
#include "FuzzyNumber.h"
#include "Pair.h"

ostream& operator << (ostream& out, const Pair& r)
{
	return r.Print(out);
}

istream& operator >> (istream& in, Pair& r)
{
	return r.Insert(in);
}

int main()
{
	Pair* A1 = new Complex(-4, 5);
	Pair* B1 = new Complex();
	Pair* C1 = new Complex();
	Pair* D1 = new Complex();
	Pair* E1 = new Complex();
	Pair* F1 = new Complex();

	cout << "*A1 = " << *A1 << endl;

	cin >> *B1;
	cout << "*B1 = " << *B1 << endl;

	C1 = *A1 + B1;
	cout << "*C1 = " << *C1 << endl;

	D1 = *A1 - B1;
	cout << "*D1 = " << *D1 << endl;

	E1 = *A1 * B1;
	cout << "*E1 = " << *E1 << endl;

	F1 = *A1 / B1;
	cout << "*F1 = " << *F1 << endl;

	if (A1 == B1)
		cout << "Comlex numbers are equal" << endl;
	else
		cout << "Complex number are not equal " << endl;

	cout << "Conjugate expression" << endl;
	cout << ((Complex*)A1)->Conj() << endl;

	cout << typeid(A1).name() << endl;
	cout << typeid(*A1).name() << endl << endl;

	delete A1;
	delete B1;
	delete C1;
	delete D1;
	delete E1;
	delete F1;

	Pair* A2 = new FuzzyNumber(4, 1, 7);
	Pair* B2 = new FuzzyNumber();
	Pair* C2 = new FuzzyNumber();
	Pair* D2 = new FuzzyNumber();
	Pair* E2 = new FuzzyNumber();
	Pair* F2 = new FuzzyNumber();

	cout << "*A2 = " << *A2 << endl;

	cin >> *B2;
	cout << "*B2 = " << *B2 << endl;

	C2 = *A2 + B2;
	cout << "*C2 = " << *C2 << endl;

	D2 = *A2 - B2;
	cout << "*D2 = " << *D2 << endl;

	E2 = *A2 * B2;
	cout << "*E2 = " << *E2 << endl;

	F2 = *A2 / B2;
	cout << "*F2 = " << *F2 << endl;

	FuzzyNumber M(1, 5, 3);
	FuzzyNumber G2 = 1 / M;
	cout << "G2 = " << G2 << endl;

	cout << typeid(A2).name() << endl;
	cout << typeid(*A2).name() << endl;

	delete A2;
	delete B2;
	delete C2;
	delete D2;
	delete E2;
	delete F2;

	Complex L(2, 7);
	FuzzyNumber Q(3, 7, 5);

	Pair* N[2];

	N[0] = &L;
	N[1] = &Q;

	cout << "x = " << ((Complex*)N[0])->get_x() << endl;
	cout << "l = " << ((FuzzyNumber*)N[1])->get_l() << endl;
}