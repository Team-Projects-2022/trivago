#pragma once
#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

struct Room
{
public:
	int Room_Number;
	bool Calender[12][30];
	bool Singularity;
	bool Has_TV;
	bool Has_Wifi;
	bool available;
};


class RoomList
{
public:
	unordered_map<int, Room> Rooms;
	void Add_Room_Admin();
	void Update_Room();
	void searchroom();
};

struct Hotel
{
	int ID;
	string Name;
	string Country;
	string Location;
	bool Free_Meals[2];
	string comments;
	int Number_Of_Stars;
	int Number_Of_Rooms;
	double Rate;
	bool Has_Gym;
	bool Has_pool;
	bool Available;
	RoomList roomList;
        vector<string> v;
};

class HotelList
{
public:
	int Number_of_Hotels;
	unordered_map<int, Hotel> IDmap;

public:
	HotelList();
	void show();
	void Add_hotel_Admin();
	void Update_hotel();
	//void Delete_hotel();
	//void Display_hotels();
	void Addcomments(int);
	void search(string); // in specific query gym ,pool, free_meals ..
	void filter();
	void searchhotel(string c,int a);
	void reserve(int);
};

