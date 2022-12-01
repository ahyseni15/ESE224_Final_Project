#include <iostream>
#include "Student.h"
#include "LMS.h"

Student::Student()
{
	Reader("0", "none", "none", 5, 30, vector<Copy*>(), vector<Copy*>());
}

Student::Student(string userTypeIn, string usernameIn, string passwordIn, int maxCopiesIn, int borrowPeriodIn, vector<Copy*> copiesBorrowedIn, vector<Copy*> copiesReservedIn)
{
	Reader(userTypeIn, usernameIn, passwordIn, maxCopiesIn, borrowPeriodIn, copiesBorrowedIn, copiesReservedIn);
}