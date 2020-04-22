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



void saveInFile(BookShop bookShop)
{
	fstream outBookShop,outBook,outClient,outSaleManager;
	outBookShop.open("BookShop.txt", ios::out | ios::app);
	if (!outBookShop)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: BookShop \n"; return;
	}
	outBookShop << bookShop.getBookShopName() << "\n" <<bookShop.getAddress() ;
	outBookShop.close();


	outBook.open("Book.txt", ios::out | ios::app);
	if (!outBook)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: Book \n"; return;
	}
	for (int i = 0; i < bookShop.getCountOfBook(); i++)
	{
		outBook << bookShop.getBOOK(i).getBookName()<< "\n" << bookShop.getBOOK(i).getGenre()
			    <<"\n"<<bookShop.getBOOK(i).getBookCost() 
			    <<"\n"<< bookShop.getBOOK(i).getCountOfOneBook() <<"\n"<< bookShop.getBOOK(i).getAgeExcepion() << "\n";
	}
	outBook.close();


	outSaleManager.open("SaleManager.txt", ios::out | ios::app);
	if (!outSaleManager)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: SaleManager \n"; return;
	}
	for (int i = 0; i < bookShop.getCountOfSaleManagers(); i++)
	{
		outSaleManager << bookShop .getSaleManager(i).getSurname() << "\n" << bookShop.getSaleManager(i).getAge()
			<< "\n" << bookShop.getSaleManager(i).getPosition()
			<< "\n" << bookShop.getSaleManager(i).getSalary() << "\n";
	}
	outSaleManager.close();

	outClient.open("Client.txt", ios::out | ios::app);
	if (!outClient)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: Client \n"; return;
	}
	for (int i = 0; i < bookShop.getCountOfClient(); i++)
	{
		outClient << bookShop.getClient(i).getSurname() << "\n" << bookShop.getClient(i).getAge()
			<< "\n" << bookShop.getClient(i).getBill()
			<< "\n" << bookShop.getClient(i).getPhoneNumber() << "\n";
	}
	outClient.close();
}


