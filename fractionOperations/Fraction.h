/* W05
 * Fraction.h
 * Ivy Leano
 */

#ifndef SICT_Fraction_H
#define SICT_Fraction_H

namespace sict 
{
	class Fraction 
	{
		int numerator;
		int denominator;
		int max() const;
		int min() const;
		int gcd() const;
		void reduce();

	public:

		Fraction();
		Fraction(int numer, int denom);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);
	};
}

#endif

