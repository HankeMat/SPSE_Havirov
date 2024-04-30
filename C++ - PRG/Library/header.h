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
 
#ifndef HEADER_H
#define HEADER_H

//Including libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Class for book
class Book {
//Private data and methods (can be used only within the class)
private:
	string name;
	int id;
	double price;
//Public data and methods (can be used anywhere)
public:
	Book();
	friend ostream& operator << (ostream& output, Book content);
	friend istream& operator >> (istream& output, Book& content);
	string getName(){return this->name;}
	int getID(){return this->id;}
	float getPrice(){return this->price;}
	void setName(string name){this->name = name;}
	void setID(int id){this->id = id;}
	void setPrice(float price){this->price = price;}
};

//Class for library
class Library {
//Private data and methods (can be used only within the class)
private:
	Book books[100];
	int booksCount;
//Public data and methods (can be used anywhere)
public:
	Library();
	friend ostream& operator << (ostream& output, Library content);
	void addToLibrary(Book book);
	bool saveToFile(string fileName);
	bool readFromFileToDB(string fileName);
	bool findBook();
	bool sortBooks();
	bool deleteBook(int id);
	bool editBook(int id);
	double minPrice();
	double maxPrice();
};

#endif
