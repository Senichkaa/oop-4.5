//Complex.cpp
#include "Complex.h"

Complex::Complex()
	:x(0),y(0)
{
}

Complex::Complex(double x, double y)
	:x(x),y(y)
{
}

Complex::Complex(const Complex& v)
	:x(v.x),y(v.y)
{
}
Complex& Complex::Conj() //комплексно спряжене число
{
	this->set_y(-this->get_y());
	return *this;
}

Complex* Complex::operator=(Pair* r)
{
	this->set_x(get_x());
	this->set_y(get_y());
	return this;
}

Complex* Complex::operator+(Pair* F)
{
	Complex* T = new Complex();
	T->set_x(this->get_x() + ((Complex*)F)->get_x());
	T->set_y(this->get_y() + ((Complex*)F)->get_y());
	return T;
}

Complex* Complex::operator-(Pair* F)
{
	Complex* T = new Complex();
	T->set_x(this->get_x() - ((Complex*)F)->get_x());
	T->set_y(this->get_y() - ((Complex*)F)->get_y());
	return T;
}

Complex* Complex::operator*(Pair* F)
{
	Complex* T = new Complex();
	T->set_x(this->get_x() * ((Complex*)F)->get_x() - this->get_y() * ((Complex*)F)->get_y());
	T->set_y(this->get_y() * ((Complex*)F)->get_y() + ((Complex*)F)->get_x() * this->get_y());
	return T;
}

Complex* Complex::operator/(Pair* F)
{
	Complex* T = new Complex();
	T->set_x((this->get_x() * ((Complex*)F)->get_x() + this->get_y() * ((Complex*)F)->get_y()) /
		(((Complex*)F)->get_x() * ((Complex*)F)->get_x() + ((Complex*)F)->get_y() * ((Complex*)F)->get_y()));
	T->set_y((((Complex*)F)->get_x() * this->get_y() - this->get_x() * ((Complex*)F)->get_y()) /
		(((Complex*)F)->get_x() * ((Complex*)F)->get_x() + ((Complex*)F)->get_y() * ((Complex*)F)->get_y()));
	return T;
}

bool Complex::operator==(Pair* F)
{
	Complex* T = new Complex();
	return T->get_x() == ((Complex*)F)->get_x() && T->get_y() == ((Complex*)F)->get_y();
}

ostream& Complex::Print(ostream& out) const
{
	out << get_x() << "+i*" << get_y() << endl;
	return out;
}

istream& Complex::Insert(istream& in)
{
	double x, y;
	cout << "x: "; in >> x;
	cout << "y: "; in >> y;
	this->set_x(x);
	this->set_y(y);
	return in;
}

