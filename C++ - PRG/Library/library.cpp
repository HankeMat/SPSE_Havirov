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
Library::Library(){
	this->booksCount = 0;
}

/**
 * @brief friend method for << to be able to easily print entire library
 * 
 * @param content 
 * @param output 
 * 
 * @return output
 */
ostream& operator << (ostream& output, Library content){	
	for(int i=0;i<content.booksCount;i++){ //loop that goes through entire library
		//Printing current book
		output << "==============" << endl << "Book #" << i+1 << ": " << content.books[i].getName() << endl << "ID: " << content.books[i].getID() << endl << "Price: " << content.books[i].getPrice() << endl;
	}
	return output;
}

/**
 * @brief method for adding a book into library
 * 
 * @param book 
 */
void Library::addToLibrary(Book book){	
	this->books[booksCount] = book;	//adds book into new place
	this->booksCount++;				//Increment book count
}

/**
 * @brief method for saving current library books into file
 * 
 * @param fileName 
 * 
 * @return true if OK, false if error
 */
bool Library::saveToFile(string fileName){
	//File variable declaration
	ofstream file;
	//File opening
	file.open(fileName, ios::app);
	//Error message
	if(file.fail()){
		cout << "Problem occured while opening the file" << endl;
		return false;
	}
	
	//Loop goes through the whole library
	for(int i=0;i<this->booksCount;i++){
		//Writing current book into the file by each element of the book divided by '|'
		file << this->books[i].getID() << "|" << this->books[i].getName() << "|" << this->books[i].getPrice() << "|" << endl;
	}
	
	//Closing file
	file.close();
	return true;
}

/**
 * @brief method for loading data from file
 * 
 * @param fileName 
 * 
 * @return true if OK, false if error
 */
bool Library::readFromFileToDB(string fileName){
	//Declaration and inicialization
	ifstream file;
	string word;
	int j = 0, i = 0, id;
	double price;
	//Opening teh file
	file.open(fileName);
	
	//Error message
	if(file.fail()){
		cout << "Problem occured while opening the file" << endl;
		return false;
	}
	
	//Reading the file by lines and deviding them into words by '|'.
	while(getline(file, word, '|')){
		if(i == 0){		//If we read ID
			id = stoi(word);	//Converting read string into int
			this->books[j].setID(id);	//Setting new value in the library
		}else if(i == 1){	//If we read name
			this->books[j].setName(word);	//Setting new value in the library
		}else if(i == 2){	//If we read price
			price = stod(word);	//Converting read string into double
			this->books[j].setPrice(price);	//Setting new value in the library
			getline(file, word);
		}
		i++; //Incrementing i for new word
		
		if(i > 2){	//If we read whole book
			i = 0;	//Return value of i back to zero
			j++;	//Next book
			this->booksCount += 1;	//Increment book count
		}
	}
	
	//Closing file
	file.close();
	return true;
}

/**
 * @brief method that find a book in a library based on whatever the user wants
 * 
 * @return true if found, false if not found
 */
bool Library::findBook(){
	//Basic declaration
	int deci;	
	string name;
	//Menu
	cout << "1 - ID" << endl;
	cout << "2 - Name" << endl;
	cout << "3 - Price" << endl;
	cout << "Search for a book by: ";
	cin >> deci;
	
	//Condition based on users input
	switch (deci) {
	case 1:
		//Looking for a book by its ID
		int id;
		cout << "Enter books ID: ";
		cin >> id;
		for(int i=0;i<this->booksCount;i++){
			if(this->books[i].getID() == id){
				cout << this->books[i] << endl;
				return true;
			}
		}	
		break;
	case 2:
		//Looking for a book by its Name
		cout << "Enter books name: ";
		fflush(stdin);
		getline(cin, name);
		for(int i=0;i<this->booksCount;i++){
			if(this->books[i].getName() == name){
				cout << this->books[i] << endl;
				return true;
			}
		}	
		break;
	case 3:
		//Looking for a book by its Price
		double price;
		cout << "Enter books price: ";
		cin >> price;
		for(int i=0;i<this->booksCount;i++){
			if(this->books[i].getPrice() == price){
				cout << this->books[i] << endl;
				return true;
			}
		}	
		break;
	default:
		//Error message if user enters invalid value
		cout << "There is no such option" << endl;
		return false;
		break;
	}

	//Error message if there is no such book
	cout << "This book was not found" << endl;
	return false;
}

/**
 * @brief method for sorting books in library based on their IDs
 * 
 * @return true if OK, false if error
 */
bool Library::sortBooks(){
	int swap = 0;
	for(int i=0;i<this->booksCount - 1;i++){	//Loop goes through the whole library
		if(this->books[i].getID() > this->books[i+1].getID()){	//Condition whether current book has higher ID than next one
			Book temp;		//Declaration temporary book
			temp = this->books[i+1];	//Swap current and next book
			this->books[i+1] = this->books[i];
			this->books[i] = temp;
			swap++;		//Increment check variable 
			i=0;		//Go from the begining
		}
	}
	
	//Error message
	if(swap > 0){
		return true;
	}
	return false;
}

/**
 * @brief method for deleting book from the library
 * 
 * @param id 
 * 
 * @return true if OK, false if error
 */
bool Library::deleteBook(int id){
	
	for(int i=0;i<this->booksCount;i++){		//Loop goes through the whole library
		if(this->books[i].getID() == id){		//Condition whether our chosen ID is similar to the current books ID
			for(int j = i;j<this->booksCount - 1;j++){	//Loop that shifts all the books from this point one position before
				this->books[j] = this->books[j+1];		
			}
			this->booksCount -= 1;				//Decrementing the number of books in the library
			return true;
		}
	}
	//Error message
	cout << "Book was not found" << endl;
	return false;
}

/**
 * @brief method that edits a book that is already in database
 * 
 * @param id 
 * 
 * @return true if ok, false if error
 */
bool Library::editBook(int id){
	
	for(int i=0;i<this->booksCount;i++){	//Loop goes through the whole library
		if(this->books[i].getID() == id){	//Condition whether our chosen ID is similar to the current books ID
			//Declaration of used variables
			int nid;						
			string name;
			double price;
			//Changing old values to new values 
			cout << "Enter new ID: ";
			cin >> nid;
			this->books[i].setID(nid);
			cout << "Enter new Name: ";
			fflush(stdin);
			getline(cin, name);
			this->books[i].setName(name);
			cout << "Enter new Price: ";
			cin >> price;
			this->books[i].setPrice(price);
			return true; //Returns here if everything was OK
		}
	}
	
	//Error message
	cout << "Book was not found" << endl;
	return false;
}

/**
 * @brief method for finding the lowest price in the library
 * 
 * @return min
 */
double Library::minPrice(){
	double min = this->books[0].getPrice(); 	//Setting default value for min
	for(int i=0;i<this->booksCount;i++){		//Loop goes through the whole library
		if(min > this->books[i].getPrice()){	//Condition whether current book has lower price than the min value
			min = this->books[i].getPrice();	//Updating the min value
			i = 0;								//Start from begining (just making sure)
		} 
	}
	return min;
}

/**
 * @brief method for finding the highest price in the library
 * 
 * @return max
 */
double Library::maxPrice(){
	double max = this->books[0].getPrice(); 	//Setting default value for max
	for(int i=0;i<this->booksCount;i++){		//Loop goes through the whole library 
		if(max < this->books[i].getPrice()){	//Condition whether current book has greater price than the max value
			max = this->books[i].getPrice();	//Updating the max value
			i = 0;								//Start from begining (just making sure)
		} 
	}
	return max;
}
