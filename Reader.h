#pragma once
#include "User.h"
#include <vector>
#include "Copy.h"

class Reader :public User
{
private:
	int maxCopies;
	int borrowPeriod;
	vector<Copy*> copiesBorrowed;
	vector<Copy*> copiesReserved;
	int penalties;

public:
	Reader();
	Reader(string userTypeIn, string usernameIn, string passwordIn, int maxCopiesIn, int borrowPeriodIn, vector<Copy*> copiesBorrowedIn, vector<Copy*> copiesReservedIn);

};
