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
#include <ctime>
#include <map>
using namespace std;


void createBookShop(BookShop* shop)
{
	char bookShopName[30];
	char address[20];
	cout << "\n������� �������� ��������:  ";
	cin >> bookShopName;
	shop->setBookShopName(bookShopName);
	cout << "\n������� ����� ��������:  ";
	cin >> address;
	shop->setAddress(address);
	shop->setCountOfSaleManagers(0);
	shop->setCountOfBook(0);
	shop->setCountOfClient(0);
}


void addBook(BookShop* shop)
{
	char bookName[25];
	char genre[20];
	double bookCost;
	int countOfOneBook;
	int ageException;
	if (shop->getCountOfBook() == 100) throw BookException();
	cout << "\n������� �������� �����:  ";
	cin >> bookName;
	cout << "\n������� ���� �����:  ";
	cin >> genre;
	cout << "\n������� ��������� �����:  ";
	cin >> bookCost;
	cout << "\n������� ���-�� ������ �����:  ";
	cin >> countOfOneBook;
	cout << "\n������� ����������� �� �������� ��� ������ �����:  ";
	cin >> ageException;
	try
	{
		Book book(bookName, genre, bookCost, countOfOneBook, ageException);
		shop->addCountBook(book);
	}
	catch (int*)
	{
		cout << "\n\t�������������� �������� � ������� addBook!!!" << endl;
		system("pause");
	}
}


ostream& operator<<(ostream& out, Book shop)
{
	return out << shop.getBookName() << "\t" << shop.getGenre() << "\t" << shop.getAgeExcepion() << "\t"
		<< shop.getCountOfOneBook() << "\t" << shop.getBookCost() << endl;
}

ostream& operator <<(ostream& out, Client tmp)
{
	return out << tmp.getSurname() << "\t" << tmp.getAge() << "\t"
		<< tmp.getBill() << "\t" << tmp.getPhoneNumber() << endl;
}

ostream& operator<<(ostream& out, BookShop tmp)
{
	return out << tmp.saleTmp.getSurname() << "\t" << tmp.saleTmp.getAge()
		<< "\t " << tmp.saleTmp.getPosition() << "\t    " << tmp.saleTmp.getSalary() << endl;
}

void showBooks(BookShop* shop)
{
	map<int, Book> bookMap;
	Book tmp;
	if (shop->getCountOfBook() == 0) { cout << "\n\t������� ����!"; return; }
	for (int i = 0; i < shop->getCountOfBook(); i++)
	{
		tmp = shop->getBOOK(i);
		bookMap.emplace(i, tmp);
	}
	cout << "\n\t***������ ���� ��������***\n";
	cout << "  |��������|" << "| ���� |" << "|�������|" << "|���-��|" << "|����|"<< endl;
	for (int i = 0; i < shop->getCountOfBook(); i++)
	{
		cout << "\t" << bookMap[i] ;
	}
	/*cout << "\n\t***������ ���� ��������***\n";
	for (int i = 0; i < shop->getCountOfBook(); i++)
	{
		tmp = shop->getBOOK(i);
		cout << tmp;
	}*/
}

void deleteBook(BookShop* shop)
{
	char nameBook[20];
	cout << "\n\t������� �������� �����:  ";
	cin >> nameBook;
	for (int i = 0; i < shop->getCountOfBook(); i++)
	{
		if (strcmp(shop->getBOOK(i).getBookName(), nameBook) == 0)
		{
			for (int j = i; j < shop->getCountOfBook() - 1; j++)
			{
				shop->setBook(j, shop->getBOOK(j + 1));
			}
			shop->setCountOfBook(shop->getCountOfBook() - 1);
			cout << "\n\t����� � ��������� " << nameBook << " �������!\n";
			system("pause");
			return;
		}
	}
	cout << "\n\t����� � ��������� " << nameBook << " � ������ ���!\n";
	system("pause");
}

void addSaleManager(BookShop* shop)
{
	if (shop->getCountOfSaleManagers() == 5)throw SaleManagerException();
	shop->inputSaleManager();
}

