#include "Librarian.h"
#include "LMS.h"
#include "iostream"

Librarian::Librarian()
{
	User("2", "admin", "admin", 0);
}

Librarian::Librarian(string userTypeIn, string usernameIn, string passwordIn)
{
	User(userTypeIn, usernameIn, passwordIn, 0);
}