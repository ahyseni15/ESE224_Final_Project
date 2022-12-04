#include "Copy.h"
#include <iostream>
#include "LMS.h"

Copy::Copy()
{
	ISBN = "0";
	id = -1;
	//book = NULL;
	borrowedBy = "None";
	reserver = "None";
	availableDate = 0;
	borrowDate = 0;
	expirationDate = 0;
}

Copy::Copy(string ISBNIn, int idIn, string borrowedByIn, string reserverIn, int availableDateIn, int borrowDateIn, int expirationDateIn)
{
	ISBN = ISBNIn;
	id = idIn;
	//book = bookIn;
	borrowedBy = borrowedByIn;
	reserver = reserverIn;
	availableDate = availableDateIn;
	borrowDate = borrowDateIn;
	expirationDate = expirationDateIn;
}

int Copy::getID()
{
	return id;
}


string Copy::getISBN()
{
	return ISBN;
}

string Copy::getBorrowedBy()
{
	return borrowedBy;
}


void Copy::setBorrowedBy(string borrowedByIn)
{
	this->borrowedBy = borrowedByIn;
}

void Copy::setBorrowDate(int borrowDateIn)
{
	this->borrowDate = borrowDateIn;
}

istream& operator>>(istream& in, Copy& c)
{
	string isbn;
	int idIn;

	if (!in.eof())
	{
		in >> isbn;
		in >> idIn;

		c.ISBN = isbn;
		c.id = idIn;

		//c.book = Book();
		c.borrowedBy = "None";
		c.reserver = "None";
		c.availableDate = 0;
		c.borrowDate = 0;
		c.expirationDate = 0;
	}
	return in;
}