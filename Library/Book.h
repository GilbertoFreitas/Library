#pragma once

#include<iostream>


class Book
{
private:
	int Id;
	std::string Title;
	std::string Author;
	bool CheckedOut;

public:
	Book();
	Book(std::string title, std::string author);

	bool operator==(const Book& book) const
	{
		if (Title.compare(book.Title) == 0) 
			return true;
		
		else
			return false;
	}

};