void showSaleManager(BookShop* shop)
{
	if (shop->getCountOfSaleManagers() == 0) { cout << "\n\t� �������� ��� ����������!" << endl; return; }
	shop->showSSSaleManagers(shop);
}

void deleteSaleManager(BookShop* shop)
{
	if (shop->getCountOfSaleManagers() == 0) { cout << "\n\t� �������� ��� ����������!" << endl; return; }
	shop->deleteSSSaleManeger(shop);
}



void addClient(BookShop* shop)
{
	char surname[20];
	int age;
	double bill;
	char phoneNumber[15];
	Client client;
	if (shop->getCountOfClient() == 10) throw ClientException();
	client = shop->getClient(shop->getCountOfClient());
	cout << "\n������� �������:  ";
	cin >> surname;
	client.setSurname(surname);
	cout << "\n������� �������:  ";
	cin >> age;
	client.setAge(age);
	cout << "\n������� ����:  ";
	cin >> bill;
	client.setBill(bill);
	cout << "\n������� ����� ��������:  ";
	cin >> phoneNumber;
	client.setPhoneNumber(phoneNumber);
	shop->setClient(shop->getCountOfClient(), client);
	shop->setCountOfClient(shop->getCountOfClient() + 1);
}


void showClients(BookShop* shop)
{
	map<int, Client> clientMap;
	Client tmp;
	if (shop->getCountOfClient() == 0) { cout << "\n\t������ �������� ����!"; return; }
	for (int i = 0; i < shop->getCountOfClient(); i++)
	{
		tmp = shop->getClient(i);
		clientMap.emplace(i, tmp);
	}
	cout << "\n\t***������ �������� ��������***\n";
	cout << "    |�������|" << "|�������|" << "|����|" << "|�����|" << endl;
	for (int i = 0; i < shop->getCountOfClient(); i++)
	{
		cout <<"\t" <<clientMap[i];
	}

	/*cout << "\n\t***������ �������� ��������***\n";
	for (int i = 0; i < shop->getCountOfClient(); i++)
	{
		tmp = shop->getClient(i);
		cout << "\n\t������� �������: " << tmp.getSurname() << " || ������� �������: " << tmp.getAge()
			<< "\n\t���� �������: " << tmp.getBill() << " || ����� �������: " << tmp.getPhoneNumber() << endl;
	}*/
}

void checkoutOrder(BookShop* shop)
{
	Book book;
	Client client;
	bool checkBook = true;
	bool checkBuySome = true;
	int sw;
	int tmpBook,tmpClient;
	int idClient;
	char bookMass[100][20];
	char surname[20], bookName[25];
	int age, ageExp;
	int countBook = 0;
	double summCost = 0;
	bool flag = true;
	cout << "\n\t������� �������:  ";
	cin >> surname;
	for (int i = 0; i < shop->getCountOfClient(); i++)
		if (strcmp(surname, shop->getClient(i).getSurname()) == 0)
		{
			idClient = i;
			age = shop->getClient(i).getAge(); flag = false; break;
		}
	if (flag) { cout << "\n\t������� � ����� �������� � ������ ���!"; system("pause"); return; }
	while (true)
	{
		cout << "\n\t������� �������� �����: ";
		cin >> bookName;
		flag = true;
		for (int i = 0; i < shop->getCountOfBook(); i++)
			if (strcmp(bookName, shop->getBOOK(i).getBookName()) == 0)
			{
				if(shop->getBOOK(i).getCountOfOneBook()==0)
				{
					cout << "\n\t������ ����� ��� �� ������!!!"<<endl;
					checkBook = false;
					break;
				}
				ageExp = shop->getBOOK(i).getAgeExcepion();
				if (age <= ageExp) { throw GenreException(); }
				summCost += shop->getBOOK(i).getBookCost();
				strcpy_s(bookMass[countBook], bookName);
				countBook++;
				tmpBook = shop->getBOOK(i).getCountOfOneBook();
				tmpBook = tmpBook - 1;
				book = shop->getBOOK(i);
				book.setCountOfOneBook(tmpBook);
				shop->setBook(i, book);
				flag = false;
				checkBuySome = false;
			}
		if (checkBook)
		{
			if (flag) { cout << "\n\t������ ����� � ������ ���!!!" << endl; }
		}
		cout << "\n\t ������� ��������� �����(0 - ��/1 - ���)?  ";
		cin >> sw;
		if (sw == 1) { break; }
	}
	if (shop->getClient(idClient).getBill() < summCost) 
	{
	cout << "\n\t����� �� ����� ������������!��������� ����� �����!" << endl;
	system("pause");
	return; 
	}
	tmpClient = shop->getClient(idClient).getBill() - summCost;
	client = shop->getClient(idClient);
	client.setBill(tmpClient);
	shop->setClient(idClient, client);
	if (checkBuySome) { return; }
	cout << "\n\t***������ ���� ������ ������***\n";
	for (int i = 0; i < countBook; i++)
	{
		cout << "   " << bookMass[i] << endl;
	}
	srand(time(NULL));
	if (shop->getCountOfSaleManagers() == 1)sw = 0;
	if (shop->getCountOfSaleManagers() == 2)sw = rand() % 1;
	if (shop->getCountOfSaleManagers() == 3)sw = rand() % 2;
	if (shop->getCountOfSaleManagers() == 4)sw = rand() % 3;
	if (shop->getCountOfSaleManagers() == 5)sw = rand() % 4;
	cout << "\n\t��������� ������ ������ ���������: " << summCost << endl;
	cout << "****����������� � ��������!����� ���� ������ ��� �����!!!****" << endl;
	cout << "��� �������� ��������:  " << shop->getSaleManager(sw).getSurname() << endl;
	system("pause");
}

