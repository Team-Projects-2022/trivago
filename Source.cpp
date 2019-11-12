#include<iostream>
#include"Hotel.h"
#include<string>
using namespace std;

void adminAdd(){
	bool ans; int add;
	HotelList hotels;
	cout << "Click 1 to add hotel\n";
	cin >> add;
	if (add==1)
	hotels.Add_hotel();
	cout << "Again? 0/1";
	cin >> ans;
	if (ans == 1){
		system("cls");
		adminAdd();
	}
	
}
int main()
{
	adminAdd();
	/*HotelList x;
	Hotel h;
	Hotel r;
	Room z;
	h.ID = 1;
	h.Name = "Hotel transylvania";
	h.Number_Of_Stars = 4;
	h.Country = "Egypt";
	h.Location = "cairo";
	h.Free_Meals = "breakfast-lunch";
	h.Rate = 8.5;
	h.Has_pool = true;
	h.Has_Gym = false;
	h.Available = true;
	/////////////////////
        r.Name = " kempinski";
	r.Number_Of_Stars = 5;
	r.ID = 2;
	r.Has_pool = true;
	r.Has_Gym = true;
	/////////////////////////////////// hotel
	z.Has_TV = true;
	z.Has_TV = true;
	z.Reservation_Duration = 14;
	z.reserved = false;
	z.Room_Number = 1;
	z.Singularity = false;
	/////////////////////////////////// room
	h.rooms.Add_Room(z);
	x.Add_hotel(h);
        x.Add_hotel(r);
	x.Update_hotel();
	*/
}
