#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "User.h"
#include "DateCounter.h"
#include <conio.h>
#include "Copy.h"
#include "BST.h"

using namespace std;

class LMS
{
private:
	static int totalCopies;

public:
	static bool loadCopyFile();
	static bool loadBookFile();	//load all book data from book.txt
	static bool loadStudentFile();	//load all user data from student.txt

	static User login(istream& in);	//check for login credentials

	static void bookSearch();	//search book database based on given criteria

	static void searchISBN();	//search book using isbn
	static void searchID();		//search book using id
	static void searchTitle();	//search book using title
	static void searchAuthor();	//search book using author
	static void searchCategory();	//search book using category

	static void printBookHeader();		//print the book given book index.
	static void printBook(Book b);

	static void borrowBook(string username);
	static void returnBook(string username);
	static void renewBook(string username);
	//static void reserveBook(string username);

	static void requestNewBook();
	static void deleteCopy();
	static void searchUsers();
	static void addUsers();
	static void deleteUsers();

	static string toLowerCase(string str);	//lower case user input
};
