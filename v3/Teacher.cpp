#include <iostream>
#include "Teacher.h"
#include "LMS.h"

Teacher::Teacher()
{
	Reader("0", "none", "none", 10, 50, vector<Copy*>(), vector<Copy*>());
}

Teacher::Teacher(string userTypeIn, string usernameIn, string passwordIn, int maxCopiesIn, int borrowPeriodIn, vector<Copy*> copiesBorrowedIn, vector<Copy*> copiesReservedIn)
{
	Reader(userTypeIn, usernameIn, passwordIn, maxCopiesIn, borrowPeriodIn, copiesBorrowedIn, copiesReservedIn);
}