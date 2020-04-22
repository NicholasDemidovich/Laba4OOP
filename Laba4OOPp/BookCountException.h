#pragma once
#include "stdio.h"
#include <iostream>
using namespace std;

class BookException :exception 
{
public:
	BookException()
	{
		cout << "\nBookException:Список кинг переполнен!!! " << endl;
	}
};

