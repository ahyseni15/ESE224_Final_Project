#pragma once
#include "User.h"

class Librarian : public User
{
	Librarian();
	Librarian(string userTypeIn, string usernameIn, string passwordIn);
};
