#pragma once
#include "Reader.h"

class Teacher :public Reader
{
	Teacher();
	Teacher(string userTypeIn, string usernameIn, string passwordIn, int maxCopiesIn, int borrowPeriodIn, vector<Copy*> copiesBorrowedIn, vector<Copy*> copiesReservedIn);
};

