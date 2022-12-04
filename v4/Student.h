#pragma once
#include "Reader.h"

class Student :public Reader
{
	Student();
	Student(string userTypeIn, string usernameIn, string passwordIn, int maxCopiesIn, int borrowPeriodIn, vector<Copy*> copiesBorrowedIn, vector<Copy*> copiesReservedIn);
};
