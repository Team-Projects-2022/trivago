//alaa edit
#include "Hotel.h"
#include<iostream>
using namespace std;
#include <string>

HotelNode::HotelNode(Hotel val)
{
	value = val;
	next = 0;
}

RoomNode::RoomNode(Room val)
{
	value = val;
	next = 0;
}

RoomList::RoomList()
{
	start = end = 0;
	Number_Of_Rooms = 0;
}

void RoomList::Add_Room()
{

	Room roomtmp;
	cout << "Enter the new room's data:\n";
	cout << "Room Number: ";			 cin >> roomtmp.Room_Number;
	cout << "Is it Singular?: 0/1";		 cin >> roomtmp.Singularity;
	cout << "Has Wifi?: 0/1";			 cin >> roomtmp.Has_Wifi;
	cout << "Has TV?: 0/1";		         cin >> roomtmp.Has_TV;

	RoomNode* newnode = new RoomNode(roomtmp);
	if (start == 0)
		start = end = newnode;
	else
	{
		end->next = newnode;
		end = newnode;
	}
	Number_Of_Rooms++;
}

void RoomList::Update_Room()
{
	int id;
	cout << "Enter The ID of the Room you want to modify : ";
	cin >> id;
	cout << endl;
	RoomNode* tmp = start;
	int counter = 0;
	bool c = true;
	while (tmp->value.Room_Number != id)
	{
		tmp = tmp->next;
		counter++;
		if (counter >= Number_Of_Rooms)
		{
			cout << "ID not valid Please enter a valid ID " << endl;
			c = false;
			break;
		}
	}

	while (c)
	{
		if (tmp->value.reserved)
		{
			cout << "1.Reserved : " << "Yes" << endl;
			cout << "Reservation duration : " << tmp->value.Reservation_Duration << " Days" << endl;
		}
		else { cout << "1.Reserved : " << "No" << endl; }
		if (tmp->value.Has_TV) { cout << "2.Wifi : " << "Has Wifi" << endl; }
		else { cout << "2.Wifi : " << "Doesn't have Wifi" << endl; }
		if (tmp->value.Has_TV) { cout << "3.Tv : " << "Has Tv" << endl; }
		else { cout << "3.Tv : " << "Doesn't have Tv" << endl; }
		if (tmp->value.Singularity) { cout << "4.Single or double : " << "Single" << endl; }
		else { cout << "4.Single or double : " << "Double" << endl; }
		cout << endl;
		cout << "What do you want to modify?" << endl;
		int choose;
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 1:
		{
			cout << "Modify reservation :" << endl;
			if (tmp->value.reserved)
			{
				tmp->value.reserved = false;
				tmp->value.Reservation_Duration = 0;
				cout << "Room is now empty" << endl;
			}
			else
			{
				tmp->value.reserved = true;
				int a;
				cout << "Room reserved, Enter reservation duration : ";
				cin >> a;
				tmp->value.Reservation_Duration = a;
			}
			break;
		}
		case 2:
		{
			cout << "Modify Wifi availability :" << endl;
			if (tmp->value.Has_Wifi)
			{
				cout << "Room Wifi deleted " << endl;
				tmp->value.Has_Wifi = false;
			}
			else
			{
				cout << "Wifi Added !" << endl;
				tmp->value.Has_Wifi = true;
			}
			break;
		}
		case 3:
		{
			cout << "Modify Tv availability :" << endl;
			if (tmp->value.Has_TV)
			{
				cout << "Room Tv deleted " << endl;
				tmp->value.Has_TV = false;
			}
			else
			{
				cout << "Tv Added !" << endl;
				tmp->value.Has_TV = true;
			}
			break;
		}
		case 4:
		{
			cout << "Modify Singularity :" << endl;
			if (tmp->value.Singularity)
			{
				cout << "Room is now double !" << endl;
				tmp->value.Has_TV = false;
			}
			else
			{
				cout << "Room is now single !" << endl;
				tmp->value.Has_TV = true;
			}
			break;
		}
		default:
		{
			break;
		}
		}
		system("cls");
		char ans;
		cout << "Do you want to modify any other thing in this room ?" << endl;
		cin >> ans;
		system("cls");
		if (ans == 'n' || ans == 'N')
			break;
	}

}

HotelList::HotelList()
{
	head = tail = 0;
	Number_Of_Hotels = 0;
}

