#pragma once
#include "stdio.h"
#include <iostream>
using namespace std;

class ClientException :exception 
{
public:
	ClientException() 
	{
		cout << "\nClientException:������ �������� ����������!!! " << endl;
	}
};

