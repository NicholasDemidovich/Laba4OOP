#include "BookShop.h"
#include <map>

void BookShop::inputSaleManager()
{
	char surname[20];
	int age;
	char position[25];
	double salary;
	cout << "\n\t������� �������: ";
	cin >> surname;
	saleManagerMass[countOfSaleManagers].setSurname(surname);
	cout << "\n\t������� �������: ";
	cin >> age;
	saleManagerMass[countOfSaleManagers].setAge(age);
	cout << "\n\t������� ���������: ";
	cin >> position;
	saleManagerMass[countOfSaleManagers].setPosition(position);
	cout << "\n\t������� ��������: ";
	cin >> salary;
	saleManagerMass[countOfSaleManagers].setSalary(salary);
	countOfSaleManagers++;
}



void BookShop::showSSSaleManagers(BookShop* shop)
{
	BookShop tmp;
	if (shop->getCountOfSaleManagers() == 0) { cout << "\n\t����������� ���!"; return; }
	cout << "\n\t***������ ����������� ��������***\n";
	cout << "   |�������|" << "|�������|" << "|���������|" << "|��������|" << endl;
	for (int i = 0; i < shop->getCountOfSaleManagers(); i++)
	{
		tmp.saleTmp = shop->getSaleManager(i);

		cout << "\t" << tmp.saleTmp.getSurname() << "\t" << tmp.saleTmp.getAge()
			<< "\t " << tmp.saleTmp.getPosition() << "\t    " << tmp.saleTmp.getSalary() << endl;
	}
	/*cout << "\n\t***������ ����������� ��������***\n";
	for (int i = 0; i < shop->getCountOfSaleManagers(); i++)
	{
		cout << "\n\t������� ����������: " << saleManagerMass[i].getSurname() << " || ������� ����������: " << saleManagerMass[i].getAge()
			<< "\n\t��������� ����������: " << saleManagerMass[i].getPosition() << " || �������� ����������: " << saleManagerMass[i].getSalary() << endl;
	}*/
}

void BookShop::deleteSSSaleManeger(BookShop* shop)
{
	char surname[20];
	cout << "\n\t������� ������� ���������� ��������:  ";
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
			cout << "\n\t�������� � ��������: " << surname << " ������!";
			system("pause");
			return;
		}
	}
	cout << "\n\t������ �������� � �������� �� �������!!!";
	system("pause");
}

