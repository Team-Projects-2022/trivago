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

	val.roomList.Rooms.insert(make_pair(rval.Room_Number, rval));

	Room rval2;

	rval2.Has_TV = false;
	rval2.Has_Wifi = true;

	rval2.available = true;
	rval2.Room_Number = 2;
	rval2.Singularity = false;
	val.roomList.Rooms.insert(make_pair(rval2.Room_Number, rval2));

	h.IDmap.insert(make_pair(val.ID, val));

	//////////////////////////////////////
	val.Available = true;
	val.Country = "Egypt";
	val.Free_Meals[0] = false;
	val.Free_Meals[1] = false;
	val.Has_Gym = false;
	val.Has_pool = false;
	val.ID = 1001;
	val.Location = "Gesr ElSuez - Cairo";
	val.Name = "Elsalam Hotel";
	val.Number_Of_Rooms = 0;
	val.Number_Of_Stars = 1;
	val.Rate = 3.2;

	h.IDmap.insert(make_pair(val.ID, val));

	////////////////////////////////////
	val.Available = true;
	val.Country = "France";
	val.Free_Meals[0] = true;
	val.Free_Meals[1] = true;
	val.Has_Gym = true;
	val.Has_pool = true;
	val.ID = 1002;
	val.Location = "Palace du colonel Fabien - Paris ";
	val.Name = "Generator Paris";
	val.Number_Of_Rooms = 0;
	val.Number_Of_Stars = 3;
	val.Rate = 7.9;

	h.IDmap.insert(make_pair(val.ID, val));

	////////////////////////////////////
	val.Available = true;
	val.Country = "USA";
	val.Free_Meals[0] = true;
	val.Free_Meals[1] = true;
	val.Has_Gym = false;
	val.Has_pool = true;
	val.ID = 1003;
	val.Location = "3555 Las Vegas Boulevard - Las Vegas";
	val.Name = "Flamingo Las Vegas";
	val.Number_Of_Rooms = 0;
	val.Number_Of_Stars = 3;
	val.Rate = 7.8;

	h.IDmap.insert(make_pair(val.ID, val));

	/////////////////////////////////////
	val.Available = true;
	val.Country = "USA";
	val.Free_Meals[0] = false;
	val.Free_Meals[1] = false;
	val.Has_Gym = true;
	val.Has_pool = true;
	val.ID = 1004;
	val.Location = "3850 Las Vegas Boulevard south - Las Vegas";
	val.Name = "Excalibur";
	val.Number_Of_Rooms = 0;
	val.Number_Of_Stars = 3;
	val.Rate = 7.8;

	h.IDmap.insert(make_pair(val.ID, val));

	/////////////////////////////////////
	val.Available = true;
	val.Country = "India";
	val.Free_Meals[0] = false;
	val.Free_Meals[1] = true;
	val.Has_Gym = true;
	val.Has_pool = true;
	val.ID = 1005;
	val.Location = "Taj East Gate road - Uttar Pradesh - Agra";
	val.Name = "Taj Hotel";
	val.Number_Of_Rooms = 0;
	val.Number_Of_Stars = 5;
	val.Rate = 8.6;

	h.IDmap.insert(make_pair(val.ID, val));

}

string GetCountry()
{
	string country;
	cout << " enter the country you want to search in : ";
	cin.ignore(); cin.clear(); cin.sync(); getline(cin, country);

	return country;
}

int Login(userInfo &U)
{
	cout << "Login :" << endl << endl;
	cout << "1. Sign Up " << endl;
	cout << "2. Sign in" << endl << endl;
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
			  cin.ignore(); cin.clear(); cin.sync(); getline(cin, U.name);
			  cout << endl;
			  cout << "country : ";
			  cin.ignore(); cin.clear(); cin.sync(); getline(cin, U.country);
			  cout << endl;
			  cout << "E-mail : ";
			  cin.ignore(); cin.clear(); cin.sync(); getline(cin, U.account);
			  cout << endl;
			  cout << "Password : ";
			  cin.ignore(); cin.clear(); cin.sync(); getline(cin, U.password);
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
				  cin.ignore(); cin.clear(); cin.sync(); getline(cin, username);
				  U.name = username;
				  string passwordx;
				  cout << "Enter password : " << endl;
				  cin.ignore(); cin.clear(); cin.sync(); getline(cin, passwordx);
				  U.password = passwordx;
				  return 2;
			  }
			  else
			  {
				  cout << "Enter Admin's passcode :";
				  string passcode;
				  cin.ignore(); cin.clear(); cin.sync(); getline(cin, passcode);
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
