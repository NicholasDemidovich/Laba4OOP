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
#include "io.h"
using namespace std;
#pragma warning(disable:4996)



void saveInFileBinaryBook(BookShop bookShop)
{
	int len;
	int counterBook = 0;
	Book bookTmp;
	fstream outBook;
	outBook.open("BookBinary.dat", ios::out | ios::binary);
	if (!outBook)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: BookBinary \n"; return;
	}
	for (int i = 0; i < bookShop.getCountOfBook(); i++)
	{
		bookTmp = bookShop.getBOOK(counterBook);
		len = sizeof(bookTmp);
		outBook.write((char*)&bookTmp, len);
		counterBook++;
	}
	outBook.close();

}

void saveInFileBinarySaleManager(BookShop bookShop)
{
	int len;
	int  counterSaleManager = 0;
	BookShop saleManagerTmp;
	fstream  outSaleManager;
	outSaleManager.open("SaleManagerBinary.dat", ios::out | ios::binary);
	if (!outSaleManager)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: SalaManagerBinary \n"; return;
	}
	for (int i = 0; i < bookShop.getCountOfSaleManagers(); i++)
	{
		saleManagerTmp.setSaleManager(counterSaleManager,bookShop.getSaleManager(counterSaleManager));
		len = sizeof(saleManagerTmp.getSaleManager(counterSaleManager));
		outSaleManager.write((char*)&saleManagerTmp.getSaleManager(counterSaleManager), len);
		counterSaleManager++;
	}
	outSaleManager.close();
}


void saveInFileBinaryClient(BookShop bookShop)
{
	int len;
	int counterClient = 0;
	Client clientTmp;
	fstream outClient;
	outClient.open("ClientBinary.dat", ios::out | ios::binary);
	if (!outClient)
	{
		cerr << "\n\t\t  SAVE:Error - Couldn't open file: ClientBinary \n"; return;
	}
	for (int i = 0; i < bookShop.getCountOfClient(); i++)
	{
		clientTmp = bookShop.getClient(counterClient);
		len = sizeof(clientTmp);
		outClient.write((char*)&clientTmp, len);
		counterClient++;
	}
	outClient.close();

}

void loadFromFileBinaryBook(BookShop *bookShop)
{
	Book tmpBook;
	int counterBook=0;
	int len = sizeof(tmpBook);
	fstream inBook;
	inBook.open("BookBinary.dat", ios::in);
	if (!inBook)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: BookBinary \n"; return;
	}
	while (!inBook.eof())
	{
		tmpBook.setBookCost(0);
		inBook.read((char*)&tmpBook, len);
		if (tmpBook.getBookCost() == 0) { continue; }
		bookShop->setBook(counterBook, tmpBook);
		counterBook++;
		bookShop->setCountOfBook(counterBook);
	}
	inBook.close();
}

void loadFromFileSaleManager(BookShop* bookShop)
{
	
	BookShop saleManagerTmp;
	int counterSaleManager = 0;
	int len = sizeof(saleManagerTmp.getSaleManager(counterSaleManager));
	fstream inSaleManager;
	inSaleManager.open("SaleManagerBinary.dat", ios::in);
	if (!inSaleManager)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file:  SaleManagerBinary \n"; return;
	}
	while (!inSaleManager.eof())
	{
		len = sizeof(saleManagerTmp.getSaleManager(counterSaleManager));
		saleManagerTmp.saleTmp.setAge(0);
		inSaleManager.read((char*)&(saleManagerTmp.saleTmp), len);
		if (saleManagerTmp.saleTmp.getAge() == 0) { continue; }
		bookShop->setSaleManager(counterSaleManager, saleManagerTmp.saleTmp);
		counterSaleManager++;
		bookShop->setCountOfSaleManagers(counterSaleManager);
	}
	inSaleManager.close();
}

void loadFromFileBinaryClient(BookShop* bookShop)
{
	Client tmpClient;
	int counterClient = 0;
	int len = sizeof(tmpClient);
	fstream inClient;
	inClient.open("ClientBinary.dat", ios::in);
	if (!inClient)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: ClientBinary \n"; return;
	}
	while (!inClient.eof())
	{
		tmpClient.setAge(0);
		inClient.read((char*)&tmpClient, len);
		if (tmpClient.getAge() == 0) { continue; }
		bookShop->setClient(counterClient, tmpClient);
		counterClient++;
		bookShop->setCountOfClient(counterClient);
	}
	inClient.close();
}

