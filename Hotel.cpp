#include "Hotel.h"
#include <string>
#include<vector>
#include <unordered_map>
using namespace std;
#include<iostream>


HotelList::HotelList()
{
}



void HotelList::Add_hotel_Admin()
{

	Hotel hoteltmp;
	char tmpchoice;
	cout << "Enter the new hotel's data:\n";
	cout << "ID: "; cin >> hoteltmp.ID;
	cout << "Name: "; cin.ignore(); cin.clear(); cin.sync(); getline(cin, hoteltmp.Name);
	cout << "Country: "; cin.ignore(); cin.clear(); cin.sync(); getline(cin, hoteltmp.Country);
	cout << "Location: "; cin.ignore(); cin.clear(); cin.sync(); getline(cin, hoteltmp.Location);
	cout << "Has Free Meals?: y/n "; cin >> tmpchoice; if (tmpchoice == 'y') {
		cout << "Has Free Breakfast?: y/n "; cin >> tmpchoice; if (tmpchoice == 'y') { hoteltmp.Free_Meals[0] = true; }
		else { hoteltmp.Free_Meals[0] = false; }
		cout << "Has Free Dinner?: y/n "; cin >> tmpchoice; if (tmpchoice == 'y') { hoteltmp.Free_Meals[1] = true; }
		else { hoteltmp.Free_Meals[1] = false; }
	}
	
	cout << "Number Of Stars: "; cin >> hoteltmp.Number_Of_Stars;
	cout << "Rating: "; cin >> hoteltmp.Rate;

	cout << "Number Of Rooms: "; cin >> hoteltmp.Number_Of_Rooms;
	cout << "Has Gym?:  y/n "; cin >> tmpchoice; if (tmpchoice == 'y') { hoteltmp.Has_Gym = true; }
	else { hoteltmp.Has_Gym = false; }
	cout << "Has Pool?:  y/n "; cin >> tmpchoice;  if (tmpchoice == 'y') { hoteltmp.Has_pool = true; }else { hoteltmp.Has_pool = false; }
	
	system("cls");
	for (int i = 0; i < hoteltmp.Number_Of_Rooms; i++)
	{
		cout << "Enter room " << i + 1 << "'s data:\n";

		hoteltmp.roomList.Add_Room_Admin();
	}

	
	IDmap[hoteltmp.ID] = hoteltmp;

}


void RoomList::Add_Room_Admin()
{

	Room roomtmp;
	char tmpchoice;
	cout << "Room Number: ";			 cin >> roomtmp.Room_Number;
	cout << "Is it Single?:  y/n "; cin >> tmpchoice;	 if (tmpchoice == 'y') { roomtmp.Singularity = true; }
	else { roomtmp.Singularity = false; }
	cout << "Has Wifi?:  y/n ";	cin >> tmpchoice;	 if (tmpchoice == 'y') { roomtmp.Has_Wifi = true; }
	else { roomtmp.Has_Wifi = false; }
	cout << "Has TV?:  y/n ";	cin >> tmpchoice;	     if (tmpchoice == 'y') { roomtmp.Has_TV = true; }
	else { roomtmp.Has_TV = false; }
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 30; j++){
			roomtmp.Calender[i][j] = false;
		}

	}

}