void findClient(BookShop *bookShop)
{
	system("Cls");
	Client tmp;
	bool flag = false;
	char surname[20];
	cout << "\n\t ������� ������� �������� �������:  ";
	cin >> surname;
	for(int i = 0;i<(*bookShop).getCountOfClient();i++)
	{
		tmp = (*bookShop).getClient(i);
		if (strcmp(surname, tmp.getSurname()) == 0)
		{
			system("Cls");
			cout << "\n\t***������ � �������� " << surname <<" ������***";
			cout << "\n\t������� �������: " << tmp.getSurname() << " || ������� �������: " << tmp.getAge()
				<< "\n\t���� �������: " << tmp.getBill() << " || ����� �������: " << tmp.getPhoneNumber() << endl;
			flag = true;
			system("pause");
			break;
		}
	
	}
	if(!flag)
	{
		system("Cls");
		cout << "\n\t ������� � �������� " << surname << " � ������ �� �������!!! " << endl;
		system("pause");
	}
}

void changeBook(BookShop *bookShop)
{
	system("Cls");
	Book tmp;
	char nameOfBook[25];
	int cost;
	char genre[20];
	double countOfBook;
	int ageException;
	bool flag = false;
	cout << "\n\t ������� �������� ���������� �����:  ";
	cin >> nameOfBook;
	for (int i = 0; i < bookShop->getCountOfBook(); i++)
	{
		if (strcmp(nameOfBook,(*bookShop).getBOOK(i).getBookName()) == 0)
		{
			system("Cls");
			cout << "\n\t������� ����� �������� �����: ";
			cin >> nameOfBook;
			tmp.setBookName(nameOfBook);
			cout << "\n\t������� ����� ���������: ";
			cin >> cost;
			tmp.setBookCost(cost);
			cout << "\n\t������� ����� ����: ";
			cin >> genre;
			tmp.setGenre(genre);
			cout << "\n\t������� ����� ���-�� ������ �����: ";
			cin >> countOfBook;
			tmp.setCountOfOneBook(countOfBook);
			cout << "\n\t������� ����� ����������� �� �������� ��� ������ ����� ";
			cin >> ageException;
			tmp.setAgeException(ageException);
			bookShop->setBook(i, tmp);
			flag = true;
			system("pause");
			break;
		}

	}
	if (!flag)
	{
		system("Cls");
		cout << "\n\t ����� � ��������� " << nameOfBook << " � ������ ����������!!! " << endl;
		system("pause");
	}
}