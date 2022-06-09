#include "Money.h"
#include <iostream>
#include <string>
#include <sstream>
#define Pair Money
using namespace std;

void Money::setGrn(long value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		grn = value;
	}
}

void Money::setKop(unsigned long value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		kop = value;
	}
}
Money::Money()
{
	grn = 0;
	kop = 0;
}
Money::Money(const long grn = 0,const unsigned long kop = 0)
{
	if (grn < 0 || kop < 0)
	{
		throw invalid_argument("values must be bigger than 0");
	}
	else
	{
		long a = grn;
		unsigned long b = kop;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		setGrn(a);
		setKop(b);
	}
}
Money::Money(const Money& x)
{
	this->grn = x.grn;
	this->kop = x.kop;
}
Money& Money::operator =(const Money& x)
{
	grn = x.grn;
	kop = x.kop;
	
	return *this;
}
Money::operator string() const
{
	stringstream ss;
	ss << grn << "." << kop << endl;
	return ss.str();
}
istream& operator >> (istream& in, Money& x)
{
	long f;
	long s;
	cout << "Grn = "; in >> f;
	cout << "Kop = "; in >> s;
	cout << endl;
	if (f < 0 || s < 0)
	{
		throw NewException("Numbers must be bigger than 0!!!");
	}
	else
	{
		x.setGrn(f);
		x.setKop(s);
	}
	return in;
}
ostream& operator <<(ostream& out, const Money& x)
{
	out << string(x);
	return out;
}
Money operator -(const Money& x, const Money& y)
{
	Money t(0, 0);
	if ((x.getGrn() < y.getGrn()) && (x.getKop() < y.getKop()))
	{
		t.setGrn(0);
		t.setKop(0);
		return t;
	}
	if (x.getKop() < y.getKop())
	{
		t.setGrn((x.getGrn() - 1) - y.getGrn());
		t.setKop(100 - (y.getKop() - x.getKop()));
	}
	else
	{
		t.setGrn(x.getGrn() - y.getGrn());
		t.setKop(x.getKop() - y.getKop());
	}
	return t;
}
Money operator *(const Money& x, const double n)
{
	Money t(0, 0);
	long a = (x.getGrn() * n);
	unsigned long b = (x.getKop() * n);
	while (b > 99)
	{
		b -= 100;
		a++;
	}
	t.setGrn(a);
	t.setKop(b);
	return t;
}

bool Money::Init(int first, int second)
{
	if (first >= 0 && second >= 0)
	{
		grn = first;
		kop = second;
		return true;
	}
	else
	{
		return false;
	}
}

Money& Money::operator ++()
{
	grn++;
	kop++;
	return *this;
}
Money Money::operator ++(int)
{
	Money t(*this);

	grn++;
	kop++;

	return t;
}
Money& Money::operator --()
{
	grn--;
	kop--;
	
	return *this;
}
Money Money::operator --(int)
{
	Money t(*this);
	grn--;
	kop--
		;
	

	return t;
}

bool Pair::operator ==	(const Pair& x)
{
	return (this->grn == x.grn && this->kop == x.kop);
}
bool Pair::operator >(const Pair& x)
{
	if ((this->grn > x.grn) || (this->grn == x.grn && this->kop > x.kop))
		return true;
	else
		return false;
}
bool Pair::operator <(const Pair& x)
{
	if ((this->grn < x.grn) || (this->grn == x.grn && this->kop < x.kop))
		return true;
	else
		return false;
}