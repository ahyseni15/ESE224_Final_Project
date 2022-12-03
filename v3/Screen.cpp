#include "Screen.h"
#include <iostream>
#include <vector>


void Screen::welcome(string user)
{
	cout << endl;
	border();
	cout << "\tWelcome to My Library!" << endl << endl;
	border();
	cout << "Welcome back, " << user << endl;
}

void Screen::border()
{
	cout << "=============================================" << endl << endl;
}

void Screen::menu()
{
	cout << endl;
	vector<string> options = { "Search for Books", "Borrow Books", "Return Books", "Renew Books", "Request a new book copy", "Delete an exisiting copy", "Log Out" };

	for (int i = 0; i < options.size(); i++)
	{
		if (i == 0)
		{
			cout << "Please Choose:" << endl;
		}
		if (i < options.size() - 1)
		{
			cout << "\t" << i + 1 << " -- " << options[i] << endl;
		}
		else
		{
			cout << "\t" << "0 -- " << options[i] << endl;
		}
	}
}