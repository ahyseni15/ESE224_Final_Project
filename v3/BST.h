#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "User.h"
#include "Copy.h"
#include <vector>

using namespace std;

class BookBST
{
private:
    Book b;
    BookBST *left, *right;
    vector<Book> bookList;

public:
    BookBST();
    BookBST(Book bIn);
    BookBST* insert(BookBST* root, Book book);
    void inOrder(BookBST* root);
    BookBST* search(BookBST* root, string ISBN);
    Book searchISBN(BookBST* root, string ISBN);
    void searchTitle(BookBST* BST, string title);
    vector<Book> getBookList();
    void resetBookList();
    void searchAuthor(BookBST* BST, string author);
    void searchCategory(BookBST* BST, string category);
    string toLowerCase(string str);
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
    UserBST* updateUser(UserBST* root, User u);
    UserBST* deleteNode(UserBST* root, User u);
    UserBST* minValueNode(UserBST* node);
};

class CopyBST
{
private:
    Copy c;
    CopyBST* left, * right;
    vector<int>copies;
    
public:
    CopyBST();
    CopyBST(Copy cIn);
    CopyBST* insert(CopyBST* root, Copy copy);
    void copiesList(CopyBST* root, string isbn);
    CopyBST* search(CopyBST* root, int id);
    Copy searchCopy(CopyBST* root, int id);
    void inOrder(CopyBST* root);
    CopyBST* deleteNode(CopyBST* root, Copy c);
    CopyBST* minValueNode(CopyBST* node);
    CopyBST* updateCopy(CopyBST* root, Copy c);

    vector<int> getCopiesList();
    void resetCopiesList();
};