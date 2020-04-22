#pragma once
#include <iostream>
#include "stdio.h"
#include "Man.h"
using namespace std;

class Client :public Man
{
	double bill;
	char phoneNumber[15];
public:
	void setBill(double bill) { this->bill = bill; }
	double getBill() { return bill; }
	void setPhoneNumber(char* phoneNumber) { strcpy_s(this->phoneNumber, phoneNumber); }
	char* getPhoneNumber() { return phoneNumber; }
};

