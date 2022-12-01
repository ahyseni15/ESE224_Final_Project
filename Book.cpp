#include <iostream>
#include "Book.h"

Book::Book()
{
	ISBN = "0";
	title = "title";
	author = "author";
	category = "category";
	vector<int>copyList = { 0 };
}

Book::Book(string ISBNIn, string titleIn, string authorIn, string categoryIn, vector<int> copyListIn)
{
	ISBN = ISBNIn;
	title = titleIn;
	author = authorIn;
	category = categoryIn;
	copyList = copyListIn;
}

string Book::getISBN()
{
	return ISBN;
}

string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author;
}

string Book::getCategory()
{
	return category;
}

vector<int> Book::getCopyList()
{
	return copyList;
}

void Book::setISBN(string isbnIn)
{
	this->ISBN = isbnIn;
}

void Book::setTitle(string titleIn)
{
	this->title = titleIn;
}

void Book::setAuthor(string authorIn)
{
	this->author = authorIn;
}

void Book::setCategory(string categoryIn)
{
	this->category = categoryIn;
}

void Book::setCopyList(vector<int> copyListIn)
{
	this->copyList = copyListIn;
}

istream& operator>>(istream& in, Book& b)
{
	string isbn, title, author, category;

	if (!in.eof())
	{
		in >> isbn;
		in >> title;
		title = Book::replaceDash(title);
		in >> author;
		author = Book::replaceDash(author);
		in >> category;
		category = Book::replaceDash(category);

		b.ISBN = isbn;
		b.title = title;
		b.author = author;
		b.category = category;
	}
	return in;
}

string Book::replaceDash(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{

			str[i] = ' ';
		}
	}
	return str;
}