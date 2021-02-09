#pragma once

#include<iostream>


class Book
{
private:
	
	std::string Title;
	std::string Author;
	bool CheckedOut;

public:
	Book();
	Book(std::string title, std::string author);

	int Id;

	void CheckInOrOut(bool checkOut);
	void DisplayBook();
	bool IsCheckedOut();
	std::string GetBookFileData();


	bool operator==(const Book& book) const
	{
		if (Title.compare(book.Title) == 0) 
			return true;
		
		else
			return false;
	}

};

