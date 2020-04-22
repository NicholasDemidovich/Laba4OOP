#pragma once
#include <iostream>
#include "stdio.h"
#include "Man.h"
#include "Client.h"
#include "Book.h"
using namespace std;



class BookShop
{
    class SaleManager :public Man
	{
		char position[25];
		double salary;
	public:
		void setPosition(char* position) { strcpy_s(this->position, position); }
		char* getPosition() { return position; }
		void setSalary(double salary) { this->salary = salary; }
		double getSalary() { return salary; }
	};
	//Book bookMass[100];
	Book *bookMass = new Book[100];
	//SaleManager saleManagerMass[5];
	SaleManager *saleManagerMass = new SaleManager[5];
	//Client clientMass[10];
	Client *clientMass = new Client[10];

	int countOfSaleManagers;
	int countOfClients;
	int countOfBook;

	char bookShopName[30];
	char address[20];
public:
	SaleManager saleTmp;
	void setBookShopName(char* bookShopName) { strcpy_s(this->bookShopName, bookShopName); }
	char* getBookShopName() { return bookShopName; }
	void setAddress(char* address) { strcpy_s(this->address, address); }
	char* getAddress() { return address; }
	void setCountOfSaleManagers(int countOfSaleManagers) { this->countOfSaleManagers = countOfSaleManagers; }
	int getCountOfSaleManagers() { return countOfSaleManagers; }
	void setCountOfClient(int countOfClients) { this->countOfClients = countOfClients; }
	int getCountOfClient() { return countOfClients; }
	void setCountOfBook(int countOfBook) { this->countOfBook = countOfBook; }
	int getCountOfBook() { return countOfBook; }

	void inputSaleManager();

	void showSSSaleManagers(BookShop* shop);

	void deleteSSSaleManeger(BookShop* shop);


	void addCountBook(Book book)
	{
		bookMass[countOfBook] = book;
		countOfBook++;
	}

	SaleManager getSaleManager(int i)
	{
		return saleManagerMass[i];
	}
	SaleManager getAllSaleManager()
	{
		return *saleManagerMass;
	}
	
	void variableSetSaleManager(int i, char surname[20], int age, char position[25], double salary)
	{
		saleManagerMass[i].setSurname(surname);
		saleManagerMass[i].setAge(age);
		saleManagerMass[i].setPosition(position);
		saleManagerMass[i].setSalary(salary);
	}

	void setSaleManager(int i, SaleManager saleManager)
	{
		saleManagerMass[i] = saleManager;
	}

	Book getBOOK(int i)
	{
		return bookMass[i];
	}
	Book getAllBook()
	{
		return *bookMass;
	}
	void setBook(int i, Book book)
	{
		bookMass[i] = book;
	}

	Client getClient(int i)
	{
		return clientMass[i];
	}

	void setClient(int i, Client client)
	{
		clientMass[i] = client;
	}

};

