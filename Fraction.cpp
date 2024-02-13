#include "Fraction.h"

Fraction::Fraction() : Fraction(0, 1)
{
	cout << "DEFAULT C-TOR!\n";
}

Fraction::Fraction(int value)
{
	numerator = value;
	denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
	cout << "PARAM CTOR!\n";
	this->numerator = numerator;
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}

double Fraction::GetDecimal() const
{
	return (double)numerator / denominator;
}

void Fraction::Print() const
{
	cout << numerator << "/" << denominator << "\n";
}

void Fraction::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

bool Fraction::LessThan(const Fraction& another) const
{
	return GetDecimal() < another.GetDecimal();
}

bool Fraction::GreaterThan(const Fraction& another) const
{
	return GetDecimal() > another.GetDecimal();
}

bool Fraction::IsEquals(const Fraction& another) const
{
	return GetDecimal() == another.GetDecimal();
}

Fraction operator + (int left, const Fraction& right)
{
	return right + left;
}

Fraction operator + (double left, const Fraction& right)
{
	return right + left;
}

Fraction operator + (const Fraction& left, int right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() + right * left.GetDenominator());
	result.SetDenominator(left.GetDenominator());
	return result;
}

Fraction operator + (const Fraction& left, double right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() + right * left.GetDenominator());
	result.SetDenominator(left.GetDenominator());
	return result;
}

Fraction operator * (const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetNumerator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetNumerator());
	return result;
}

Fraction operator - (const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}

Fraction operator + (const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}



bool operator < (const string& a, const string& b)
{
	return a < b;
}

bool operator > (const string& a, const string& b)
{
	return a > b;
}

bool operator <= (const string& a, const string& b)
{
	return a <= b;
}

bool operator >= (const string& a, const string& b)
{
	return a >= b;
}

bool operator != (const string& a, const string& b)
{
	return a != b;
}

bool operator == (const string& a, const string& b)
{
	return a == b;
}