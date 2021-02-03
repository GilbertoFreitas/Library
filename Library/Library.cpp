#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string>

using namespace std;

Inventory _inventory;

int main()
{
    while (true)
    {
        cout << "Choose and option:" << endl;
        cout << "1 - Add book" << endl;
        cout << "2 - List All books" << endl;
        cout << "3 - Check out book" << endl;
        cout << "4 - Check in book" << endl;

        cout << "0 - Exit" << endl;

        int input;

        cin >> input;
        cin.ignore();
        switch (input)
        {
        case 0:

            return 0;

        case 1:
        {
            cout << "Title: ";
            string title;
            getline(cin, title);

            cout << "Author: ";
            string author;
            getline(cin, author);

            int id = _inventory.Books.size() + 1;

            Book newBook(id, title, author);



            _inventory.AddBook(newBook);
            break;
        }

        case 2:

            cout << "Id\tTitle\tAuthor\n\n";
            for (int i = 0; i < _inventory.Books.size(); i++) 
            {
                cout << _inventory.Books[i].Id << "\t" << _inventory.Books[i].Title << "\t" << _inventory.Books[i].Author << endl; 
            }
            break;

        case 3:
        {
            cout << "Enter a book title to check out: ";
            string title;
            getline(cin, title);
            Book foundBook;
            if (_inventory.FindBookByTitle(title, foundBook)) 
            {
                if (!foundBook.CheckedOut)
                {
                    cout << "Book already checked out!" << endl;;
                    break;
                }
                _inventory.CheckOutBook(foundBook);
                cout << "Book checked out!" << endl;
            }
            else 
            {
                cout << "Book not found" << endl;
            }

            break;
        }
        case 4:
        {
            cout << "Enter a book title to check in: ";
            string title;
            getline(cin, title);
            Book foundBook;
            if (_inventory.FindBookByTitle(title, foundBook))
            {
                if (!foundBook.CheckedOut)
                {
                    cout << "Book already checked in!";
                    break;
                }
                _inventory.CheckInBook(foundBook);
                cout << "Book checked in!" << endl;
            }
            else
            {
                cout << "Book not found";
            }

            break;
        }

        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }


    }

    return 0;

}
