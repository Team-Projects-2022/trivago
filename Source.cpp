#pragma once
#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include "Header.h"
#include "Hotel.h"
using namespace std;


int main()
{

	HotelList hotels;
	Setup(hotels);
	bool c = true;
	while (c)
	{
		userInfo U;
		int admin = Login(U);
		system("pause");
		while (admin == 3)
		{
			system("cls");
			cout << "please Re-login" << endl;
			admin = Login(U);
		}
		system("cls");
		switch (admin)
		{
		case 1:
		{
			bool c1 = true;
			while (c1)
			{
				cout << "Logged in as <Admin>" << endl << endl;
				cout << "1.Add Hotel" << endl;
				cout << "2.Update Hotel" << endl;
				cout << "3.Delete Hotel" << endl;
				cout << "4.Display Hotel's info" << endl;
				cout << "5.Search & Filter Hotels" << endl;
				cout << "6.Exit" << endl << endl;
				cout << "choose what you want to do : ";
				int x;
				while (true)
				{
					cin >> x;
					if (x > 6 || x < 1)
					{
						cout << "Enter a valid number : ";
					}
					else
					{
						system("cls");
						break;
					}
				}
				switch (x)
				{
				case 1:
				{
					hotels.Add_hotel_Admin();
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					hotels.Update_hotel();
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					hotels.Delete_hotel();
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					hotels.Display_hotels();
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					int y;
					cout << "Search by availability or Filter hotels (1/2) : ";
					cin >> y;
					if (y == 1)
					{
						string y = GetCountry();
						hotels.searchhotel(y, admin);
						system("pause");
						system("cls");
					}
					else
					{
						string n = GetCountry();
						hotels.search(n, admin);
						system("pause");
						system("cls");
					}
					break;
				}
				case 6:
				{
					c1 = false;
					break;
				}
				}

			}
			break;
		}
		case 2:
		{
			bool c2 = true;
			while (c2)
			{
				cout << "Welcome " << U.name << endl << endl;
				cout << "1.Search for available hotels" << endl;
				cout << "2.Search for hotels with number of stars / rating" << endl;
				cout << "3.Search for hotels with a specific query" << endl;
				cout << "4.Exit" << endl;
				cout << "choose what you want to do : ";
				int x;
				while (true)
				{
					cin >> x;
					if (x > 6 || x < 1)
					{
						cout << "Enter a valid number : ";
					}
					else
					{
						system("cls");
						break;
					}
				}
				switch (x)
				{
				case 1:
				{
					string y = GetCountry();
					hotels.searchhotel(y, admin);
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					string y = GetCountry();
					hotels.filter(y, admin);
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					string n = GetCountry();
					hotels.search(n, admin);
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					c2 = false;
					break;
				}
				}
			}
			break;
		}
		case 3:
		{
			c = false;
			break;
		}
		}
	}
}
