#include "header.h"


int main() {
	//Declaration
	Fraction fr1, fr2, fr3;
	int decision;
	
	//User interface
	do{
		cout << "0 - EXIT" << endl;
		cout << "1 - Set a fraction" << endl;
		cout << "2 - Print a fraction" << endl;
		cout << "3 - Total of two fractions" << endl;
		cout << "4 - Difference between two fractions" << endl;
		cout << "5 - Multiple two fractions" << endl;
		cout << "6 - Devide two fractions" << endl;
		cout << "7 - Compare two fractions" << endl;
		
		cout << "Your decision: ";
		cin >> decision;

		system("cls");
		switch (decision) {
		case 1:
			cin >> fr1;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << fr1 << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cin >> fr2;
			cout << fr2 << endl;
			cin >> fr3;
			cout << fr3 << endl;
			cout << fr2 << " + " << fr3 << " = " << fr2 + fr3 << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cin >> fr2;
			cout << fr2 << endl;
			cin >> fr3;
			cout << fr3 << endl;
			cout << fr2 << " - " << fr3 << " = " << fr2 - fr3 << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cin >> fr2;
			cout << fr2 << endl;
			cin >> fr3;
			cout << fr3 << endl;
			cout << fr2 << " * " << fr3 << " = " << fr2 * fr3 << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			cin >> fr2;
			cout << fr2 << endl;
			cin >> fr3;
			cout << fr3 << endl;
			cout << fr2 << " / " << fr3 << " = " << fr2 / fr3 << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cin >> fr2;
			cout << fr2 << endl;
			cin >> fr3;
			cout << fr3 << endl;
			if(fr2.compareWith(fr3) == -1){
				cout << fr2 << " < " << fr3 << endl;
			}else if(fr2.compareWith(fr3) == 1){
				cout << fr2 << " > " << fr3 << endl;
			}else if(fr2.compareWith(fr3) == 0){
				cout << fr2 << " = " << fr3 << endl;
			}else{
				cout << "Something went seriously bad :D" << endl;	
			}
			system("pause");
			system("cls");
			break;
		default:
			cout << "Missclick? (There is no such option)" << endl;
			system("pause");
			system("cls");
			break;
		}
	}while(decision != 0);
	
	return 0;
}
