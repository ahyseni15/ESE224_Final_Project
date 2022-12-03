#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userType;
	string username;
	string password;
	int numBorrowed;
public:
	User();
	User(string userType, string username, string password, int numBorrowedIn);

	//get()
	string getUsername();
	string getPassword();
	string getUserType();
	int getNumBorrowed();

	void setNumBorrowed(int numBorrowedIn);
	//operator overloading
	friend istream& operator>>(istream& in, User& u);
};