void findInFileBook(BookShop book)
{
	bool flag = true;
	Book tmp;
	int len = sizeof(tmp);
	char name[25];
	fstream bookFile;
	cout << "\nВведите название искомой книги: ";
	cin >> name;
	bookFile.open("BookBinary.dat", ios::in|ios::binary);
	if (!bookFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: BookBinary \n"; return;
	}
	while(!bookFile.eof())
	{
		bookFile.read((char*)&tmp, len);
		if (strcmp(name, tmp.getBookName()) == 0)
		{
			cout << "\nДанная книга в файле имеется!" << "\n***Информация о искомой книге***";
			cout << "\nНазвание: " << tmp.getBookName()
				<< "\nЖанр: " << tmp.getGenre()
				<< "\nСтоимость: " << tmp.getBookCost()
				<< "\nВозрастное ограничение: " << tmp.getAgeExcepion()
				<< "\nКол-во экземпляров данной книги: " << tmp.getCountOfOneBook() << endl;
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tКниги с названием: " << name << " в файле не имеется!!!"<< endl;
	}
	bookFile.close();
}

void findInFileSaleManager(BookShop book)
{
	bool flag = true;
	BookShop tmp;
	int len = sizeof(tmp.saleTmp);
	char name[25];
	fstream saleManagerFile;
	cout << "\nВведите фамилию искомого продавца: ";
	cin >> name;
	saleManagerFile.open("SaleManagerBinary.dat", ios::in | ios::binary);
	if (!saleManagerFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: SaleManagerBinary \n"; return;
	}
	while (!saleManagerFile.eof())
	{
		saleManagerFile.read((char*)&tmp.saleTmp, len);
		if (strcmp(name, tmp.saleTmp.getSurname()) == 0)
		{
			cout << "\nДанный продавец в файле имеется!" << "\n***Информация о искомом продавце***";
			cout << "\nФамилия: " << tmp.saleTmp.getSurname()
				<< "\nДолжность: " << tmp.saleTmp.getPosition()
				<< "\nВозраст: " << tmp.saleTmp.getAge()
				<< "\nЗарплата: " << tmp.saleTmp.getSalary() << endl;
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tПродавца с фамилией: " << name << " в файле не имеется!!!" << endl;
	}
	saleManagerFile.close();
}


void findInFileClient(BookShop book)
{
	bool flag = true;
	Client tmp;
	int len = sizeof(tmp);
	char name[25];
	fstream clientFile;
	cout << "\nВведите фамилию искомого клиента: ";
	cin >> name;
	clientFile.open("ClientBinary.dat", ios::in | ios::binary);
	if (!clientFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: ClientBinary \n"; return;
	}
	while (!clientFile.eof())
	{
		clientFile.read((char*)&tmp, len);
		if (strcmp(name, tmp.getSurname()) == 0)
		{
			cout << "\nДанный клиент в файле имеется!" << "\n***Информация о искомом клиенте***";
			cout << "\nФамилия: " << tmp.getSurname()
				<< "\nВозраст: " << tmp.getAge()
				<< "\nСчет: " << tmp.getBill()
				<< "\nНомер телефона: " << tmp.getPhoneNumber() << endl;
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tКлиента с фамилией: " << name << " в файле не имеется!!!" << endl;
	}
	clientFile.close();
}


void deleteFromFileBook(BookShop book)
{
	bool flag = true;
	Book tmp;
	int sw=0,size=0;
	int len = sizeof(tmp);
	char name[25];
	fstream bookFile;
	cout << "\nВведите название удаляемой книги: ";
	cin >> name;
	bookFile.open("BookBinary.dat", ios::in|ios::out | ios::binary);
	if (!bookFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: BookBinary \n"; return;
	}
	bookFile.seekg(0, ios::end);
	size = bookFile.tellg();
	bookFile.seekg(0, ios::beg);
	while (!bookFile.eof())
	{
		bookFile.read((char*)&tmp, len);
		if (strcmp(name, tmp.getBookName()) == 0)
		{
			sw = bookFile.tellg();
			if (sw == size)
			{
				flag = false;
				break;
			}
			bookFile.seekg((sw * sizeof(char)), ios::beg);
			for (int i = 0; i < (size/64)-1; i++)
			{
				bookFile.read((char*)&tmp, len);
				bookFile.seekp((sw * sizeof(char))-64, ios::beg);
				bookFile.write((char*)&tmp, len);
				sw = sw+64;
			}
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tКниги с названием: " << name << " в файле не имеется!!!" << endl;
		bookFile.close();
		return;
	}
	bookFile.seekp(-len, ios::end);
	long lon = bookFile.tellp();
	bookFile.close();
	int fd = open("BookBinary.dat", 2);
	chsize(fd, lon);
	close(fd);
}

void deleteFromFileSaleManager(BookShop book)
{
	bool flag = true;
	BookShop tmp;
	int sw = 0, size = 0;
	int len = sizeof(tmp.saleTmp);
	char name[25];
	fstream saleManagerFile;
	cout << "\nВведите фамилию удаляемого продавца: ";
	cin >> name;
	saleManagerFile.open("SaleManagerBinary.dat", ios::in | ios::out | ios::binary);
	if (!saleManagerFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: SaleManager \n"; return;
	}
	saleManagerFile.seekg(0, ios::end);
	size = saleManagerFile.tellg();
	saleManagerFile.seekg(0, ios::beg);
	while (!saleManagerFile.eof())
	{
		saleManagerFile.read((char*)&tmp.saleTmp, len);
		if (strcmp(name, tmp.saleTmp.getSurname()) == 0)
		{
			sw = saleManagerFile.tellg();
			if (sw == size)
			{
				flag = false;
				break;
			}
			saleManagerFile.seekg((sw * sizeof(char)), ios::beg);
			for (int i = 0; i < (size / 64) - 1; i++)
			{
				saleManagerFile.read((char*)&tmp.saleTmp, len);
				saleManagerFile.seekp((sw * sizeof(char)) - 64, ios::beg);
				saleManagerFile.write((char*)&tmp.saleTmp, len);
				sw = sw + 64;
			}
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tПродавца с фамилией: " << name << " в файле не имеется!!!" << endl;
		saleManagerFile.close();
		return;
	}
	saleManagerFile.seekp(-len, ios::end);
	long lon = saleManagerFile.tellp();
	saleManagerFile.close();
	int fd = open("SaleManagerBinary.dat", 2);
	chsize(fd, lon);
	close(fd);
}

void deleteFromFileClient(BookShop book)
{
	bool flag = true;
	Client tmp;
	int sw = 0, size = 0;
	int len = sizeof(tmp);
	char name[25];
	fstream clientFile;
	cout << "\nВведите название удаляемого клиента: ";
	cin >> name;
	clientFile.open("ClientBinary.dat", ios::in | ios::out | ios::binary);
	if (!clientFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: ClientBinary \n"; return;
	}
	clientFile.seekg(0, ios::end);
	size = clientFile.tellg();
	clientFile.seekg(0, ios::beg);
	while (!clientFile.eof())
	{
		clientFile.read((char*)&tmp, len);
		if (strcmp(name, tmp.getSurname()) == 0)
		{
			sw = clientFile.tellg();
			if (sw == size)
			{
				flag = false;
				break;
			}
			clientFile.seekg((sw * sizeof(char)), ios::beg);
			for (int i = 0; i < (size / 48) - 1; i++)
			{
				clientFile.read((char*)&tmp, len);
				clientFile.seekp((sw * sizeof(char)) - 48, ios::beg);
				clientFile.write((char*)&tmp, len);
				sw = sw + 48;
			}
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tКлиента с названием: " << name << " в файле не имеется!!!" << endl;
		clientFile.close();
		return;
	}
	clientFile.seekp(-len, ios::end);
	long lon = clientFile.tellp();
	clientFile.close();
	int fd = open("ClientBinary.dat", 2);
	chsize(fd, lon);
	close(fd);
}


void editFromFileBook(BookShop book)
{
	bool flag = true;
	Book tmp;
	int sw = 0, size = 0,countBook,ageExcep;
	int len = sizeof(tmp);
	char name[25],genre[20];
	double cost;
	fstream bookFile;
	cout << "\nВведите название редактируемой книги: ";
	cin >> name;
	bookFile.open("BookBinary.dat", ios::in | ios::out | ios::binary);
	if (!bookFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: BookBinary \n"; return;
	}
	bookFile.seekg(0, ios::end);
	size = bookFile.tellg();
	bookFile.seekg(0, ios::beg);
	while (!bookFile.eof())
	{
		bookFile.read((char*)&tmp, len);
		if (strcmp(name, tmp.getBookName()) == 0)
		{
			cout << "\n\tВведите новое название:  ";
			cin >> name;
			tmp.setBookName(name);
			cout << "\n\tВведите новый жанр: ";
			cin >> genre;
			tmp.setGenre(genre);
			cout << "\n\tВведите новую стоимость: ";
			cin >> cost;
			tmp.setBookCost(cost);
			cout << "\n\tВведите новое кол-во книги: ";
			cin >> countBook;
			tmp.setCountOfOneBook(countBook);
			cout << "\n\tВведите новое ограничение: ";
			cin >> ageExcep;
			tmp.setAgeException(ageExcep);
			sw = bookFile.tellg();
			bookFile.seekp((sw * sizeof(char)) - 64, ios::beg);
			bookFile.write((char*)&tmp, len);
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tКниги с названием: " << name << " в файле не имеется!!!" << endl;
		bookFile.close();
		return;
	}
	bookFile.close();
}


void editFromFileSaleManager(BookShop book)
{
	bool flag = true;
	BookShop tmp;
	int sw = 0, size = 0, age;
	int len = sizeof(tmp.saleTmp);
	char name[25], position[20];
	double salary;
	fstream saleManagerFile;
	cout << "\nВведите фамилию редактируемого продавца: ";
	cin >> name;
	saleManagerFile.open("SaleManagerBinary.dat", ios::in | ios::out | ios::binary);
	if (!saleManagerFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: SaleManagerBinary \n"; return;
	}
	saleManagerFile.seekg(0, ios::end);
	size = saleManagerFile.tellg();
	saleManagerFile.seekg(0, ios::beg);
	while (!saleManagerFile.eof())
	{
		saleManagerFile.read((char*)&tmp.saleTmp, len);
		if (strcmp(name, tmp.saleTmp.getSurname()) == 0)
		{
			cout << "\n\tВведите новую фамилию:  ";
			cin >> name;
			tmp.saleTmp.setSurname(name);
			cout << "\n\tВведите новый возраст : ";
			cin >> age;
			tmp.saleTmp.setAge(age);
			cout << "\n\tВведите новую должность: ";
			cin >> position;
			tmp.saleTmp.setPosition(position);
			cout << "\n\tВведите новую зарплату: ";
			cin >> salary;
			tmp.saleTmp.setSalary(salary);
			sw = saleManagerFile.tellg();
			saleManagerFile.seekp((sw * sizeof(char)) - 64, ios::beg);
			saleManagerFile.write((char*)&tmp.saleTmp, len);
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tПродавца с фамилией: " << name << " в файле не имеется!!!" << endl;
		saleManagerFile.close();
		return;
	}
	saleManagerFile.close();
}

void editFromFileClient(BookShop book)
{
	bool flag = true;
	Client tmp;
	int sw = 0, size = 0,age;
	int len = sizeof(tmp);
	char name[25], phoneNumber[15];
	double bill;
	fstream clientFile;
	cout << "\nВведите название редактируемого клиента: ";
	cin >> name;
	clientFile.open("ClientBinary.dat", ios::in | ios::out | ios::binary);
	if (!clientFile)
	{
		cerr << "\n\t\t  OPEN:Error - Couldn't open file: ClientBinary \n"; return;
	}
	clientFile.seekg(0, ios::end);
	size = clientFile.tellg();
	clientFile.seekg(0, ios::beg);
	while (!clientFile.eof())
	{
		clientFile.read((char*)&tmp, len);
		if (strcmp(name, tmp.getSurname()) == 0)
		{
			cout << "\n\tВведите новую фамили.:  ";
			cin >> name;
			tmp.setSurname(name);
			cout << "\n\tВведите новый возраст: ";
			cin >> age;
			tmp.setAge(age);
			cout << "\n\tВведите новый счет: ";
			cin >> bill;
			tmp.setBill(bill);
			cout << "\n\tВведите новый номер: ";
			cin >> phoneNumber;
			tmp.setPhoneNumber(phoneNumber);
			sw = clientFile.tellg();
			clientFile.seekp((sw * sizeof(char)) - 48, ios::beg);
			clientFile.write((char*)&tmp, len);
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "\n\tКлиента с фамилией: " << name << " в файле не имеется!!!" << endl;
		clientFile.close();
		return;
	}
	clientFile.close();
}