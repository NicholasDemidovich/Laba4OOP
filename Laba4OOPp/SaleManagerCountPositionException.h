#pragma once
#include "stdio.h"
#include <iostream>
using namespace std;

class SaleManagerException :exception 
{
public:
	SaleManagerException()
	{
		cout << "\nSaleManagerException:��� ��������� � �������� ������!!!" << endl;
	}
};

