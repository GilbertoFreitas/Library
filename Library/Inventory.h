#pragma once

#include "Book.h"
#include <vector>
#include "CheckInOrOutResult.h"

class Inventory
{
private:

	std::vector<Book> Books;
	int MaxBookId;
	bool checkOut;

public:


	Inventory();

	void DisplayAllBooks();
	void DisplayCheckOutBooks();
	int NumberOfBooks();
	Book GetBookByIndex(int index);
	void AddBook(Book book);
	void RemoveBook(std::string title);
	int FindBookByTitle(std::string title);
	CheckInOrOutResult CheckInOrOutBook(std::string, bool checkOut);

	
};

