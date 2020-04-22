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
#include <Windows.h>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;



void excelPrintBook(BookShop shop)
{
    fstream f;
    Book tmp;
    f.open("out_file_book.xls", ios::out);
    f << "BookName" << "\t" << "Genre"  << "\t" << "AgeException " << "\t" << "CountOfOneBook" << "\t" << "BookCost " << endl;
            for (int i=0;i<shop.getCountOfBook();i++)
            {
                tmp = shop.getBOOK(i);
                f << tmp;
            }
    f.close();

    return;
}


void excelPrintSaleManager(BookShop shop)
{
    fstream f;
    BookShop tmp;
    map<int, BookShop> saleManagerMap;
    f.open("out_file_saleManager.xls", ios::out);
    for (int i = 0; i < shop.getCountOfSaleManagers(); i++)
    {
        tmp.saleTmp = shop.getSaleManager(i);
        saleManagerMap.emplace(i, tmp);
    }
    f << "Surname" << "\t" << "Age" << "\t" << "Position" << "\t" << "Salary" <<endl;
    for (int i = 0; i < shop.getCountOfSaleManagers(); i++)
    {
        f << saleManagerMap[i];
    }
    f.close();
    return;
}

void excelPrintClient(BookShop shop)
{
    fstream f;
    Client tmp;
    f.open("out_file_client.xls", ios::out);
    f << "Surname" << "\t" << "Age" << "\t" << "Bill" << "\t" << "PhoneNumber" << endl;
    for (int i = 0; i < shop.getCountOfClient(); i++)
    {
        tmp = shop.getClient(i);
        f << tmp;
    }
    f.close();
    return;
}



void openExcelFileBook()
{
   system("\"C:\\Users\\nikde\\source\\repos\\Laba2OOP\\Laba2OOP\\out_file_book.xls\"");
}
void openExcelFileSaleManager()
{
    system("\"C:\\Users\\nikde\\source\\repos\\Laba2OOP\\Laba2OOP\\out_file_saleManager.xls\"");
}
void openExcelFileClient()
{
    system("\"C:\\Users\\nikde\\source\\repos\\Laba2OOP\\Laba2OOP\\out_file_client.xls\"");
}