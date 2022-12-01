#include <iostream>
#include <fstream>
#include "Screen.h"
#include "LMS.h"

using namespace std;

int main()
{
	if (!LMS::loadBookFile())	//load books from books.txt
	{
		cout << "Error loading book file." << endl;
		exit(-1);
	}
	else if (!LMS::loadStudentFile())	//load users from student.txt
	{
		cout << "Error loading student file." << endl;
		exit(-1);
	}
	else if (!LMS::loadCopyFile())
	{
		cout << "Error loading copy file." << endl;
		exit(-1);
	}

	cout << "Opening Library Management System. . . " << endl << endl;

	string user = LMS::login(cin);	//check user authentication
	if (user == "none")
	{
		cout << endl << "Access Denied: Username and Password do not match." << endl;
		exit(-1);
	}

	Screen::welcome(user);	//welcome screen
	int choice = 1;
	while (1)
	{
		Screen::menu();	//print menu
		cout << "Please select an option: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			LMS::bookSearch();	//search book based on given criteria
			break;
		case 2:
			//LMS::borrowBook(user);	//borrow book with ID
			break;
		case 3:
			//LMS::returnBook(user);	//allows user to return borrowed book
			break;
		case 4:
			//LMS::renewBook(user);	//allows user to renew borrowed book
			break;
		case 5:
			//LMS::requestNewBook(user);	//allows teacher to request a book not in database
			break;
		case 6:
			//LMS::deleteCopy(user);	//allows teacher to delete a book from database
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}