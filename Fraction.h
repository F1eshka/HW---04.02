#pragma once

#include "Date.h"
#include "Group.h"
#include <iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction();

	Fraction(int numerator, int denominator);

	Fraction(int value);

	double GetDecimal() const;

	void Print() const;

	void PrintDecimal() const;


	int GetNumerator() const
	{
		return numerator;
	}

	int GetDenominator() const
	{
		return denominator;
	}

	void SetNumerator(int numerator) {
		this->numerator = numerator;
	}

	void SetDenominator(int denominator) {
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	bool GreaterThan(const Fraction& another) const;
	bool LessThan(const Fraction& another) const;
	bool IsEquals(const Fraction& another) const;

	Fraction operator + (const Fraction& right)
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = this->numerator * right.denominator + right.numerator * this->denominator;
		result.denominator = this->denominator * right.denominator;
		return result;
	}

	Fraction operator - (const Fraction& right)
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = this->numerator * right.denominator - right.numerator * this->denominator;
		result.denominator = this->denominator * right.denominator;
		return result;
	}

	Fraction operator * (const Fraction& right)
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = this->numerator * right.numerator;
		result.denominator = this->denominator * right.denominator;
		return result;
	}

	Fraction operator / (const Fraction& right)
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = this->numerator * right.denominator;
		result.denominator = this->denominator * right.numerator;
		return result;
	}

	Fraction operator - ()
	{
		cout << "CLASS METHOD\n";
		Fraction result;
		result.numerator = -numerator;
		result.denominator = denominator;
		return result;
	}
};
