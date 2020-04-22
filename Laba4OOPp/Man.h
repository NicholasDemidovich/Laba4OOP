#pragma once
#include <iostream>
#include "stdio.h"
using namespace std;

class Man
{
protected:
	char surname[20];
	int age;
public:
	void setSurname(char* surname) { strcpy_s(this->surname, surname); }
	char* getSurname() { return surname; }
	void setAge(int age) { this->age = age; }
	int getAge() { return age; }
};

