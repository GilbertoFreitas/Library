#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string>

using namespace std;

Inventory _inventory;

void DisplayMainMenu()
{
    cout << "Choose and option:" << endl;
    cout << "1 - Add book" << endl;
    cout << "2 - List All books" << endl;
    cout << "3 - Check out book" << endl;
    cout << "4 - Check in book" << endl;
    cout << "5 - Remove book from library" << endl;
    cout << "6 - List all checked out books" << endl;

    cout << "0 - Exit" << endl;
}

void AddNewBook() 
{
    cout << "Title: ";
    string title;
    getline(cin, title);

    cout << "Author: ";
    string author;
    getline(cin, author);

    Book newBook(title, author);



    _inventory.AddBook(newBook);
}

void ListBooks()
{
    _inventory.DisplayAllBooks();
}

void CheckInOrOutBook(bool checkOut)
{
    string inOrOuT;

    if (checkOut)
    {
        inOrOuT = "out";
    }
    else
    {
        inOrOuT = "in";
    }

    cout << "Enter a book title to check " + inOrOuT + ": ";
    string title;
    getline(cin, title);

    CheckInOrOutResult result = _inventory.CheckInOrOutBook(title, checkOut);

    if (result == CheckInOrOutResult::BookNotFound)
    {
        cout << "Book not found!\n";

    }
    else if(result == CheckInOrOutResult::Success)
    {
        cout << "Book checked " + inOrOuT + "!" << endl;
    }
    else if (result == CheckInOrOutResult::AlreadyCheckedIn || result == CheckInOrOutResult::AlreadyCheckedOut)
    {
        cout << "Book already checked " + inOrOuT + "!" << endl;
    }
    else
    {
        cout << "Book failed checking" + inOrOuT + "!" << endl;
    }
}

void RemoveBook()
{
    cout << "Title: ";
    string title;
    getline(cin, title);

    _inventory.RemoveBook(title);
}

void DisplayCheckedOutBooks()
{
    _inventory.DisplayCheckOutBooks();
}


int main()
{
    while (true)
    {
        DisplayMainMenu();

        int input;

        cin >> input;
        cin.ignore();
        switch (input)
        {
        case 0:

            cout << "Thank you. Good bye!" << endl;
            return 0;

        case 1:
        {
            AddNewBook();
            break;
        }

        case 2:
        {
            ListBooks();
            break;
        }

        case 3:
        {
            CheckInOrOutBook(true);
            break;
        }

        case 4:
        {
            CheckInOrOutBook(false);
            break;
        }

        case 5:
        {
            RemoveBook();
            break;
        }

        case 6:
        {
            DisplayCheckedOutBooks();
            break;
        }

        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }
        

    }

    return 0;

}
