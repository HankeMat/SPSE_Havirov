/**
 * @file main.cpp
 * @author Hanke Matěj (hanke.matej@seznam.cz)
 * @brief Program that represents book database
 * @version 0.1
 * @date 2023-04-15
 * 
 * @copyright Copyright Hanke Matěj (c) 2023
 * 
 */

//Linking header file
#include "header.h"

/**
 * @brief constructor
 * 
 * @return 
 */
Book::Book(){
	this->name = "UNSET";
	this->id = 0;
	this->price = 0;
}

/**
 * @brief friend method for being able to print easily a book
 * 
 * @param content 
 * @param output 
 * 
 * @return output
 */
ostream& operator << (ostream& output, Book content){
	output << "Book name: " << content.name << endl << "ID: " << content.id << endl << "Price: " << content.price << endl;
	return output;
}

/**
 * @brief friend method for being able to set easily a book
 * 
 * @param content 
 * @param input 
 * 
 * @return input
 */
istream& operator >> (istream& input, Book& content){
	cout << "Book name: ";
	fflush(stdin);
	getline(cin, content.name);
	cout << "ID: ";
	input >> content.id;
	cout << "Price: ";
	input >> content.price;
	
	
	return input;	
}
