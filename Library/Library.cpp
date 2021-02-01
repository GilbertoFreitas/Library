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

            break;

        case 3:

            break;

        case 4:

            break;

        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }


    }

    return 0;

}
