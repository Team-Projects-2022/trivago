#include<iostream>
#include"Hotel.h"
#include<string>
using namespace std;
void Setup(HotelList& h);
int main()
{
	HotelList hotels;
	Setup(hotels);
	bool c = true;
	while (c)
	{
		int admin;
		cout << "Login :" << endl;
		cout << endl;
		cout << "1.Admin     2.User     3.Exit" << endl;
		while (true)
		{
			cin >> admin;
			if (admin > 3 || admin < 0)
			{
				cout << "Enter a valid number" << endl;
			}
			else
			{
				system("cls");
				break;
			}
		}
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
						hotels.searchhotel();
						system("pause");
						system("cls");
					}
					else
					{
						hotels.search();
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
				cout << "Logged in as <User>" << endl << endl;
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
					hotels.searchhotel();
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					hotels.filter();
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					hotels.search();
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

	HotelNode* newnode = new HotelNode(val);
	h.Number_Of_Hotels++;
	h.head = newnode;

	Room rval;

	rval.Has_TV = true;
	rval.Has_Wifi = false;
	rval.Reservation_Duration = 0;
	rval.reserved = false;
	rval.Room_Number = 1;
	rval.Singularity = true;
	RoomNode* r = new RoomNode(rval);
	h.head->value.roomList.start = r;

	Room rval2;

	rval2.Has_TV = false;
	rval2.Has_Wifi = true;
	rval2.Reservation_Duration = 0;
	rval2.reserved = true;
	rval2.Room_Number = 2;
	rval2.Singularity = false;
	RoomNode* r2 = new RoomNode(rval);
	h.head->value.roomList.start->next = r2;

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
	HotelNode* newnode2 = new HotelNode(val);
	h.Number_Of_Hotels++;
	newnode->next = newnode2;
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
	HotelNode* newnode3 = new HotelNode(val);
	h.Number_Of_Hotels++;
	newnode2->next = newnode3;
	////////////////////////////////////
	val.Available = false;
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
	HotelNode* newnode4 = new HotelNode(val);
	h.Number_Of_Hotels++;
	newnode3->next = newnode4;
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
	HotelNode* newnode5 = new HotelNode(val);
	h.Number_Of_Hotels++;
	newnode4->next = newnode5;
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
	HotelNode* newnode6 = new HotelNode(val);
	h.Number_Of_Hotels++;
	newnode5->next = newnode6;

	h.tail = newnode6;
	
}

