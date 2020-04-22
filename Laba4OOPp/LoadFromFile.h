#pragma once
#include <iostream>
#include "stdio.h"
#include "Man.h"
#include "Client.h"
#include "Book.h"
#include "BookShop.h"
#include "BookCountException.h"
#include "ClientException.h"
#include "GenreException.h"
#include "SaleManagerCountPositionException.h"
#include "fstream"
using namespace std;

void loadFromFile(BookShop *bookShop)
{
	Book bookTmp;
	Client clientTmp;
	char name[20],genre[20],bookName[25],position[25],phoneNumber[15];
	double bookCost,salary,bill;
	int countOfOneBook,ageException,counterBook=0,age,counterSaleManagers=0,counterClient = 0;
	fstream inBookShop, inBook, inClient, inSaleManager;
	inBookShop.open("BookShop.txt", ios::in);
	if (!inBookShop)
	{
		cerr << "\n\t\t  LOAD:Error - Couldn't open file: BookShop \n"; return;
	}
	inBookShop >> name;
	(*bookShop).setBookShopName(name);
	inBookShop >> name;
	(*bookShop).setAddress(name);
	system("pause");
	inBookShop.close();


	inBook.open("Book.txt", ios::in);
	if (!inBook)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: Book \n"; return;
	}
	while (!inBook.eof())
	{
		inBook >> bookName;
		bookTmp.setBookName(bookName);
		inBook >> genre;
		bookTmp.setGenre(genre);
		inBook >> bookCost;
		bookTmp.setBookCost(bookCost);
		inBook >> countOfOneBook;
		bookTmp.setCountOfOneBook(countOfOneBook);
		inBook >> ageException;
		bookTmp.setAgeException(ageException);
		(*bookShop).setBook(counterBook, bookTmp);
		counterBook++;
		(*bookShop).setCountOfBook(counterBook);
	}
	inBook.close();

	inSaleManager.open("SaleManager.txt", ios::in);
	if (!inSaleManager)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: SaleManager \n"; return;
	}
	while (!inSaleManager.eof())
	{
		strcpy_s(name, ""); age = 0; strcpy_s(position, ""); salary = 0;
		inSaleManager >> name;
		inSaleManager >> age;
		inSaleManager >> position;
		inSaleManager >> salary;
		if (strcmp(name,"")==0 && age == 0 && strcmp(position, "") == 0 && salary == 0) { continue; }
		(*bookShop).variableSetSaleManager(counterSaleManagers, name, age, position, salary);
		counterSaleManagers++;
		(*bookShop).setCountOfSaleManagers(counterSaleManagers);
	}
	inSaleManager.close();
	
	inClient.open("Client.txt", ios::in);
	if (!inClient)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: Client \n"; return;
	}

	while (!inClient.eof())
	{
		strcpy_s(name, ""); age = 0; bill=0; strcpy_s(phoneNumber,"");
		inClient >> name;
		clientTmp.setSurname(name);
		inClient >> age;
		clientTmp.setAge(age);
		inClient >> bill;
		clientTmp.setBill(bill);
		inClient >> phoneNumber;
		clientTmp.setPhoneNumber(phoneNumber);
		if (strcmp(name, "") == 0 && age == 0 && bill==0 && strcmp(phoneNumber, "") == 0) { continue; }
		(*bookShop).setClient(counterClient, clientTmp);
		counterClient++;
		(*bookShop).setCountOfClient(counterClient);
	}
	inClient.close();

}