void HotelList::filter() {

	unordered_map<int ,Hotel >::iterator it;
	it = IDmap.begin();

	int c;

	double r;

	int s;

	cout << "Enter your choice" << endl;

	cout << "(1) to search by rate" << endl;

	cout << "(2) to search by stars" << endl;

	cout << "Enter your choice : ";

	cin >> c;

	system("cls");

	if (c == 1) {

		cout << "Enter the rate you want to search for : ";
		cin >> r;

		cout << endl;

		int num = 0;
		for (it = IDmap.begin(); it != IDmap.end(); it++) {
			if (it->second.Rate >= r) {
				num++;

				cout << it->second.Name << ' ' << "has" << ' ' << it->second.Rate << ' ' << "rating" << endl;

				cout << "the hotel ID:" << " " << it->second.ID << endl;


			}

		}
		if (num == 0)
		{
			cout << "no hotel with" << " " << r << " " << "rating" << endl;
		}
		else {
			cout << "do you want to dispaly the rest of information (y/n) : ";

			char choice;

			cin >> choice;
			while (true)
			{

				int count = 0;


				if (choice == 'y') {
					system("cls");

					int id;

					cout << "enter th ID of the hotel you want" << endl;

					cin >> id;


					cout << "1.Country : " << IDmap[id].Country << endl;

					cout << "2.Location : " << IDmap[id].Location << endl;

					if (IDmap[id].Free_Meals[0] != false || IDmap[id].Free_Meals[1] != false)

						cout << "3.Free meals : " << "has free meals" << endl;

					else

						cout << "3.Free meals : " << "has no free meals" << endl;

					if (IDmap[id].Has_pool == true)

						cout << "4.Pool : " << "has Pool" << endl;

					else

						cout << "4.Pool : " << "has no Pool" << endl;

					if (IDmap[id].Has_Gym == true)

						cout << "5.Gym : " << "has Gym" << endl;

					else

						cout << "5.Gym : " << "has no Gym" << endl;

					if (IDmap[id].Available == true)

						cout << "6.Availability : " << "the hotel is available" << endl;

					else

						cout << "6.availability : " << "the hotel is available" << endl;

				}

				else
				{
					count++;
					if (count > IDmap.size() - 1)
					{
						cout << "ID not valid !" << endl;
						return;
					}
				}

				cout << "Is there any other hotel you want to know it's information?(y/n) ";

				cin >> choice;

				if (choice == 'y') {

					continue;

				}

				else

					break;

			}

		}
	}

	if (c == 2) {

		cout << "Enter the number of stars : ";

		cin >> s;
		int num = 0;
		for (it = IDmap.begin(); it != IDmap.end(); it++) {

			if (it->second.Number_Of_Stars >= s) {
				num++;

				cout << it->second.Name << ' ' << "has" << ' ' << it->second.Number_Of_Stars << ' ' << "stars" << endl;

				cout << "the hotel ID:" << it->second.ID << endl;


			}

		}
		if (num == 0)
		{
			cout << "no hotel with" << " " << s << " " << "stars" << endl;
		}


		else {

			cout << "do you want to dispaly the rest of information (y/n) : ";

			char choice;

			cin >> choice;

			while (true){
			int count = 0;
			if (choice == 'y') {

				system("cls");

				int id;

				cout << "enter th ID of the hotel you want" << endl;

				cin >> id;
				cout << "1.Country : " << IDmap[id].Country << endl;

				cout << "2.Location : " << IDmap[id].Location << endl;

				if (IDmap[id].Free_Meals[0] != false || IDmap[id].Free_Meals[1] != false)

				cout << "3.Free meals : " << "has free meals" << endl;

				  else

				cout << "3.Free meals : " << "has no free meals" << endl;

				if (IDmap[id].Has_pool == true)

				 cout << "4.Pool : " << "has Pool" << endl;

				 else

				cout << "4.Pool : " << "has no Pool" << endl;

				if (IDmap[id].Has_Gym == true)

							cout << "5.Gym : " << "has Gym" << endl;

						else

							cout << "5.Gym : " << "has no Gym" << endl;

				if (IDmap[id].Available == true)

							cout << "6.Availability : " << "the hotel is available" << endl;

						else

							cout << "6.availability : " << "the hotel is available" << endl;

					}

					else
					{
						count++;
						if (count > IDmap.size() - 1)
						{
							cout << "ID not valid !" << endl;
							return;
						}
					}
			cout << "there is any other hotel you want to know it's information(y/n)" << endl;

			cin >> choice;

			if (choice == 'y') {
				continue;

			}

			else

				break;
		}
			
		}

	}

}

