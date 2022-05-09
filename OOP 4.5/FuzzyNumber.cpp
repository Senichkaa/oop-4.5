//FuzzyNumber.cpp
#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	:x(0),l(0),r(0)
{
}

FuzzyNumber::FuzzyNumber(double x, double l, double r)
{
	if (x > (x - l) && (x + r) > x)
	{
		set_x(x);
		set_l(l);
		set_r(r);
	}
	else
	{
		set_x(0);
		set_l(0);
		set_r(0);
	}
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
	:x(v.x),l(v.l),r(v.r)
{
}

FuzzyNumber* FuzzyNumber::operator=(Pair* r)
{
	this->set_l(get_l());
	this->set_r(get_r());
	this->set_x(get_x());
	return this;
}

FuzzyNumber* FuzzyNumber::operator+(Pair* F)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->set_x(this->get_x() + ((FuzzyNumber*)F)->get_x());
	T->set_l(this->get_x() + ((FuzzyNumber*)F)->get_x() - this->get_l() - ((FuzzyNumber*)F)->get_l());
	T->set_r(this->get_x() + ((FuzzyNumber*)F)->get_x() + this->get_r() + ((FuzzyNumber*)F)->get_r());
	return T;
}

FuzzyNumber* FuzzyNumber::operator-(Pair* F)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->set_x(this->get_x() - ((FuzzyNumber*)F)->get_x());
	T->set_l(this->get_x() - ((FuzzyNumber*)F)->get_x() - this->get_l() - ((FuzzyNumber*)F)->get_l());
	T->set_r(this->get_x() - ((FuzzyNumber*)F)->get_x() + this->get_r() + ((FuzzyNumber*)F)->get_r());
	return T;
}

FuzzyNumber* FuzzyNumber::operator*(Pair* F)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->set_x(this->get_x() * ((FuzzyNumber*)F)->get_x());
	T->set_l(this->get_x() * ((FuzzyNumber*)F)->get_x() - ((FuzzyNumber*)F)->get_x() * this->get_l() - this->get_x()
		* ((FuzzyNumber*)F)->get_l() - this->get_l() * ((FuzzyNumber*)F)->get_l());
	T->set_r(this->get_x() * ((FuzzyNumber*)F)->get_x() + ((FuzzyNumber*)F)->get_x() * this->get_r() + this->get_x()
		* ((FuzzyNumber*)F)->get_r() + this->get_r() * ((FuzzyNumber*)F)->get_r());
	return T;
}

FuzzyNumber* FuzzyNumber::operator/(Pair* F)
{
	FuzzyNumber* T = new FuzzyNumber();
	if (((FuzzyNumber*)F)->get_x() > 0 && (((FuzzyNumber*)F)->get_x() + ((FuzzyNumber*)F)->get_r()) > 0
		&& (((FuzzyNumber*)F)->get_x() - ((FuzzyNumber*)F)->get_l()) > 0)
	{
		T->set_x(this->get_x() / ((FuzzyNumber*)F)->get_x());
		T->set_l((this->get_x() - this->get_l()) / (((FuzzyNumber*)F)->get_x() + ((FuzzyNumber*)F)->get_r()));
		T->set_r((this->get_x() + this->get_r()) / (((FuzzyNumber*)F)->get_x() - ((FuzzyNumber*)F)->get_l()));
	}
	else
	{
		cout << "FuzzyNumbers can not be divided" << endl;
	}
	return T;
}

ostream& FuzzyNumber::Print(ostream& out) const
{
	out << "(" << get_l() << ";" << get_x() << ";" << get_r() << ")" << endl;
	return out;
}

istream& FuzzyNumber::Insert(istream& in)
{
	double x;
	double l;
	double r;
	do
	{
		cout << "x: "; in >> x;
		cout << "l: "; in >> l;
		cout << "r: "; in >> r;
	} while (!(x > (x - 1) && (x + r) > x));
	this->set_x(x);
	this->set_l(l);
	this->set_r(r);
	return in;
}

FuzzyNumber operator/(int a, const FuzzyNumber F)
{
	FuzzyNumber T(0, 0, 0);
	T.set_x(a / F.get_x());
	T.set_l(a / (F.get_x() + F.get_l()));
	T.set_r(a / (F.get_x() - F.get_r()));
	return T;
}
