#include "BookShop.h"
#include <map>

void BookShop::inputSaleManager()
{
	char surname[20];
	int age;
	char position[25];
	double salary;
	cout << "\n\tВведите фамилию: ";
	cin >> surname;
	saleManagerMass[countOfSaleManagers].setSurname(surname);
	cout << "\n\tВведите возраст: ";
	cin >> age;
	saleManagerMass[countOfSaleManagers].setAge(age);
	cout << "\n\tВведите должность: ";
	cin >> position;
	saleManagerMass[countOfSaleManagers].setPosition(position);
	cout << "\n\tВведите зарплату: ";
	cin >> salary;
	saleManagerMass[countOfSaleManagers].setSalary(salary);
	countOfSaleManagers++;
}



void BookShop::showSSSaleManagers(BookShop* shop)
{
	BookShop tmp;
	if (shop->getCountOfSaleManagers() == 0) { cout << "\n\tСотрудников нет!"; return; }
	cout << "\n\t***Список сотрудников магазина***\n";
	cout << "   |Фамилия|" << "|Возраст|" << "|Должность|" << "|Зарплата|" << endl;
	for (int i = 0; i < shop->getCountOfSaleManagers(); i++)
	{
		tmp.saleTmp = shop->getSaleManager(i);

		cout << "\t" << tmp.saleTmp.getSurname() << "\t" << tmp.saleTmp.getAge()
			<< "\t " << tmp.saleTmp.getPosition() << "\t    " << tmp.saleTmp.getSalary() << endl;
	}
	/*cout << "\n\t***Список сотрудников магазина***\n";
	for (int i = 0; i < shop->getCountOfSaleManagers(); i++)
	{
		cout << "\n\tФамилия сотрудника: " << saleManagerMass[i].getSurname() << " || Возраст сотрудника: " << saleManagerMass[i].getAge()
			<< "\n\tДолжность сотрудника: " << saleManagerMass[i].getPosition() << " || Зарплата сотрудника: " << saleManagerMass[i].getSalary() << endl;
	}*/
}

void BookShop::deleteSSSaleManeger(BookShop* shop)
{
	char surname[20];
	cout << "\n\tВвеидте фамилию удаляемого продавца:  ";
	cin >> surname;
	for (int i = 0; i < shop->getCountOfSaleManagers(); i++)
	{
		if (strcmp(surname, saleManagerMass[i].getSurname()) == 0)
		{
			for (int j = i; j < shop->getCountOfSaleManagers() - 1; j++)
			{
				saleManagerMass[j] = saleManagerMass[j + 1];
			}
			shop->setCountOfSaleManagers(shop->getCountOfSaleManagers() - 1);
			cout << "\n\tПродавец с фамилией: " << surname << " удален!";
			system("pause");
			return;
		}
	}
	cout << "\n\tТакого продавца в магазине не имеется!!!";
	system("pause");
}

