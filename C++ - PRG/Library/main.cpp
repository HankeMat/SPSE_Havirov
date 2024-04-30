/**
 * @file main.cpp
 * @author Hanke Matěj (hanke.matej@seznam.cz)
 * @brief User interface for program that represents book database
 * @version 0.1
 * @date 2023-04-15
 * 
 * @copyright Copyright Hanke Matěj (c) 2023
 * 
 */

//Linking header file
#include "header.h"

int main() {
	//Basic declaration
	int decision, id;
	double minimum, maximum;
	bool check;
	Library mainLibrary;
	Book newBook;
	string filename;
	
	//User interface for calling our methods
	do{
		cout << "0 - EXIT" << endl;
		cout << "1 - Add a book to library" << endl;
		cout << "2 - Print all books from library" << endl;
		cout << "3 - Find a book in library" << endl;
		cout << "4 - Sort books in library by its ID" << endl;
		cout << "5 - Save books into file" << endl;
		cout << "6 - Load books from file" << endl;
		cout << "7 - Delete book by its ID" << endl;
		cout << "8 - Edit book by its ID" << endl;
		cout << "9 - Lowest price in library" << endl;
		cout << "10 - Highest price in library" << endl;
		
		cout << "Your decision: ";
		cin >> decision;
		
		switch (decision) {
		case 0:
			cout << "Thanks for using me :-)" << endl;
			system("pause");
			break;
		case 1:
			cin >> newBook;
			mainLibrary.addToLibrary(newBook);
			cout << "Book has been added to a library" << endl;	
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "=====Print all books=====" << endl;
			cout << mainLibrary;
			cout << "=========================" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			check = mainLibrary.findBook();
			if(true == check){
				cout << "Book found!" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 4:
			check = mainLibrary.sortBooks();
			if(true == check){
				cout << "Books has been sorted" << endl;
			}else if(false == check){
				cout << "There is no books/Books are already sorted" << endl;	
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Enter file name: ";
			fflush(stdin);
			getline(cin, filename);
			check = mainLibrary.saveToFile(filename);
			if(true == check){
				cout << "Save successfull" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Enter file name: ";
			fflush(stdin);
			getline(cin, filename);
			check = mainLibrary.readFromFileToDB(filename);
			if(true == check){
				cout << "Load successfull" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Enter books ID: ";
			cin >> id;
			check = mainLibrary.deleteBook(id);
			if(true == check){
				cout << "Book deleted" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "Enter books ID: ";
			cin >> id;
			check = mainLibrary.editBook(id);
			if(true == check){
				cout << "Book edited" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 9:
			minimum = mainLibrary.minPrice();	
			cout << "Lowest price in the library is " << minimum << ",-" << endl;
			system("pause");
			system("cls");
			break;
		case 10:
			maximum = mainLibrary.maxPrice();	
			cout << "Highest price in the library is " << maximum << ",-" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "There is no such option" << endl;
			system("pause");
			system("cls");
			break;
		}
		
		
	}while(decision != 0);
	
	return 0;
}
