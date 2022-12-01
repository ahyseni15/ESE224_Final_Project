#include "User.h"
#include <iostream>


User::User()
{
	userType = "none";
	username = "none";
	password = "none";
}

User::User(string userTypeIn, string usernameIn, string passwordIn)
{
	userType = userTypeIn;
	username = usernameIn;
	password = passwordIn;
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
