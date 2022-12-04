#include <iostream>
#include <fstream>
#include "Screen.h"
#include "LMS.h"

using namespace std;

int main()
{
	
	if (!LMS::loadCopyFile())	//load books from books.txt
	{
		cout << "Error loading copy file." << endl;
		exit(-1);
	}
	else if (!LMS::loadStudentFile())	//load users from student.txt
	{
		cout << "Error loading student file." << endl;
		exit(-1);
	}
	else if (!LMS::loadBookFile())
	{
		cout << "Error loading book file." << endl;
		exit(-1);
	}

	cout << "Opening Library Management System. . . " << endl << endl;

	User u = LMS::login(cin);	//check user authentication
	if (u.getUsername() == "none")
	{
		cout << endl << "Access Denied: Username and Password do not match." << endl;
		exit(-1);
	}

	Screen::welcome(u.getUsername());	//welcome screen
	int choice = 1;
	while (u.getUserType() == "0" || u.getUserType() == "1")
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
			LMS::borrowBook(u.getUsername());	//borrow book with ID
			break;
		case 3:
			LMS::returnBook(u.getUsername());	//allows user to return borrowed book
			break;
		case 4:
			LMS::renewBook(u.getUsername());	//allows user to renew borrowed book
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

	while (u.getUserType() == "2")
	{
		Screen::LibrarianMenu();	//print menu
		cout << "Please select an option: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			LMS::requestNewBook();
			break;
		case 2:
			LMS::deleteCopy();	//borrow book with ID
			break;
		case 3:
			LMS::searchUsers();	//allows user to return borrowed book
			break;
		case 4:
			LMS::addUsers();	//allows user to renew borrowed book
			break;
		case 5:
			LMS::deleteUsers();	//allows teacher to request a book not in database
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