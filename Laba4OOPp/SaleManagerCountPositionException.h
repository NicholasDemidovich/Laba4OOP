#pragma once
#include "stdio.h"
#include <iostream>
using namespace std;

class SaleManagerException :exception 
{
public:
	SaleManagerException()
	{
		cout << "\nSaleManagerException:Все должности в магазине заняты!!!" << endl;
	}
};