void HotelList::Add_hotel()
{

	Hotel hoteltmp;
	cout << "Enter the new hotel's data:\n";
	cout << "ID: "; cin >> hoteltmp.ID;
	cout << "Name: "; cin.clear(); cin.sync(); getline(cin, hoteltmp.Name);
	cout << "Country: "; cin >> hoteltmp.Country;
	cout << "Location: "; cin >> hoteltmp.Location;
	cout << "Has Free Meals?: "; cin >> hoteltmp.Free_Meals;
	cout << "Has Gym?: "; cin >> hoteltmp.Has_Gym;
	cout << "Has Pool?: "; cin >> hoteltmp.Has_pool;
	
	cout << "Number Of Rooms: "; cin >> hoteltmp.Number_Of_Rooms;
	for (int i = 0; i < hoteltmp.Number_Of_Rooms; i++)
	{
		hoteltmp.roomList.Add_Room();

	}
	cout << "Number Of Stars: "; cin >> hoteltmp.Number_Of_Stars;
	cout << "Rating: "; cin >> hoteltmp.Rate;
	HotelNode* newNode = new HotelNode(hoteltmp);
	if (head == 0)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	Number_Of_Hotels++;

}

void HotelList::Update_hotel()
{
	int id;
	cout << "Enter The ID of the hotel you want to modify : ";
	cin >> id;
	cout << endl;
	HotelNode* tmp = head;
	int counter = 0;
	bool c = true;
	while (tmp->value.ID != id)
	{
		tmp = tmp->next;
		counter++;
		if (counter >= Number_Of_Hotels)
		{
			cout << "ID not valid Please enter a valid ID " << endl;
			c = false;
			break;
		}
	}
	while (c)
	{
		cout << "1.Hotel name : " << tmp->value.Name << endl;
		cout << "2.Stars : " << tmp->value.Number_Of_Stars << endl;
		cout << "3.Country : " << tmp->value.Country << endl;
		cout << "4.Location : " << tmp->value.Location << endl;
		cout << "5.Free meals : " << tmp->value.Free_Meals << endl;
		cout << "6.Rating : " << tmp->value.Rate << endl;
		if (tmp->value.Has_pool) { cout << "7.Pool : Has pool " << endl; }
		else { cout << "7.Pool : Doesn't have pool " << endl; }
		if (tmp->value.Has_Gym) { cout << "8.Gym : Has gym " << endl; }
		else { cout << "8.Gym : Doesn't have gym " << endl; }
		if (tmp->value.Available) { cout << "9.Availability now : Available " << endl; }
		else { cout << "9.Availability : Isn't available now" << endl; }
		cout << "10.Rooms" << endl;
		cout << endl;
		cout << "What do you want to modify?" << endl;
		int choice;
		cin >> choice;
		system("cls");


		switch (choice)
		{
		case 1:
		{
			string x;
			cout << "Modify the name: ";
			cin.clear();
			cin.sync();
			getline(cin, x);
			tmp->value.Name = x;
			break;
		}
		case 2:
		{
			int x;
			cout << "Modify the number of stars: ";
			cin >> x;
			tmp->value.Number_Of_Stars = x;
			break;
		}
		case 3:
		{
			string x;
			cout << "Modify the country: ";
			cin >> x;
			tmp->value.Country = x;
			break;
		}
		case 4:
		{
			string x;
			cout << "Modify the location : ";
			cin >> x;
			tmp->value.Location = x;
			break;
		}
		case 5:
		{
			string x;
			cout << "Modify Free meals : ";
			cin >> x;
			tmp->value.Free_Meals = x;
			break;
		}
		case 6:
		{
			double x;
			cout << "Modify the rating : ";
			cin >> x;
			tmp->value.Rate = x;
			break;
		}
		case 7:
		{
			cout << "Modify pool availability : ";
			if (tmp->value.Has_pool == true)
				tmp->value.Has_pool = false;
			else
				tmp->value.Has_pool = true;
			break;
		}
		case 8:
		{
			cout << "Modify gym availability : ";
			if (tmp->value.Has_Gym == true)
				tmp->value.Has_Gym = false;
			else
				tmp->value.Has_Gym = true;
			break;
		}
		case 9:
		{
			cout << "Modify hotel availability : ";
			if (tmp->value.Available == true)
				tmp->value.Available = false;
			else
				tmp->value.Available = true;
			break;
		}
		case 10:
		{
			cout << "Modify current rooms: ";
			tmp->value.roomList.Update_Room();
			break;
		}
		default:
		{
			break;
		}
		}
		system("cls");
		char y;
		cout << "Do you want to modify any thing else " << endl;
		cin >> y;
		system("cls");
		if (y == 'n' || y == 'N')
			break;
	}

}

