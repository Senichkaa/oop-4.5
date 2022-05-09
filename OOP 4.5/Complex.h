//Complex.h
#pragma once
#include "Pair.h"
class Complex : public Pair
{
private:
	double x, y;
public:
	Complex();
	Complex(double x, double y);
	Complex(const Complex& v);

	double get_x() const { return x; }
	double get_y() const { return y; }

	void set_x(double value) { x = value; }
	void set_y(double value) { y = value; }

	Complex& Conj();
	virtual Complex* operator = (Pair* r);
	virtual Complex* operator + (Pair* F);
	virtual Complex* operator - (Pair* F);
	virtual Complex* operator * (Pair* F);
	virtual Complex* operator / (Pair* F);
	virtual bool operator == (Pair* F);

	virtual ostream& Print(ostream& out) const;
	virtual istream& Insert(istream& in);
};

