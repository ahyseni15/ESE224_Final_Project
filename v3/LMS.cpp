#include "LMS.h"
#include "Screen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

BookBST* bookRoot = NULL;
UserBST *userRoot = NULL;
CopyBST *copyRoot = NULL;

BookBST book;
UserBST user;
CopyBST cop;

int LMS::totalCopies = 0;

bool LMS::loadCopyFile()
{
	fstream copyFile("copy.txt");
	Copy c = Copy();
	if (copyFile.is_open())
	{
		while (!copyFile.eof())
		{
			copyFile >> c;
			if (c.getID() != -1)
			{
				totalCopies++;
				copyRoot = cop.insert(copyRoot, c);
			}
		}
	}
	copyFile.close();
	return 1;
}

bool LMS::loadBookFile()
{
	fstream bookFile("book.txt");
	Book b = Book();
	if (bookFile.is_open())
	{
		while (!bookFile.eof())
		{
			bookFile >> b;
			if (b.getTitle() != "title")
			{
				cop.copiesList(copyRoot, b.getISBN());
				b.setCopyList(cop.getCopiesList());
				cop.resetCopiesList();
				bookRoot = book.insert(bookRoot, b);
			}
		}
	}
	bookFile.close();
	return 1;
}

bool LMS::loadStudentFile()
{
	fstream studentFile("student.txt");

	User u = User();
	if (studentFile.is_open())
	{
		while (!studentFile.eof())
		{
			studentFile >> u;
			if (u.getUsername() != "none")
			{
				userRoot = user.insert(userRoot, u);
			}
		}
	}
	studentFile.close();
	return 1;
}

string LMS::login(istream& in)
{
	string username, password;
	cout << "Enter your username: ";
	in >> username;
	cout << "Enter your password: ";
	char c;
	int ctr = 0;
	while ((c = _getch()) != '\r')
	{
		if (c > 32 && c < 128)
		{
			password.push_back(c);
			cout << "*";
			ctr++;
		}
		else if (c == 8 && ctr > 0)
		{
			password.erase(password.end() - 1);
			cout << "\b \b";
			ctr--;
		}
	}
	cout << endl;
	User u = user.searchUsername(userRoot, username);
	if (username == u.getUsername() && password == u.getPassword())
	{
		return u.getUsername();
	}
	return "none";
}

void LMS::bookSearch()
{
	cout << endl;
	int choice;
	cout << "Search By: " << endl;
	string choices[] = { "ISBN", "Title", "Author", "Category", "ID" };
	for (int i = 0; i < 5; i++)
	{
		cout << "\t" << i + 1 << "-" << choices[i] << endl;
	}

	cout << "Please Choose: ";
	cin >> choice;


	switch (choice)
	{
	case 1:
		searchISBN();
		break;
	case 2:
		searchTitle();
		break;
	case 3:
		searchAuthor();
		break;
	case 4:
		searchCategory();
		break;
	case 5:
		searchID();
		break;
	default:
		break;
	}

}

void LMS::searchISBN()
{
	cout << endl;
	cout << "Please enter ISBN: ";
	string isbn;
	cin >> isbn;
	int once = 0;
	cout << endl;
	Book b = book.searchISBN(bookRoot, isbn);
	if (isbn == b.getISBN())
	{
		if (once == 0)
		{
			printBookHeader();
			once = 1;
		}
		printBook(b);
	}
	else
	{
		cout << "Cannot find a book with given details." << endl;
	}
}

void LMS::searchTitle()
{
	int once = 0;
	cout << endl;
	cout << "Please enter Title: ";
	string title;
	cin.ignore();
	getline(cin, title);
	cout << endl;
	book.searchTitle(bookRoot, title);
	vector<Book> b = book.getBookList();
	for (int i = 0; i < b.size(); i++)
	{
		cout << toLowerCase(title) << endl;
		cout << toLowerCase(b[i].getTitle()) << endl;
		if (toLowerCase(title) == toLowerCase(b[i].getTitle()))
		{
			if (once == 0)
			{
				printBookHeader();
				once = 1;
			}
			printBook(b[i]);
		}
	}
	if(b.size() == 0)
	{
		cout << "Cannot find a book with given details." << endl;
	}
	book.resetBookList();
}

void LMS::searchAuthor()
{
	int once = 0;
	cout << endl;
	cout << "Please enter Author: ";
	string author;
	cin.ignore();
	getline(cin, author);
	cout << endl;
	book.searchAuthor(bookRoot, author);
	vector<Book> b = book.getBookList();
	for (int i = 0; i < b.size(); i++)
	{
		if (toLowerCase(author) == toLowerCase(b[i].getAuthor()))
		{
			if (once == 0)
			{
				printBookHeader();
				once = 1;
			}
			printBook(b[i]);
		}
	}
	if(b.size() == 0)
	{
		cout << "Cannot find a book with given details." << endl;
	}
	book.resetBookList();
}

void LMS::searchCategory()
{
	int once = 0;
	cout << endl;
	cout << "Please enter Category: ";
	string category;
	cin.ignore();
	getline(cin, category);
	cout << endl;
	book.searchCategory(bookRoot, category);
	vector<Book> b = book.getBookList();
	for (int i = 0; i < b.size(); i++)
	{
		if (toLowerCase(category) == toLowerCase(b[i].getCategory()))
		{
			if (once == 0)
			{
				printBookHeader();
				once = 1;
			}
			printBook(b[i]);
		}
	}
	if(b.size() == 0)
	{
		cout << "Cannot find a book with given details." << endl;
	}
}



