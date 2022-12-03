#pragma once
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
	string ISBN;
	string title;
	string author;
	string category;
	vector<int> copyList;
	bool isAvailable;

public:
	Book();
	Book(string ISBN, string title, string author, string category, vector<int> copyListIn, bool isAvailableIn);

	static string replaceDash(string str);
	friend istream& operator>>(istream& in, Book& b);

	//get()
	string getISBN();
	string getTitle();
	string getAuthor();
	string getCategory();
	vector<int> getCopyList();

	//set()
	void setISBN(string isbnIn);
	void setTitle(string titleIn);
	void setAuthor(string authorIn);
	void setCategory(string categoryIn);
	void setCopyList(vector<int> copyListIn);
};
