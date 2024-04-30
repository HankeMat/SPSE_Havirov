//Linking header file
#include "header.h"

/**
 * @brief Constructor for initializing the fraction (happens with declaration of fraction)
 */
Fraction::Fraction(){
	this->numerator = 1;
	this->denominator = 1;
}

/**
 * @brief Function for operator "<<" to work for fraction (printing)
 * 
 * @param content 
 * @param output 
 * 
 * @return output
 */
ostream& operator << (ostream& output, Fraction content){
	content.shortenFraction();	//Shortening the fraction before printing
	
	//Conditions for correct printing fraction with minuses
	if(content.denominator < 0 && content.numerator >= 0){	
		output << content.numerator * -1 << "/" << content.denominator * -1;
	}else if(content.denominator < 0 && content.numerator < 0){
		output << content.numerator * -1 << "/" << content.denominator * -1;
	}else{
		output << content.numerator << "/" << content.denominator;
	}

	return output;
}


/**
 * @brief Function for operator "<<" to work for fraction (setting)
 * 
 * @param content 
 * @param input 
 * 
 * @return input
 */
istream& operator >> (istream& input, Fraction& content){
	cout << "Numerator: ";
	input >> content.numerator;	//Setting numerator
	do{							//Setting denominator but cannot be "0"
		cout << "Denominator: ";
		input >> content.denominator;
		if(content.denominator == 0){	//Message to remind user that denominator cannot be "0"
			cout << "Denominator cannot be 0" << endl;
		}
	}while(content.denominator == 0);

	return input;	
}

/**
 * @brief Function for finding the GCD
 * 
 * @return gcd
 */
int Fraction::findGcd(){
	int gcd = 1;	//Default declaration of GCD value
	if(this->denominator < this->numerator){	//If numerator is greater than denominator
		for(int i=1;i<=this->denominator;i++){	//Count only to value of denominator
			if(this->denominator % i == 0 && this->numerator % i == 0){	//Condition whether the fraction is dividable by "i"
				gcd = i;	//Settign GCD as "i" (rewrites whenever it finds new GCD)
			}
		}	
	}else if(this->numerator < this->denominator){	//If denominator is greater than numerator
		for(int i=1;i<=this->numerator;i++){		//Count only to value of numerator
			if(this->denominator % i == 0 && this->numerator % i == 0){	//Condition whether the fraction is dividable by "i"
				gcd = i;	//Settign GCD as "i" (rewrites whenever it finds new GCD)
			}
		}
	}else{				//If denominator is similar to numerator
		for(int i=1;i<=this->numerator;i++){	//Count to one of them (does not matter)
			if(this->denominator % i == 0 && this->numerator % i == 0){	//Condition whether the fraction is dividable by "i"
				gcd = i;	//Settign GCD as "i" (rewrites whenever it finds new GCD)
			}
		}
	}
	
	return gcd;
}

/**
 * @brief Function for shortening the fraction
 */
void Fraction::shortenFraction(){
	int gcd = this->findGcd();	//Looking for GCD (greatest common divisor)

	this->denominator = this->denominator / gcd;	//Shortening
	this->numerator = this->numerator / gcd;
}

/**
 * @brief Function for operator "*" to work for fraction
 * 
 * @param a 
 * @param b 
 * 
 * @return result of multiplying a and b
 */
Fraction operator * (Fraction a, Fraction b){
	Fraction result;	//Declaration of result fraction
	result.numerator = a.numerator * b.numerator;	//Calculation
	result.denominator = a.denominator * b.denominator;
	
	return result;
}

/**
 * @brief Function for operator "-" to work for fraction
 * 
 * @param a 
 * @param b 
 * 
 * @return difference between a and b
 */
Fraction operator - (Fraction a, Fraction b){
	Fraction result;	//Declaration of result fraction
	result.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);	//Calculation
	result.denominator = a.denominator * b.denominator;
	
	return result;
}

/**
 * @brief Function for operator "+" to work for fraction
 * 
 * @param a 
 * @param b 
 * 
 * @return total of a and b
 */
Fraction operator + (Fraction a, Fraction b){
	Fraction result;	//Declaration of result fraction
	result.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);	//Calculation
	result.denominator = a.denominator * b.denominator;
	
	return result;
}

/**
 * @brief Function for operator "/" to work for fraction
 * 
 * @param a 
 * @param b 
 * 
 * @return result of deviding a and b
 */
Fraction operator / (Fraction a, Fraction b){
	Fraction result;	//Declaration of result fraction
	result.numerator = a.numerator * b.denominator;	//Calculation
	result.denominator = a.denominator * b.numerator;
	
	return result;
}

/**
 * @brief Function that compares two fractions
 * 
 * @param b 
 * 
 * @return "-1" if A < B, "1" if A > B, "0" if A = B
 */
int Fraction::compareWith(Fraction b){
	if((this->numerator / this->denominator) < (b.numerator / b.denominator)){
		//B is greater than A
		return -1;
	}else if((this->numerator / this->denominator) > (b.numerator / b.denominator)){
		//A is greater than B
		return 1;
	}else{
		//Fractions are similar
		return 0;
	}
}
