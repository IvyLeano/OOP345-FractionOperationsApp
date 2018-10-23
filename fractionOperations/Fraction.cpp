/* W05
 * Fraction.cpp
 * Ivy Leano
 */

#include<iostream>
#include"Fraction.h"
using namespace std;

namespace sict 
{
	Fraction::Fraction()
	{
		numerator = 0;
		denominator = 0;
	}

	Fraction::Fraction(int numer, int denom)
	{
		if (numer < 0 || denom < 0) 
		{
			*this = Fraction();
		}
		
		else 
		{
			numerator = numer;
			denominator = denom;
			reduce();
		}
	}

	void Fraction::reduce()
	{
		int greCommDeno = gcd();

		denominator = denominator / greCommDeno;
		numerator = numerator / greCommDeno;
	}

	int Fraction::gcd() const
	{
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) 
		{ // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) 
			{
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	int Fraction::min() const
	{
		int lesser;

		numerator < denominator ? lesser = numerator : lesser = denominator;

		return lesser;
	}

	int Fraction::max() const
	{
		int greater;

		numerator > denominator ? greater = numerator : greater = denominator;

		return greater;
	}

	bool Fraction::isEmpty() const
	{
		return (numerator == 0 && denominator == 0);
	}

	void Fraction::display() const
	{
		if (!isEmpty() && denominator != 1) 
		{
			cout << numerator << "/" << denominator;
		}
		else if (!isEmpty() && denominator == 1) 
		{
			cout << numerator;
		}
		else 
		{
			cout << "no fraction stored";
		}
	}

	Fraction Fraction::operator+(const Fraction & rhs) const
	{
		Fraction add; 

		if (!isEmpty() && !rhs.isEmpty()) 
		{
			add = operator*(rhs);
			add.numerator += (rhs.numerator * this->denominator);
			add.reduce();
		}
		return add;
	}

	Fraction Fraction::operator*(const Fraction & rhs) const
	{
		Fraction add;

		if (!isEmpty() && !rhs.isEmpty()) 
		{
			add.numerator = (this->numerator * rhs.denominator);
			add.denominator = (this->denominator * rhs.denominator);
		}
		return add;
	}

	bool Fraction::operator==(const Fraction & rhs) const
	{	
		bool equalNum = numerator == rhs.numerator;
		bool equalDeno = denominator == rhs.denominator;
		bool empt = isEmpty() && rhs.isEmpty();

		return (!empt && equalDeno && equalNum);
	}

	bool Fraction::operator!=(const Fraction & rhs) const
	{
		bool equalNum = numerator == rhs.numerator;
		bool equalDeno = denominator == rhs.denominator;
		bool empt = isEmpty() && rhs.isEmpty();

		return !(empt && equalDeno & equalNum);
	}

	Fraction& Fraction::operator+=(const Fraction & rhs)
	{
		!isEmpty() && !rhs.isEmpty() ? *this = operator+(rhs) : *this = Fraction();
		
		return *this;
	}

}