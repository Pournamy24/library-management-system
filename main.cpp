#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;
};

Book books[100];
int total = 0;

void loadBooks()
{
    ifstream file("books.txt");
    total = 0;

    while (file >> books[total].id >> books[total].title >> books[total].author >> books[total].issued)
    {
        total++;
    }

    file.close();
}

void saveBooks()
{
    ofstream file("books.txt");

    for (int i = 0; i < total; i++)
    {
        file << books[i].id << " "
             << books[i].title << " "
             << books[i].author << " "
             << books[i].issued << endl;
    }

    file.close();
}

void addBook()
{
    cout << "\nEnter Book ID: ";
    cin >> books[total].id;

    cout << "Enter Book Title: ";
    cin >> books[total].title;

    cout << "Enter Author: ";
    cin >> books[total].author;

    books[total].issued = false;
    total++;

    saveBooks();

    cout << "\nBook Added Successfully!\n";
}

void displayBooks()
{
    if (total == 0)
    {
        cout << "\nNo Books Available.\n";
        return;
    }

    cout << "\n----- BOOK LIST -----\n";

    for (int i = 0; i < total; i++)
    {
        cout << "\nBook ID : " << books[i].id << endl;
        cout << "Title   : " << books[i].title << endl;
        cout << "Author  : " << books[i].author << endl;

        if (books[i].issued)
            cout << "Status  : Issued\n";
        else
            cout << "Status  : Available\n";
    }
}

void issueBook()
{
    int id;

    cout << "\nEnter Book ID: ";
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].issued)
            {
                cout << "Book Already Issued.\n";
            }
            else
            {
                books[i].issued = true;
                saveBooks();
                cout << "Book Issued Successfully.\n";
            }
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void returnBook()
{
    int id;

    cout << "\nEnter Book ID: ";
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (books[i].id == id)
        {
            if (!books[i].issued)
            {
                cout << "Book is already available.\n";
            }
            else
            {
                books[i].issued = false;
                saveBooks();
                cout << "Book Returned Successfully.\n";
            }
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void searchTitle()
{
    string title;

    cout << "\nEnter Title: ";
    cin >> title;

    for (int i = 0; i < total; i++)
    {
        if (books[i].title == title)
        {
            cout << "\nBook Found\n";
            cout << "ID: " << books[i].id << endl;
            cout << "Author: " << books[i].author << endl;
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void searchAuthor()
{
    string author;
    bool found = false;

    cout << "\nEnter Author: ";
    cin >> author;

    for (int i = 0; i < total; i++)
    {
        if (books[i].author == author)
        {
            cout << "\nBook ID: " << books[i].id << endl;
            cout << "Title: " << books[i].title << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No Books Found.\n";
}

int main()
{
    loadBooks();

    int choice;

    while (true)
    {
        cout << "\n=============================\n";
        cout << " LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=============================\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search by Title\n";
        cout << "6. Search by Author\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            issueBook();
            break;

        case 4:
            returnBook();
            break;

        case 5:
            searchTitle();
            break;

        case 6:
            searchAuthor();
            break;

        case 7:
            cout << "\nThank You!\n";
            return 0;

        default:
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}