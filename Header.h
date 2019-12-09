#pragma once
#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include "Hotel.h"
using namespace std;

struct userInfo
{
	bool ad;
	string name;
	string country;
	string account;
	string password;
};

void Setup(HotelList& h)
{
	Hotel val;

	val.Available = true;
	val.Country = "Egypt";
	val.Free_Meals[0] = false;
	val.Free_Meals[1] = true;
	val.Has_Gym = false;
	val.Has_pool = true;
	val.ID = 1000;
	val.Location = "Triumph - Cairo";
	val.Name = "Hotel Triumph";
	val.Number_Of_Rooms = 2;
	val.Number_Of_Stars = 2;
	val.Rate = 5;

	Room rval;

	rval.Has_TV = true;
	rval.Has_Wifi = false;
	rval.available = true;
	rval.Room_Number = 1;
	rval.Singularity = true;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			rval.Calender[i][j] = false;
		}
	}

	val.roomList.Rooms.insert(make_pair(rval.Room_Number, rval));

	Room rval2;

	rval2.Has_TV = false;
	rval2.Has_Wifi = true;

	rval2.available = true;
	rval2.Room_Number = 2;
	rval2.Singularity = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			rval2.Calender[i][j] = false;
		}
	}
	val.roomList.Rooms.insert(make_pair(rval2.Room_Number, rval2));

	h.IDmap.insert(make_pair(val.ID, val));

	//////////////////////////////////////
	Hotel val2;
	val2.Available = true;
	val2.Country = "Egypt";
	val2.Free_Meals[0] = false;
	val2.Free_Meals[1] = false;
	val2.Has_Gym = false;
	val2.Has_pool = false;
	val2.ID = 1001;
	val2.Location = "Gesr ElSuez - Cairo";
	val2.Name = "Elsalam Hotel";
	val2.Number_Of_Rooms = 0;
	val2.Number_Of_Stars = 1;
	val2.Rate = 3.2;

	h.IDmap.insert(make_pair(val2.ID, val2));

	////////////////////////////////////
	Hotel val3;
	val3.Available = true;
	val3.Country = "France";
	val3.Free_Meals[0] = true;
	val3.Free_Meals[1] = true;
	val3.Has_Gym = true;
	val3.Has_pool = true;
	val3.ID = 1002;
	val3.Location = "Palace du colonel Fabien - Paris ";
	val3.Name = "Generator Paris";
	val3.Number_Of_Rooms = 0;
	val3.Number_Of_Stars = 3;
	val3.Rate = 7.9;

	h.IDmap.insert(make_pair(val3.ID, val3));

	////////////////////////////////////
	Hotel val4;
	val4.Available = true;
	val4.Country = "USA";
	val4.Free_Meals[0] = true;
	val4.Free_Meals[1] = true;
	val4.Has_Gym = false;
	val4.Has_pool = true;
	val4.ID = 1003;
	val4.Location = "3555 Las Vegas Boulevard - Las Vegas";
	val4.Name = "Flamingo Las Vegas";
	val4.Number_Of_Rooms = 0;
	val4.Number_Of_Stars = 3;
	val4.Rate = 7.8;

	h.IDmap.insert(make_pair(val4.ID, val4));

	/////////////////////////////////////
	Hotel val5;

	val5.Available = true;
	val5.Country = "USA";
	val5.Free_Meals[0] = false;
	val5.Free_Meals[1] = false;
	val5.Has_Gym = true;
	val5.Has_pool = true;
	val5.ID = 1004;
	val5.Location = "3850 Las Vegas Boulevard south - Las Vegas";
	val5.Name = "Excalibur";
	val5.Number_Of_Rooms = 0;
	val5.Number_Of_Stars = 3;
	val5.Rate = 7.8;

	h.IDmap.insert(make_pair(val5.ID, val5));

	/////////////////////////////////////
	Hotel val6;
	val6.Available = true;
	val6.Country = "India";
	val6.Free_Meals[0] = false;
	val6.Free_Meals[1] = true;
	val6.Has_Gym = true;
	val6.Has_pool = true;
	val6.ID = 1005;
	val6.Location = "Taj East Gate road - Uttar Pradesh - Agra";
	val6.Name = "Taj Hotel";
	val6.Number_Of_Rooms = 0;
	val6.Number_Of_Stars = 5;
	val6.Rate = 8.6;

	h.IDmap.insert(make_pair(val6.ID, val6));

}

string GetCountry()
{
	string country;
	cout << "Enter the country you want to search in : ";
	cin.ignore(); cin.clear(); cin.sync();getline(cin, country);

	return country;
}

int Login(userInfo &U)
{
	cout << "Login :" << endl << endl;
	cout << "1. Singn Up " << endl;
	cout << "2. Sign in" << endl<< endl;
	int ch;
	cout << "Enter your choice :";
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case 1:
	{
		U.ad = false;
		cout << "Name : ";
		cin.ignore(); cin.clear(); cin.sync();getline(cin, U.name);
		cout << endl;
		cout << "country : ";
		cin.ignore(); cin.clear(); cin.sync();getline(cin, U.country);
		cout << endl;
		cout << "E-mail : ";
		cin.ignore(); cin.clear(); cin.sync();getline(cin, U.account);
		cout << endl;
		cout << "Password : ";
		cin.ignore(); cin.clear(); cin.sync();getline(cin, U.password);
		cout << endl;
		system("cls");
		cout << "Signed Up successfully" << endl;
		return 2;
	}
	case 2:
	{
		cout << "As user or admin ? (1/2) :";
		int y;
		cin >> y;
		if (y == 1)
		{
			U.ad = false;
			string username;
			cout << "Enter user name : ";
			cin.ignore(); cin.clear(); cin.sync();getline(cin, username);
			U.name = username;
			string passwordx;
			cout << "Enter password : ";
			cin.ignore(); cin.clear(); cin.sync();getline(cin, passwordx);
			U.password = passwordx;
			return 2;
		}
		else
		{
			cout << "Enter Admin's passcode :";
			string passcode;
			cin.ignore(); cin.clear(); cin.sync();getline(cin, passcode);
			if (passcode == "Admin")
			{
				return 1;
			}
			else
			{
				cout << "Not valid Admin" << endl;
				return 3;
			}
		}
	}
	default:
	{
		return 3;
	}
	}
}
