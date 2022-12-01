#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userType;
	string username;
	string password;
public:
	User();
	User(string userType, string username, string password);

	//get()
	string getUsername();
	string getPassword();
	string getUserType();

	//operator overloading
	friend istream& operator>>(istream& in, User& u);
};