#ifndef HEADER_H
#define HEADER_H

//Linking common libraries
#include <iostream>
#include <string>

using namespace std;

//Class for Fraction and its methods
class Fraction {
//Private methods and data - Can be called just from inside the class where it is defined
private:
	int numerator;
	int denominator;
	void shortenFraction();
//Public methods can be called anywhere
public:
	Fraction();
	friend ostream& operator << (ostream &output, Fraction content);
	friend istream& operator >> (istream &input, Fraction& content);
	friend Fraction operator * (Fraction a, Fraction b);
	friend Fraction operator - (Fraction a, Fraction b);
	friend Fraction operator + (Fraction a, Fraction b);
	friend Fraction operator / (Fraction a, Fraction b);
	int compareWith(Fraction b);
	int findGcd();
};


#endif
