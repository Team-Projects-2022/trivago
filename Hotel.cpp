#include "Hotel.h"
#include <string>
#include<vector>
#include <unordered_map>
using namespace std;
#include<iostream>

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
	hoteltmp.Rate = 5.0;

	cout << "Has Gym?:  y/n "; cin >> tmpchoice; if (tmpchoice == 'y') { hoteltmp.Has_Gym = true; }
	else { hoteltmp.Has_Gym = false; }
	cout << "Has Pool?:  y/n "; cin >> tmpchoice;  if (tmpchoice == 'y') { hoteltmp.Has_pool = true; }
	else { hoteltmp.Has_pool = false; }
	cout << "Number Of Rooms: "; cin >> hoteltmp.Number_Of_Rooms;
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
		for (int j = 0; j < 30; j++) {
			roomtmp.Calender[i][j] = false;
		}

	}
	Rooms[roomtmp.Room_Number] = roomtmp;

}

void HotelList::filter(string k, int a, string n) {

	unordered_map<int, Hotel >::iterator it;
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
			if (it->second.Rate >= r && it->second.Country == k) {
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

				if (choice == 'y') {
					system("cls");
					int id;

					cout << "enter th ID of the hotel you want" << endl;

					cin >> id;
					if (IDmap.find(id) == IDmap.end()) {
						cout << "ID Not Valid " << endl;
						cout << "Please enter th ID again";
						continue;
					}

					else {
						cout << "1.Country : " << IDmap[id].Country << endl;

						cout << "2.Location : " << IDmap[id].Location << endl;

						cout << "3.Rating : " << IDmap[id].Rate << endl;

						if (IDmap[id].Free_Meals[0] != false || IDmap[id].Free_Meals[1] != false)

							cout << "4.Free meals : " << "has free meals" << endl;

						else

							cout << "4.Free meals : " << "has no free meals" << endl;

						if (IDmap[id].Has_pool == true)

							cout << "5.Pool : " << "has Pool" << endl;

						else

							cout << "5.Pool : " << "has no Pool" << endl;

						if (IDmap[id].Has_Gym == true)

							cout << "6.Gym : " << "has Gym" << endl;

						else

							cout << "6.Gym : " << "has no Gym" << endl;

						if (IDmap[id].Available == true)

							cout << "7.Availability : " << "the hotel is available" << endl;

						else

							cout << "7.availability : " << "the hotel is available" << endl;

						show_comments(id);

						if (a == 2) {
							cout << "do you want to reserve ?(y/n)";
							char s;
							cin >> s;
							if (s == 'y') {
								reserve(id);
							}
							cout << "Do You want to Add Comments?(y/n) ";
							char ans;
							cin >> ans;
							if (ans == 'y') {
								Addcomments(id,n);
							}

							cout << "Do You want to Rate A Hotel ?(y/n) ";
							char ans1;
							cin >> ans1;
							if (ans1 == 'y') {
								rating(id);
							}
						}
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

			if (it->second.Number_Of_Stars >= s && it->second.Country == k) {
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

			while (true) {
				if (choice == 'y') {

					system("cls");

					int id;

					cout << "enter th ID of the hotel you want" << endl;

					cin >> id;
					if (IDmap.find(id) == IDmap.end()) {
						cout << "ID Not Valid " << endl;
						cout << "Please enter th ID again";
						continue;
					}
					else {
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

						show_comments(id);

						if (a == 2) {
							cout << "do you want to reserve ?(y/n)";
							char s;
							cin >> s;
							if (s == 'y') {
								reserve(id);
							}
							cout << "Do You want to Add Comments?(y/n) "; char ans; cin >> ans;
							if (ans == 'y') {
								Addcomments(id, n);
							}

							cout << "Do You want to Rate A Hotel ?(y/n) "; char ans1; cin >> ans1;
							if (ans1 == 'y') {
								rating(id);
							}
						}
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

void HotelList::Delete_hotel()
{
	cout << "Currently existing hotels \n";
	show();
	int ID;
	cout << "Enter Hotel's ID \n";
	cin >> ID;
	IDmap.erase(ID);
}

void HotelList::Display_hotels()
{
	show();
	char z;
	int ID;
	z = 'y';
	while (z == 'y')
	{
		cout << "If you want to display the information of any hotel Enter its ID \n";
		cin >> ID;
		system("cls");
		if (IDmap.find(ID) != IDmap.end())
		{
			cout << "1.Hotel name : " << IDmap[ID].Name << endl;
			cout << "2.Stars : " << IDmap[ID].Number_Of_Stars << endl;
			cout << "3.Country : " << IDmap[ID].Country << endl;
			cout << "4.Location : " << IDmap[ID].Location << endl;
			cout << "5.Free meals : Breakfast : "; if (IDmap[ID].Free_Meals[0]) cout << "YES, "; else cout << "NO, "; cout << "Dinner: "; if (IDmap[ID].Free_Meals[1])cout << "YES,"; else cout << "NO " << endl;
			cout << "6.Rating : " << IDmap[ID].Rate << endl;
			if (IDmap[ID].Has_pool) { cout << "7.Pool : Has pool " << endl; }
			else { cout << "7.Pool : Doesn't have pool " << endl; }
			if (IDmap[ID].Has_Gym) { cout << "8.Gym : Has gym " << endl; }
			else { cout << "8.Gym : Doesn't have gym " << endl; }
			if (IDmap[ID].Available) { cout << "9.Availability now : Available " << endl; }
			else { cout << "9.Availability : Isn't available now" << endl; }
			cout << endl;
			show_comments(ID);
		}
		else
			cout << "Unavailable \n";
		cout << "If you want to display the information of another Hotel press y or Y \n";
		cin >> z;
		if (z == 'y' || z == 'Y')
			continue;
		else
			break;
	}
}

void RoomList::Update_Room()
{
	cout << endl;
	int id;
	cout << "Enter The number of the Room you want to modify : ";
	cin >> id;
	cout << endl;
	int counter = 0;
	bool c = true;
	if (Rooms.find(id) == Rooms.end())
	{
		cout << "ID not valid" << endl;
		c = false;
	}
	system("cls");
	while (c)
	{
		if (Rooms[id].Has_Wifi) { cout << "1.Wifi : " << "Has Wifi" << endl; }
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
				Rooms[id].Singularity = false;
			}
			else
			{
				cout << "Room is now single !" << endl;
				Rooms[id].Singularity = true;
			}
			break;
		}
		default:
		{
			break;
		}
		}
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
		cout << "9.Rooms : "<< IDmap[id].Number_Of_Rooms << " rooms" << endl;
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
			char x, y;
			cout << "Modify Free meals : " << endl;
			cout << "Does it have breakfast ?(y/n) : ";
			cin >> x;
			if (x == 'y')
			{
				IDmap[id].Free_Meals[0] = true;
			}
			else
			{
				IDmap[id].Free_Meals[0] = false;
			}

			cout << "Does it have dinner ?(y/n) : ";
			cin >> y;
			if (y == 'y')
			{
				IDmap[id].Free_Meals[1] = true;
			}
			else
			{
				IDmap[id].Free_Meals[1] = false;
			}
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
			if (IDmap[id].roomList.Rooms.size() == 0)
			{
				cout << "No rooms in this hotel" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "Current rooms : " << endl;
				unordered_map<int, Room>::iterator i;
				for (i = IDmap[id].roomList.Rooms.begin(); i != IDmap[id].roomList.Rooms.end(); i++)
				{
					cout << "Room number : " << i->second.Room_Number << endl;
				}
				IDmap[id].roomList.Update_Room();
				break;
			}
		}
		default:
		{
			cout << "Choise not valid" << endl;
			break;
		}
		}
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
		cout << endl;

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
	bool check = false;
	for (unordered_map<int, Room>::iterator it = IDmap[id].roomList.Rooms.begin(); it != IDmap[id].roomList.Rooms.end(); it++)
	{
		check = false;

		if (arr[0][1] == arr[1][1])
		{
			for (int i = arr[0][1] - 1; i <= arr[1][1] - 1; i++)
			{
				for (int j = arr[0][0] - 1; j <= arr[1][0] - 1; j++)
				{
					if (it->second.Calender[i][j] == true)
					{
						check = true;
						break;
					}
				}
			}
		}
		else if (arr[1][1] - arr[0][1] == 1)
		{
			for (int i = arr[0][0] - 1; i <= 30; i++)
			{
				if (it->second.Calender[arr[0][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
			for (int i = 0; i <= arr[1][0]; i++)
			{
				
				if (it->second.Calender[arr[1][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
		}
		else
		{
			for (int i = arr[0][0] - 1; i <= 30; i++)
			{
				if (it->second.Calender[arr[0][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
			for (int i = arr[0][1]; i <= arr[1][1] - 2; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					if (it->second.Calender[i][j] == true)
					{
						check = true;
						break;
					}
				}
			}
			for (int i = 0; i <= arr[1][0]; i++)
			{
				if (it->second.Calender[arr[1][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
		}
		if (check == false)
		{
			count++;
			cout << "Room number :" << it->second.Room_Number << endl;
			if (it->second.Has_TV) { cout << "1.Wifi : " << "Has Wifi" << endl; }
			else { cout << "1.Wifi : " << "Doesn't have Wifi" << endl; }
			if (it->second.Has_TV) { cout << "2.Tv : " << "Has Tv" << endl; }
			else { cout << "2.Tv : " << "Doesn't have Tv" << endl; }
			if (it->second.Singularity) { cout << "3.Single or double : " << "Single" << endl; }
			else { cout << "3.Single or double : " << "Double" << endl; }
			cout << endl;
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
		if (arr[0][1] == arr[1][1])
		{
			for (int i = arr[0][1] - 1; i <= arr[1][1] - 1; i++)
			{
				for (int j = arr[0][0] - 1; j <= arr[1][0] - 1; j++)
				{
					IDmap[id].roomList.Rooms[no].Calender[i][j] = true;
				}
			}
		}
		else if (arr[1][1] - arr[0][1] == 1)
		{
			for (int i = arr[0][0] - 1; i <= 30; i++)
			{
				IDmap[id].roomList.Rooms[no].Calender[arr[0][1] - 1][i] = true;
			}
			for (int i = 0; i <= arr[1][0]; i++)
			{
				IDmap[id].roomList.Rooms[no].Calender[arr[1][1] - 1][i] = true;
			}
		}
		else
		{
			for (int i = arr[0][0] - 1; i <= 30; i++)
			{
				IDmap[id].roomList.Rooms[no].Calender[arr[0][1] - 1][i] = true;
			}
			for (int i = arr[0][1]; i <= arr[1][1] - 2; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					IDmap[id].roomList.Rooms[no].Calender[i][j] = true;
				}
			}
			for (int i = 0; i <= arr[1][0]; i++)
			{
				IDmap[id].roomList.Rooms[no].Calender[arr[1][1] - 1][i] = true;
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

void HotelList::search(string c, int a, string n) {


	cout << "Enter the Information you want to search about" << endl;
	cout << "Press (1) to search for Hotels Contains Pool. " << endl <<
		"Press (2) to search for Hotels Contians Gym. " << endl <<
		"Press (3) to search for Hotels Contains Free_meals. " << endl <<
		"Press (4) to search for the three Queries. " << endl <<
		"Enter your Choice : "; int choice; cin >> choice;

	system("cls");
	unordered_map<int, Hotel >::iterator it;
	bool p = false;

	for (it = IDmap.begin(); it != IDmap.end(); it++) {

		if (choice == 1) {
			if (it->second.Has_pool == true && it->second.Country == c) {
				cout << it->second.Name << " Has Pool " << endl;
				cout << " It's ID is " << it->second.ID << endl;
				p = true;

			}
		}
		else if (choice == 2) {

			if (it->second.Has_Gym == true && it->second.Country == c) {
				cout << it->second.Name << " Has Gym" << endl;
				cout << " It's ID is " << it->first << endl;
				p = true;
			}
		}

		else if (choice == 3) {

			if (it->second.Free_Meals[0] == true || it->second.Free_Meals[1] == true) {
				if (it->second.Country == c) {

					cout << it->second.Name << " Has Free_Meals " << endl;

					cout << " It's ID is " << it->first << endl;
					p = true;
				}
			}
		}
		else if (choice == 4) {
			if (it->second.Has_Gym == true && it->second.Has_pool == true &&
				(it->second.Free_Meals[0] || it->second.Free_Meals[1])
				&& it->second.Country == c) {
				cout << it->second.Name << " Has The Three Queries. " << endl;
				cout << " It's ID is " << it->first << endl;
				p = true;
			}
		}
	}


	if (p == true)
	{
		cout << "Do You Want To See Hotel Info ? (y/n) : "; char x; cin >> x;
		system("cls");

		if (x == 'y') {

			while (true) {
				cout << "Enter the ID of the Hotel You'd like to See it's Info : ";	int id;
				cin >> id;
				if (IDmap.find(id) == IDmap.end()) {
					cout << "ID Not Valid " << endl;
					cout << "Please Re-enter ID";
					continue;
				}

				else {
					cout << "1.Hotel name :" << IDmap[id].Name << endl;

					cout << "2.Stars : " << IDmap[id].Number_Of_Stars << endl;

					cout << "3.Country : " << IDmap[id].Country << endl;

					cout << "4.Location : " << IDmap[id].Location << endl;

					cout << "5.Free meals : Breakfast : "; if (IDmap[id].Free_Meals[0])
						cout << "YES, "; else cout << "NO, "; cout << "Dinner: "; if (IDmap[id].Free_Meals[1])
						cout << "YES," << endl; else cout << "NO " << endl;

					cout << "6.Rating : " << IDmap[id].Rate << endl;

					if (IDmap[id].Has_pool) { cout << "7.Pool : Has pool " << endl; }

					else { cout << "7.Pool : Doesn't have pool " << endl; }

					if (IDmap[id].Has_Gym) { cout << "8.Gym : Has gym " << endl; }

					else { cout << "8.Gym : Doesn't have gym " << endl; }

					show_comments(id);


					cout << endl;

					if (a == 2) {
						cout << "/////////////////////////////////" << endl << endl;
						cout << "Would you like to Reserve ?(y/n)"; char f; cin >> f;
						if (f == 'y')
							reserve(id);
						cout << endl;
						cout << "/////////////////////////////////" << endl << endl;
						cout << "Do You want to Add Comments?(y/n) "; char ans; cin >> ans;
						if (ans == 'y')
							Addcomments(id, n);
						cout << endl;
						cout << "/////////////////////////////////" << endl << endl;
						cout << "Do You want to Rate A Hotel ?(y/n) "; char ans1; cin >> ans1;
						if (ans1 == 'y') {
							rating(id);
							cout << endl << "///////////////////////" << endl << endl;
						}
					}

				}

				cout << "If there are any other Hotels You'd Like to see (y/n) : "; char ANS;
				cin >> ANS;
				if (ANS == 'n' || ANS == 'N')
					break;
				else {

					system("cls");
					continue;

				}
			}

		}

	}
	else
		cout << "there is no Hotels in this Area with this Query  " << endl;

}

void HotelList::searchhotel(string c, int a, string n)
{

	unordered_map<int, Hotel>::iterator it;

	int counth = 0;

	string AD;

	cout << " Available Hotels in this country :  " << endl;

	for (it = IDmap.begin(); it != IDmap.end(); it++) {

		if (it->second.Available && it->second.Country == c) {

			cout << it->second.Name << "  " << it->second.ID << endl;

			counth++;

		}

	}

	cout << endl;



	if (counth == 0) {

		cout << " No Available Hotels in this country: " << endl;

		if (a == 1) {

			cout << " do you want to add new hotels to this country ? (yes /no) " << endl;

			cin >> AD;

			if (AD == "yes") {

				Add_hotel_Admin();

			}

		}



	}





	char choice;



	int idhotel;

	while (true)



	{

		if (counth == 0) {

			break;

		}



		cout << "Do you want to display a specific hotel's available rooms ?(y/n)" << endl;



		char b;



		cin >> b;



		if (b == 'n')



		{



			break;



		}



		else



		{



			system("cls");



			cout << "Enter it's ID : ";



			cin >> idhotel;



			if (IDmap.find(idhotel) == IDmap.end()) {

				cout << "unvalid id" << endl;

			}

			else

			{



				IDmap[idhotel].roomList.searchroom();

				if (a == 2) {

					char ans;

					char ans1;

					char ans2;

					cout << " do you want to add comments? (y/n) ";

					cin >> ans;

					if (ans == 'y') {

						Addcomments(idhotel, n);

					}

					cout << " do you want to rate ?(y/n) ";

					cin >> ans1;

					if (ans1 == 'y')

					{

						rating(idhotel);

					}

					cout << " Do you want to reserve? (y/n) ";

					cin >> ans2;

					if (ans2 == 'y')

						reserve(idhotel);

				}

			}

		}


		cout << "Do you want to display another hotel's info(y/n) :" << " ";



		cin >> choice;



		if (choice == 'n') {



			break;



		}

	}





}

void RoomList::searchroom()
{

	unordered_map<int, Room>::iterator it;

	it = Rooms.begin();

	int arr[2][3];

	bool check = false;

	int count = 1;

	cout << "Start Date : ";

	cin >> arr[0][0] >> arr[0][1] >> arr[0][2];

	cout << "End Date : ";



	cin >> arr[1][0] >> arr[1][1] >> arr[1][2];



	cout << "available rooms in this hotel : " << endl;



	for (unordered_map<int, Room>::iterator it = Rooms.begin(); it != Rooms.end(); it++)
	{
		check = false;

		if (arr[0][1] == arr[1][1])
		{
			for (int i = arr[0][1] - 1; i <= arr[1][1] - 1; i++)
			{
				for (int j = arr[0][0] - 1; j <= arr[1][0] - 1; j++)
				{
					if (it->second.Calender[i][j] == true)
					{
						check = true;
						break;
					}
				}
			}
		}
		else if (arr[1][1] - arr[0][1] == 1)
		{
			for (int i = arr[0][0] - 1; i <= 30; i++)
			{
				if (it->second.Calender[arr[0][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
			for (int i = 0; i <= arr[1][0]; i++)
			{

				if (it->second.Calender[arr[1][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
		}
		else
		{
			for (int i = arr[0][0] - 1; i <= 30; i++)
			{
				if (it->second.Calender[arr[0][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
			for (int i = arr[0][1]; i <= arr[1][1] - 2; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					if (it->second.Calender[i][j] == true)
					{
						check = true;
						break;
					}
				}
			}
			for (int i = 0; i <= arr[1][0]; i++)
			{
				if (it->second.Calender[arr[1][1] - 1][i] == true)
				{
					check = true;
					break;
				}
			}
		}
		if (check == false)
		{

			count++;

			cout << "Room number : " << it->second.Room_Number << endl;



			if (it->second.Singularity == true) {



				cout << "this room is single  ";



				if (it->second.Has_TV == true) {



					cout << "HAS TV" << " ";



				}



				else 
				{



					cout << "NO TV " << " ";



				}



				if (it->second.Has_Wifi == true) {



					cout << " HAS WIFI" << endl;



				}



				else {



					cout << "NO WIFI" << endl;



				}







			}



			else {



				cout << "this room is double  ";



				if (it->second.Has_TV == true) {



					cout << "HAS TV" << " ";



				}



				else {



					cout << "NO TV " << " ";



				}



				if (it->second.Has_Wifi == true) {



					cout << " HAS WIFI" << endl;



				}



				else {



					cout << "NO WIFI" << endl;



				}



			}

		}

	}
	if (count == 1)
	{
		cout << "No Available Rooms in this date\n";
	}
}

void HotelList::Addcomments(int id , string n) {
	string comm;
	cout << "Your Comments : "; cin.ignore(); cin.clear(); cin.sync(); getline(cin, comm);
	pair<string, string> c;
	c = make_pair(n, comm);
	IDmap[id].vcomments.push_back(c);

}

void HotelList::show_comments(int id)
{
	cout << "Comments :" << endl;
	for (int i = 0; i < IDmap[id].vcomments.size(); i++)
	{
		cout << IDmap[id].vcomments[i].first << " : " << IDmap[id].vcomments[i].second << endl;
	}
	cout << endl;
}

void HotelList::rating(int id) {
	double rate;
	cout << "Please Enter Your Rating : ";
	cin >> rate;
	IDmap[id].Rate = (IDmap[id].Rate + rate) / 2;
}