void LMS::searchID()
{
	int once = 0;
	cout << "Please enter ID: ";
	int ID;
	cin >> ID;

	Copy c = cop.searchCopy(copyRoot, ID);
	string isbn = c.getISBN();
	Book b = book.searchISBN(bookRoot, isbn);
	if (isbn == b.getISBN())
	{
		if (once == 0)
		{
			printBookHeader();
			once = 1;
		}
		cout << left << setw(40) << b.getTitle() << setw(25) << b.getAuthor() << setw(25) << b.getISBN() << setw(15) << to_string(ID) << endl;
	}
	else
	{
		cout << "Cannot find a book with given details." << endl;
	}
}

void LMS::borrowBook(string username)
{
	User u = user.searchUsername(userRoot, username);
	if (u.getUserType() == "0" && u.getNumBorrowed() == 5)
	{
		cout << "You have reached maximum number of books you can borrow." << endl;
	}
	else if (u.getUserType() == "1" && u.getNumBorrowed() == 10)
	{
		cout << "You have reached maximum number of books you can borrow." << endl;
	}
	else
	{
		cout << endl;
		cout << "Please enter ID for the book you would like to borrow: ";
		int ID;
		cin >> ID;
		if (ID > totalCopies)
		{
			cout << "Cannot find a book with given details." << endl;
		}
		else
		{
			Copy c = cop.searchCopy(copyRoot, ID);
			string isbn = c.getISBN();
			Book b = book.searchISBN(bookRoot, isbn);
			if (c.getBorrowedBy() == username)
			{
				cout << "This book is already borrowed by you" << endl;
			}
			else if (c.getBorrowedBy() != "None")
			{
				cout << "This book is already borrowed by another user." << endl;
			}
			else
			{
				cout << "Total Copies = " << totalCopies << endl;
				c.setBorrowedBy(username);
				int time = DateCounter::getTime();
				c.setBorrowDate(time);
				cout << endl;
				cout << left << setw(40) << "Title" << setw(25) << "Author" << setw(25) << "ISBN" << setw(15) << "ID" << setw(15) << "Borrowed By" << endl;
				cout << left << setw(40) << b.getTitle() << setw(25) << b.getAuthor() << setw(25) << b.getISBN() << setw(15) << to_string(ID) << setw(15) << c.getBorrowedBy() << endl;
				cout << endl;
				cout << "Successfully borrowed book." << endl;
				u.setNumBorrowed(u.getNumBorrowed() + 1);
				userRoot = user.updateUser(userRoot, u);
				copyRoot = cop.updateCopy(copyRoot, c);
				cout << endl;
			}
		}
		
	}
}

void LMS::returnBook(string username)
{
	User u = user.searchUsername(userRoot, username);
	cout << endl;
	cout << "Please enter ID for the book you would like to return: ";
	int ID;
	cin >> ID;
	if (ID > totalCopies)
	{
		cout << "Cannot find a book with given details." << endl;
	}
	else
	{
		Copy c = cop.searchCopy(copyRoot, ID);
		string isbn = c.getISBN();
		Book b = book.searchISBN(bookRoot, isbn);
		if (c.getBorrowedBy() == username)
		{
			c.setBorrowDate(0);
			c.setBorrowedBy("None");
			u.setNumBorrowed(u.getNumBorrowed() - 1);
			userRoot = user.updateUser(userRoot, u);
			copyRoot = cop.updateCopy(copyRoot, c);
			cout << "Book returned successfully" << endl;
		}
		else
		{
			cout << "This book is not borrowed by you." << endl;
		}
	}
}

void LMS::renewBook(string username)
{
	User u = user.searchUsername(userRoot, username);
	cout << endl;
	cout << "Please enter ID for the book you would like to renew: ";
	int ID;
	cin >> ID;
	if (ID > totalCopies)
	{
		cout << "Cannot find a book with given details." << endl;
	}
	else
	{
		Copy c = cop.searchCopy(copyRoot, ID);
		string isbn = c.getISBN();
		Book b = book.searchISBN(bookRoot, isbn);
		if (c.getBorrowedBy() == username)
		{
			int time = DateCounter::getTime();
			c.setBorrowDate(time);
			copyRoot = cop.updateCopy(copyRoot, c);
			cout << "Book Renewed Successfully" << endl;
		}
		else
		{
			cout << "This book is not borrowed by you." << endl;
		}
	}
}

void LMS::printBookHeader()
{
	cout << left << setw(40) << "Title" << setw(25) << "Author" << setw(25) << "ISBN" << setw(15) << "ID" << endl;
}

void LMS::printBook(Book b)
{
	vector<int> temp = b.getCopyList();
	for (int i = 0; i < temp.size(); i++)
	{
		cout << left << setw(40) << b.getTitle() << setw(25) << b.getAuthor() << setw(25) << b.getISBN() << setw(15) << to_string(temp[i]) << endl;
	}
}

string LMS::toLowerCase(string str)
{
	string temp = "";
	for (char c : str)
	{
		temp += tolower(c);
	}
	return temp;
}