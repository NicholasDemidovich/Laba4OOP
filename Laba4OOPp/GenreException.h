#pragma once
#include "stdio.h"
#include <iostream>
using namespace std;

class GenreException :exception
{
public:
	GenreException()
	{
		cout << "\nGenreException:���� �� �������� ��� ������ ��������!!! " << endl;
	}
};

