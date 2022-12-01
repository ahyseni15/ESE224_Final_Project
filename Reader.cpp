#include "Reader.h"
#include <iostream>
#include "LMS.h"

Reader::Reader()
{
	User();
	maxCopies = 0;
	borrowPeriod = 0;
	copiesBorrowed = vector<Copy*>();
	copiesReserved = vector<Copy*>();
	penalties = 0;
}

Reader::Reader(string userTypeIn, string usernameIn, string passwordIn, int maxCopiesIn, int borrowPeriodIn, vector<Copy*> copiesBorrowedIn, vector<Copy*> copiesReservedIn)
{
	User(userTypeIn, usernameIn, passwordIn);
	maxCopies = maxCopiesIn;
	borrowPeriod = borrowPeriodIn;
	copiesBorrowed = copiesBorrowedIn;
	copiesReserved = copiesReservedIn;
	penalties = 0;
}
