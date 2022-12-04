#pragma once
#include "Book.h"
#include <vector>

class Copy
{
private:
	string ISBN;
	int id;
	string borrowedBy;
	string reserver;
	int availableDate;
	int borrowDate;
	int expirationDate;

public:
	Copy();
	Copy(string ISBNIn, int idIn, string borrowedByIn, string reserverIn, int availableDateIn, int borrowDateIn, int expirationDateIn);

	int getID();
	string getISBN();
	string getBorrowedBy();

	void setBorrowedBy(string borrowedByIn);
	void setBorrowDate(int borrowDateIn);
	
	friend istream& operator>>(istream& in, Copy& c);
};
