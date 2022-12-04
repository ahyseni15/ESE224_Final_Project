#include "User.h"
#include <iostream>


User::User()
{
	userType = "none";
	username = "none";
	password = "none";
	numBorrowed = 0;
}

User::User(string userTypeIn, string usernameIn, string passwordIn, int numBorrowedIn)
{
	userType = userTypeIn;
	username = usernameIn;
	password = passwordIn;
	numBorrowed = numBorrowedIn;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

string User::getUserType()
{
	return userType;
}

int User::getNumBorrowed()
{
	return numBorrowed;
}

void User::setNumBorrowed(int numBorrowedIn)
{
	this->numBorrowed = numBorrowedIn;
}

istream& operator>>(istream& in, User& u)
{
	string userType, username, password;
	if (!in.eof())
	{
		in >> userType;
		in >> username;
		in >> password;
	}

	u.userType = userType;
	u.username = username;
	u.password = password;

	return in;
}
