#include "BST.h"
#include <fstream>
#include <vector>

BookBST::BookBST()
{
    b = Book();
    left = nullptr;
    right = nullptr;

}

BookBST::BookBST(Book bIn)
{
    b = bIn;
    left = nullptr;
    right = nullptr;
}

BookBST* BookBST::insert(BookBST* root, Book b)
{
    if (!root)
    {
        return new BookBST(b);
    }
    if (b.getISBN() > root->b.getISBN())
    {
        root->right = insert(root->right, b);
    }
    else if (b.getISBN() < root->b.getISBN())
    {
        root->left = insert(root->left, b);
    }
    return root;
}

void BookBST::inOrder(BookBST* root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->b.getTitle() << endl;
    inOrder(root->right);
}

BookBST* BookBST::search(BookBST* root, string isbn)
{
    if (root == NULL || isbn == root->b.getISBN())
    {
        return root;
    }
    if (isbn < root->b.getISBN())
    {
        return search(root->left, isbn);
    }
    if (isbn > root->b.getISBN())
    {
        return search(root->right, isbn);
    }
}

Book BookBST::searchISBN(BookBST* root, string isbn)
{
    root = search(root, isbn);
    if (root != NULL)
    {
        return root->b;
    }
    else
    {
        Book temp;
        return temp;
    }
}

UserBST::UserBST()
{
    u = User();
    left = nullptr;
    right = nullptr;

}

UserBST::UserBST(User uIn)
{
    u = uIn;
    left = nullptr;
    right = nullptr;
}

UserBST* UserBST::insert(UserBST* root, User u)
{
    if (!root)
    {
        return new UserBST(u);
    }
    if (u.getUsername() > root->u.getUsername())
    {
        root->right = insert(root->right, u);
    }
    else if (u.getUsername() < root->u.getUsername())
    {
        root->left = insert(root->left, u);
    }
    return root;
}

void UserBST::inOrder(UserBST* root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->u.getUsername() << endl;
    inOrder(root->right);
}


UserBST* UserBST::search(UserBST* root, string username)
{
    if (root == NULL || username == root->u.getUsername())
    {
        return root;
    }
    if (username < root->u.getUsername())
    {
        return search(root->left, username);
    }
    if (username > root->u.getUsername())
    {
        return search(root->right, username);
    }
}

User UserBST::searchUsername(UserBST* root, string username)
{
    root = search(root, username);
    if (root != NULL)
    {
        return root->u;
    }
    else
    {
        User temp;
        return temp;
    }
}

CopyBST::CopyBST()
{
    c = Copy();
    left = nullptr;
    right = nullptr;

}

CopyBST::CopyBST(Copy cIn)
{
    c = cIn;
    left = nullptr;
    right = nullptr;
}

CopyBST* CopyBST::insert(CopyBST* root, Copy c)
{
    if (!root)
    {
        return new CopyBST(c);
    }
    if (c.getID() > root->c.getID())
    {
        root->right = insert(root->right, c);
    }
    else if (c.getID() < root->c.getID())
    {
        root->left = insert(root->left, c);
    }
    return root;
}

vector<int> CopyBST::copiesList(CopyBST* root, string isbn)
{
    vector<int>copies;
    if (root == NULL)
    {
        return copies;
    }
    copiesList(root->left, isbn);
    if (root->c.getISBN() == isbn)
    {
        cout << c.getID() << endl;
        copies.push_back(c.getID());
    }
    copiesList(root->right, isbn);
}

CopyBST* CopyBST::search(CopyBST* root, int id)
{
    if (root == NULL || root->c.getID() == id)
    {
        return root;
    }

    if (root->c.getID() < id)
    {
        return search(root->right, id);
    }

    return search(root->left, id);
}

Copy CopyBST::searchCopy(CopyBST* root, int id)
{
    CopyBST* copyRoot = search(root, id);
    return copyRoot->c;
}