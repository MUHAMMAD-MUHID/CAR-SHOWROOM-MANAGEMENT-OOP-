#include "Car.h"
#include "SUV.h"
#include "Hatchback.h"
#include "Sedan.h"
#include "Person.h"
#include "Employee.h"
#include "Customer.h"
#include "Showroom.h"
#include <iostream>
using namespace std;
int main()
{
	int choice;char sure = 'y';
	do {
		cout << "\nEnter Choice: 1-Car 2- EMPLOYEE 3-CUSTOMER 4-Exit";
		cin >> choice;
		switch (choice)
		{

		case 1:
		{
			int choice1;
			cout << "\nEnter Choice: 1-SUV 2- Sedan 3-Hatchback -Exit";
			cin >> choice1;
			if (choice1 == 1)
			{
				SUV obj;
				obj.menu(obj);
			}
			else if (choice1 == 2)
			{
				Sedan obj;
				obj.menu(obj);
			}
			else if (choice1 == 3)
			{
				Hatchback obj;
				obj.menu(obj);
			}
			else
			{
				cout << "\nIncorrect Choice";
			}
			break;
		}
		case 2:
		{
			Employee obj;
			obj.menu(obj);
			break;
		}

		case 3:
		{
			Customer obj;
			obj.menu(obj);
			break;
		}
		case 4:
		{
			cout << "\nAre you sure you want to exit !! YES(Y) / NO(N)";
			cin >> sure;
			break;
		}
		}
	} while (sure == 'N' || sure == 'n');
}