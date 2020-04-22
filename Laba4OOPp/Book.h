#pragma once
#include <iostream>
#include "stdio.h"
using namespace std;

class Book
{
	char bookName[25];
	char genre[20];
	double bookCost;
	int countOfOneBook;
	int ageException;
public:
	void setBookName(char* bookName) { strcpy_s(this->bookName, bookName); }
	char* getBookName() { return bookName; }
	void setGenre(char* genre) { strcpy_s(this->genre, genre); }
	char* getGenre() { return genre; }
	void setBookCost(double bookCost) { this->bookCost = bookCost; }
	double getBookCost() { return bookCost; }
	void setCountOfOneBook(int countOfOneBook) { this->countOfOneBook = countOfOneBook; }
	int getCountOfOneBook() { return countOfOneBook; }
	void setAgeException(int ageException) { this->ageException = ageException; }
	int getAgeExcepion() { return ageException; }

	Book() {}

	Book(char bookName[25], char genre[20],double bookCost, int countOfOneBook, int ageException)
	{
		try
		{
			if (bookCost <= 0 || countOfOneBook <= 0 || ageException <= 0)
				throw new int(5);
		}
		catch (...)
		{
			cout << "\n\tException!!!Некорректное значение!!!";
			throw;
			system("pause");
		}
		strcpy_s(this->bookName, bookName);
		strcpy_s(this->genre, genre);
		this->bookCost = bookCost;
		this->countOfOneBook = countOfOneBook;
		this->ageException = ageException;
	}
	~Book()
	{	}
};

