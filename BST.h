#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "User.h"
#include "Copy.h"

using namespace std;

class BookBST
{
private:
    Book b;
    BookBST *left, *right;
public:
    BookBST();
    BookBST(Book bIn);
    BookBST* insert(BookBST* root, Book book);
    void inOrder(BookBST* root);
    BookBST* search(BookBST* root, string ISBN);
    Book searchISBN(BookBST* root, string ISBN);
};

class UserBST
{
private:
    User u;
    UserBST* left, * right;
public:
    UserBST();
    UserBST(User uIn);
    UserBST* insert(UserBST* root, User user);
    void inOrder(UserBST* root);
    UserBST* search(UserBST* root, string username);
    User searchUsername(UserBST* root, string username);
};

class CopyBST
{
private:
    Copy c;
    CopyBST* left, * right;
public:
    CopyBST();
    CopyBST(Copy cIn);
    CopyBST* insert(CopyBST* root, Copy copy);
    vector<int> copiesList(CopyBST* root, string isbn);
    CopyBST* search(CopyBST* root, int id);
    Copy searchCopy(CopyBST* root, int id);
};