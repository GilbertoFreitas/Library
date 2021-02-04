#pragma once

#include "Book.h"
#include <vector>

class Inventory
{
private:

	std::vector<Book> Books;
	int MaxBookId;

public:


	Inventory();

	int NumberOfBooks();
	Book* GetBookByIndex(int index);
	void AddBook(Book book);
	void RemoveBook(std::string title);
	int FindBookByTitle(std::string title);
	void CheckOutBook(Book* book);
	void CheckInBook(Book* book);
	
};

