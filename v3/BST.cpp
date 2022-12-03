#include "BST.h"
#include <fstream>


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
    BookBST* new_node = new BookBST(b);

    if (root == NULL)
    {
        root = new_node;
    }
    else if (root->b.getISBN() < b.getISBN())
    {
        root->right = insert(root->right, b);
    }
    else
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

void BookBST::searchTitle(BookBST* root, string title)
{
    if (!root)
    {
        return;
    }
    searchTitle(root->left, title);
    if (toLowerCase(root->b.getTitle()) == toLowerCase(title))
    {
        bookList.push_back(root->b);
    }
    searchTitle(root->right, title);
}

void BookBST::searchAuthor(BookBST* root, string author)
{
    if (!root)
    {
        return;
    }
    searchAuthor(root->left, author);
    if (toLowerCase(root->b.getAuthor()) == toLowerCase(author))
    {
        bookList.push_back(root->b);
    }
    searchAuthor(root->right, author);
}

void BookBST::searchCategory(BookBST* root, string category)
{
    if (!root)
    {
        return;
    }
    searchCategory(root->left, category);
    if (toLowerCase(root->b.getCategory()) == toLowerCase(category))
    {
        bookList.push_back(root->b);
    }
    searchCategory(root->right, category);
}

vector<Book> BookBST::getBookList()
{
    return bookList;
}

void BookBST::resetBookList()
{
    bookList.clear();
}

string BookBST::toLowerCase(string str)
{
    string temp = "";
    for (char c : str)
    {
        temp += tolower(c);
    }
    return temp;
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

UserBST* UserBST::deleteNode(UserBST* root, User u)
{
    if (root == NULL)
    {
        return root;
    }

    if (u.getUsername() < root->u.getUsername())
    {
        root->left = deleteNode(root->left, u);
    }
    else if (u.getUsername() > root->u.getUsername())
    {
        root->right = deleteNode(root->right, u);
    }
    else
    {
        if (root->left == NULL and root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            UserBST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            UserBST* temp = root->left;
            free(root);
            return temp;
        }
        UserBST* temp = minValueNode(root->right);
        root->u = temp->u;
        root->right = deleteNode(root->right, temp->u);
    }
    return root;
}

UserBST* UserBST::minValueNode(UserBST* node)
{
    UserBST* current = node;

    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

UserBST* UserBST::updateUser(UserBST* root, User u)
{
    root = deleteNode(root, u);
    root = insert(root, u);
    return root;
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
        root = new CopyBST(c);
    }
    if (c.getID() > root->c.getID())
    {
        root->right = insert(root->right, c);
    }
    else if(c.getID() < root->c.getID())
    {
        root->left = insert(root->left, c);
    }
    return root;
}

void CopyBST::copiesList(CopyBST* root, string isbn)
{
    if (!root)
    {
        return;
    }
    copiesList(root->left, isbn);
    if (root->c.getISBN() == isbn)
    {
        copies.push_back(root->c.getID());
    }
    copiesList(root->right, isbn);
}

vector<int> CopyBST::getCopiesList()
{
    return copies;
}

void CopyBST::resetCopiesList()
{
    copies.clear();
}

CopyBST* CopyBST::search(CopyBST* root, int id)
{
    if (root == NULL || id == root->c.getID())
    {
        return root;
    }
    if (id < root->c.getID())
    {
        return search(root->left, id);
    }
    if (id > root->c.getID())
    {
        return search(root->right, id);
    }
}

Copy CopyBST::searchCopy(CopyBST* root, int id)
{
    CopyBST* copyRoot = search(root, id);
    return copyRoot->c;
}

void CopyBST::inOrder(CopyBST* root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->c.getID() << endl;
    inOrder(root->right);
}

CopyBST* CopyBST::deleteNode(CopyBST* root, Copy c)
{
    if (root == NULL)
    {
        return root;
    }

    if (c.getID() < root->c.getID())
    {
        root->left = deleteNode(root->left, c);
    }
    else if (c.getID() > root->c.getID())
    {
        root->right = deleteNode(root->right, c);
    }
    else 
    {
        if (root->left == NULL and root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL) 
        {
            CopyBST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            CopyBST* temp = root->left;
            free(root);
            return temp;
        }
        CopyBST* temp = minValueNode(root->right);
        root->c = temp->c;
        root->right = deleteNode(root->right, temp->c);
    }
    return root;
}

CopyBST* CopyBST::minValueNode(CopyBST* node)
{
    CopyBST* current = node;

    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

CopyBST* CopyBST::updateCopy(CopyBST* root, Copy c)
{
    root = deleteNode(root, c);
    root = insert(root, c);
    return root;
}