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
    cout << "Id\tTitle\tAuthor\n\n";
    for (int i = 0; i < _inventory.NumberOfBooks(); i++)
    {
        cout << _inventory.GetBookByIndex(i)->Id << "\t" << _inventory.GetBookByIndex(i)->Title << "\t" << _inventory.GetBookByIndex(i)->Author << endl;
    }
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

    int foundBookIndex = _inventory.FindBookByTitle(title);

    if (foundBookIndex >= 0)
    {
        Book* foundBook = _inventory.GetBookByIndex(foundBookIndex);

        //if checkedOut == false -> Book checked in
        //if checkedOut == True -> Book checked out

        if (foundBook->CheckedOut == checkOut)
        {
            cout << "Book already checked " + inOrOuT << endl;;
            return;
        }

        if (checkOut) 
        {
            _inventory.CheckInBook(foundBook);
        }
        else
        {
            _inventory.CheckOutBook(foundBook);
        }
        
        cout << "Book checked " + inOrOuT + "!" << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }

    return;
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
    cout << "\nId\tTitle\tAuthor" << endl;
    for (int i = 0; i < _inventory.NumberOfBooks(); i++)
    {
        if (_inventory.GetBookByIndex(i)->CheckedOut)
        {
            cout << _inventory.GetBookByIndex(i)->Id << "\t" << _inventory.GetBookByIndex(i)->Title << "\t" << _inventory.GetBookByIndex(i)->Author << endl;
        }
    }
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
            CheckInOrOutBook(false);
            break;
        }

        case 4:
        {
            CheckInOrOutBook(true);
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