void RoomList::Update_Room()
{
	int id;
	cout << "Enter The ID of the Room you want to modify : ";
	cin >> id;
	cout << endl;
	int counter = 0;
	bool c = true;
	if (Rooms.find(id) == Rooms.end())
	{
		cout << "ID not valid" << endl;
		c = false;
	}

	while (c)
	{
		if (Rooms[id].Has_TV) { cout << "1.Wifi : " << "Has Wifi" << endl; }
		else { cout << "1.Wifi : " << "Doesn't have Wifi" << endl; }
		if (Rooms[id].Has_TV) { cout << "2.Tv : " << "Has Tv" << endl; }
		else { cout << "2.Tv : " << "Doesn't have Tv" << endl; }
		if (Rooms[id].Singularity) { cout << "3.Single or double : " << "Single" << endl; }
		else { cout << "3.Single or double : " << "Double" << endl; }
		cout << endl;
		cout << "What do you want to modify?" << endl;
		int choose;
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 1:
		{
				  cout << "Modify Wifi availability :" << endl;
				  if (Rooms[id].Has_Wifi)
				  {
					  cout << "Room Wifi deleted " << endl;
					  Rooms[id].Has_Wifi = false;
				  }
				  else
				  {
					  cout << "Wifi Added !" << endl;
					  Rooms[id].Has_Wifi = true;
				  }
				  break;
		}
		case 2:
		{
				  cout << "Modify Tv availability :" << endl;
				  if (Rooms[id].Has_TV)
				  {
					  cout << "Room Tv deleted " << endl;
					  Rooms[id].Has_TV = false;
				  }
				  else
				  {
					  cout << "Tv Added !" << endl;
					  Rooms[id].Has_TV = true;
				  }
				  break;
		}
		case 3:
		{
				  cout << "Modify Singularity :" << endl;
				  if (Rooms[id].Singularity)
				  {
					  cout << "Room is now double !" << endl;
					  Rooms[id].Has_TV = false;
				  }
				  else
				  {
					  cout << "Room is now single !" << endl;
					  Rooms[id].Has_TV = true;
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

void HotelList::show()
{
	unordered_map<int, Hotel>::iterator tmp;
	tmp = IDmap.begin();
	while (tmp != IDmap.end())
	{
		cout << tmp->second.Name << "   ID :" << tmp->second.ID << endl;
		tmp++;
	}

}

void HotelList::Update_hotel()
{
	show();

	int id;
	cout << endl << "Enter The ID of the hotel you want to modify : ";
	cin >> id;
	cout << endl;
	bool c = true;
	if (IDmap.find(id) == IDmap.end())
	{
		cout << "ID not valid " << endl;
		c = false;
	}
	while (c)
	{
		system("cls");
		cout << "1.Hotel name : " << IDmap[id].Name << endl;
		cout << "2.Stars : " << IDmap[id].Number_Of_Stars << endl;
		cout << "3.Country : " << IDmap[id].Country << endl;
		cout << "4.Location : " << IDmap[id].Location << endl;
		cout << "5.Free meals : Breakfast : "; if (IDmap[id].Free_Meals[0]) cout << "YES, "; else cout << "NO, "; cout << "Dinner: "; if (IDmap[id].Free_Meals[1])cout << "YES," << endl; else cout << "NO " << endl;
		if (IDmap[id].Has_pool) { cout << "7.Pool : Has pool " << endl; }
		else { cout << "6.Pool : Doesn't have pool " << endl; }
		if (IDmap[id].Has_Gym) { cout << "8.Gym : Has gym " << endl; }
		else { cout << "7.Gym : Doesn't have gym " << endl; }
		if (IDmap[id].Available) { cout << "9.Availability now : Available " << endl; }
		else { cout << "8.Availability : Isn't available now" << endl; }
		cout << "9.Rooms" << endl;
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
				  cin.ignore(); cin.clear(); cin.sync(); getline(cin, x);

				  IDmap[id].Name = x;

				  break;
		}
		case 2:
		{
				  int x;
				  cout << "Modify the number of stars: ";
				  cin >> x;
				  IDmap[id].Number_Of_Stars = x;
				  break;
		}
		case 3:
		{
				  string x;
				  cout << "Modify the country: ";
				  cin.ignore();
				  cin.clear();
				  cin.sync();
				  getline(cin, x);
				  IDmap[id].Country = x;
				  break;
		}
		case 4:
		{
				  string x;
				  cout << "Modify the location : ";
				  cin.ignore();
				  cin.clear();
				  cin.sync();
				  getline(cin, x);
				  IDmap[id].Location = x;
				  break;
		}
		case 5:
		{
				  bool x, y;
				  cout << "Modify Free meals : breakfast then dinner ";
				  cin >> x;
				  IDmap[id].Free_Meals[0] = x;
				  cin >> y;
				  IDmap[id].Free_Meals[1] = y;

				  break;
		}
		case 6:
		{
				  cout << "Modify pool availability : ";
				  if (IDmap[id].Has_pool == true)
					  IDmap[id].Has_pool = false;
				  else
					  IDmap[id].Has_pool = true;
				  break;
		}
		case 7:
		{
				  cout << "Modify gym availability : ";
				  if (IDmap[id].Has_Gym == true)
					  IDmap[id].Has_Gym = false;
				  else
					  IDmap[id].Has_Gym = true;
				  break;
		}
		case 8:
		{
				  cout << "Modify hotel availability : ";
				  if (IDmap[id].Available == true)
					  IDmap[id].Available = false;
				  else
					  IDmap[id].Available = true;
				  break;
		}
		case 9:
		{
				  cout << "Modify current rooms: ";
				  IDmap[id].roomList.Update_Room();
				  break;
		}
		default:
		{
				   cout << "Choise not valid" << endl;
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

void HotelList::reserve(int id)
{
	int arr[2][3];
	cout << "Start Date : ";
	cin >> arr[0][0] >> arr[0][1] >> arr[0][2];

	cout << "End Date : ";
	cin >> arr[1][0] >> arr[1][1] >> arr[1][2];
	int count = 1;
	cout << "Available Rooms:\n";
	bool check;
	for (unordered_map<int, Room>::iterator it = IDmap[id].roomList.Rooms.begin(); it != IDmap[id].roomList.Rooms.end(); it++)
	{
		for (int i = arr[0][1]; i < arr[1][1]; i++)
		{
			for (int j = arr[0][0]; j < arr[1][0]; j++)
			{
				if (it->second.Calender[i][j] == true)
				{
					check = true;
					break;
				}
			}
		}
		{
			if (check == false)
			{
				cout << "Room #" << count++ << endl;
				if (it->second.Has_TV) { cout << "1.Wifi : " << "Has Wifi" << endl; }
				else { cout << "1.Wifi : " << "Doesn't have Wifi" << endl; }
				if (it->second.Has_TV) { cout << "2.Tv : " << "Has Tv" << endl; }
				else { cout << "2.Tv : " << "Doesn't have Tv" << endl; }
				if (it->second.Singularity) { cout << "3.Single or double : " << "Single" << endl; }
				else { cout << "3.Single or double : " << "Double" << endl; }
				cout << endl;
			}
		}
	}
	if (count == 1)
	{
		cout << "No Available Rooms in this date\n";
	}

	else
	{
		int no;
		cout << "Enter the room number you would like to reserve : "; cin >> no;
		for (int i = arr[0][1]; i < arr[1][1]; i++)
		{
			for (int j = arr[0][0]; j < arr[1][0]; j++)
			{
				IDmap[id].roomList.Rooms[no].Calender[i][j] = true;
			}
		}

		bool av = true;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (IDmap[id].roomList.Rooms[no].Calender[i][j] == false)
				{
					av = false;
					break;
				}
			}
			if (av == false)
				break;
		}

		if (av == true)
		{
			IDmap[id].roomList.Rooms[no].available = false;
		}

		int tmpcount = 0;
		for (unordered_map<int, Room>::iterator it = IDmap[id].roomList.Rooms.begin(); it != IDmap[id].roomList.Rooms.end(); it++)
		{

			if (it->second.available)
			{
				tmpcount++;
			}

		}
		if (tmpcount == 0)
		{
			IDmap[id].Available = false;
		}
	}


}

