#pragma once

#include "Book.h"
#include <vector>
#include "CheckInOrOutResult.h"

class Inventory
{
private:

	std::vector<Book> Books;
	

public:


	void DisplayAllBooks();
	void DisplayCheckOutBooks();
	int NumberOfBooks();
	Book GetBookByIndex(int index);
	void LoadBooks();
	void AddBook(Book book);
	void RemoveBook(std::string title);
	int FindBookByTitle(std::string title);
	CheckInOrOutResult CheckInOrOutBook(std::string, bool checkOut);

	
};

