//Pair.h
#pragma once
#pragma pack(1)
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Pair
{
public:
	virtual Pair* operator = (Pair* r) = 0;
	virtual Pair* operator + (Pair* F) = 0;
	virtual Pair* operator - (Pair* F) = 0;
	virtual Pair* operator * (Pair* F) = 0;
	virtual Pair* operator / (Pair* F) = 0;

	virtual ostream& Print(ostream& out) const = 0;
	virtual istream& Insert(istream& in) = 0;
};

