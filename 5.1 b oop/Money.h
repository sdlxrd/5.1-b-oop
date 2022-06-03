#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
#include "NewException.h"

using namespace std;

class Money
{
private:
	long grn;
	unsigned long kop;
public:
	Money();
	Money(const long, const unsigned long);
	Money(const Money&);
	~Money() {}
	
	void setGrn(long grn);
	void setKop(unsigned long kop);
	long getGrn() const { return grn; }
	unsigned long getKop() const { return kop; }
	
	Money& operator = (const Money&);
	operator string() const;
	
	friend Money operator - (const Money&, const Money&);
	friend Money operator * (const Money&, const double);
	
	bool operator ==(const Money&);
	bool operator >(const Money&);
	bool operator <(const Money&);
	
	
	friend istream& operator >> (istream&, Money&);
	friend ostream& operator << (ostream&, const Money&);
	
	Money& operator ++();
	Money operator ++(int);
	Money& operator --();
	Money operator --(int);
};