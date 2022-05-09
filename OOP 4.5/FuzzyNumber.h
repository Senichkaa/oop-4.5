//FuzzyNumber.h
#pragma once
#include "Pair.h"

class FuzzyNumber : public Pair
{
private:
	double x, l, r;
public:
	FuzzyNumber();
	FuzzyNumber(double x,double l,double r);
	FuzzyNumber(const FuzzyNumber& v);

	double get_x() const { return x; }
	double get_l() const { return l; }
	double get_r() const { return r; }

	void set_x(double value) { x = value; }
	void set_l(double value) { l = value; }
	void set_r(double value) { r = value; }

	virtual FuzzyNumber* operator = (Pair* r);
	virtual FuzzyNumber* operator + (Pair* F);
	virtual FuzzyNumber* operator - (Pair* F);
	virtual FuzzyNumber* operator * (Pair* F);
	virtual FuzzyNumber* operator / (Pair* F);

	friend FuzzyNumber operator / (int a, const FuzzyNumber F);

	virtual ostream& Print(ostream& out) const;
	virtual istream& Insert(istream& in);

};

