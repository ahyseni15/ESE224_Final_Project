#include "LMS.h"
#include "Screen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

BookBST* bookRoot = nullptr;
UserBST *userRoot = nullptr;
CopyBST *copyRoot = nullptr;

BookBST book;
UserBST user;
CopyBST cop;

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
				b.setCopyList(cop.copiesList(copyRoot, b.getISBN()));
				vector<int> temp = b.getCopyList();
				//cout << temp.size();
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
	int check = 0, once = 0;

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
	int check = 0, once = 0;
	cout << endl;
	cout << "Please enter Title: ";

	string title;
	cin.ignore();
	getline(cin, title);
	cout << endl;

	/*for (int i = 0; i < books.size(); i++)
	{
		if (toLowerCase(books[i].getTitle()) == toLowerCase(title))
		{
			if (once == 0)
			{
				printBookHeader();
				once = 1;
			}
			printBook(i);
			check = 1;
		}
	}*/

	if (check == 0)
	{
		cout << "Cannot find a book with given details." << endl;
	}
}

void LMS::searchAuthor()
{
	int check = 0, once = 0;
	cout << endl;
	cout << "Please enter Author: ";

	string author;
	cin.ignore();
	getline(cin, author);


	cout << endl;

	/*for (int i = 0; i < books.size(); i++)
	{
		if (toLowerCase(books[i].getAuthor()) == toLowerCase(author))
		{
			if (once == 0)
			{
				printBookHeader();
				once = 1;
			}
			printBook(i);
			check = 1;
		}
	}*/

	if (check == 0)
	{
		cout << "Cannot find a book with given details." << endl;
	}
}

void LMS::searchCategory()
{
	int check = 0, once = 0;
	cout << endl;
	cout << "Please enter Category: ";

	string category;
	cin.ignore();
	getline(cin, category);


	cout << endl;

	/*for (int i = 0; i < books.size(); i++)
	{
		if (toLowerCase(books[i].getCategory()) == toLowerCase(category))
		{
			if (once == 0)
			{
				printBookHeader();
				once = 1;
			}
			printBook(i);
			check = 1;
		}
	}*/

	if (check == 0)
	{
		cout << "Cannot find a book with given details." << endl;
	}
}



void LMS::searchID()
{
	cout << "Please enter ID: ";
	int ID;
	cin >> ID;

	/*int index = binarySearch(ID);
	cout << endl;
	if (index != -1)
	{
		printBookHeader();
		printBook(index);
	}*/
}

void LMS::printBookHeader()
{
	cout << left << setw(40) << "Title" << setw(25) << "Author" << setw(25) << "ISBN" << setw(15) << "ID" << endl;
}

void LMS::printBook(Book b)
{
	vector<int> temp = b.getCopyList();
	cout << temp.size() << endl;
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