#include<iostream>
#include"mygraphics.h"
#include"myconsole.h"
#include<string.h>
#include<string>
#define CRT_SECURE_NO_WARNINGS
using namespace std;

void gotoxy(int x, int y)
{
	printf("%c[%d;[%df", 0x1B, y, x);
}

int login_employee(string& id, string& password, int& type)
{
	COLORREF green = RGB(0, 255, 0);
	COLORREF px = RGB(252, 15, 192);
	COLORREF blue = RGB(0, 0, 255);
	COLORREF red = RGB(255, 0, 0);
	COLORREF white = RGB(255, 255, 255);
	POINT c;
	char str[50]; char ptr[40]; char users[100];
	myRect(0, 0, 1500, 800, green, px);
	//FOR NOW WE HAVE JUST MADE PAGES NO FURTHER IMPLEMENTATION
	while (1) {
		memset(str, '\0', 50);
		strcpy(str, "EMPLOYEE LOGIN PAGE");
	
		myDrawTextWithFont(248, 70, 100, str, white, blue);
		memset(str, '\0', 50);
		


		strcpy(users, "Enter User ID\n");
		myDrawTextWithFont(400, 240, 80, users, white, blue);



		getline(cin,id);
		strcpy(ptr, "Enter User Password\n");

		myDrawTextWithFont(300, 370, 80, ptr, white, blue);
		cout << "Password:";
		getline(cin,password);

		break;
		Sleep(300);
	}
	return 0;
}

int login_customer(string& id,string& password)
    {
	COLORREF green = RGB(0, 255, 0);
	COLORREF px = RGB(252, 15, 192);
	COLORREF blue = RGB(0, 0, 255);
	COLORREF red = RGB(255, 0, 0);
	COLORREF white = RGB(255, 255, 255);
	COLORREF black = RGB(0, 0, 0);
	POINT c;
	char str[50]; char ptr[40]; char users[100]; 
	myRect(0, 0, 1500, 800,black, black);
	myRect(0, 0, 1500, 800, green, px);
	myRect(0, 0, 1500, 800, black, black);
	myRect(0, 0, 1500, 800, green, px);
	while (1) {
		memset(str, '\0', 50);
		strcpy(str, "CUSTOMER LOGIN PAGE");
		
		myDrawTextWithFont(250, 70, 100, str,white, blue);
		memset(str, '\0', 50);
		strcpy(str, "SIGNUP");
		myDrawTextWithFont(250,540, 80, str, green, white);


		strcpy(users, "Enter User ID\n");
		myDrawTextWithFont(400, 240, 80, users, white,blue);
		

		
		
	//	getline(cin, id);
		cin >> id;
		Sleep(300);
		strcpy(ptr, "Enter User Password\n");

		myDrawTextWithFont(300, 370, 80, ptr, white, blue);
		cout << "password:";
		cin >> password;
		myRect(0, 0, 1500, 800, black, black);
		break;
		Sleep(300);
	}
	return 0;
    }

int main_welcome()
  {
	int height = GetSystemMetrics(SM_CYSCREEN);
	int width = GetSystemMetrics(SM_CXSCREEN);
	POINT cursorpos;
	COLORREF green = RGB(0, 255, 0);
	COLORREF blue = RGB(0, 0, 255);
	COLORREF red = RGB(255, 0, 0);
	COLORREF white = RGB(255, 255, 255);
	COLORREF black = RGB(0, 0, 0);
	char str[50]; char ptr[20]; char users[100];
	strcpy(users, "1. CUSTOMER                           2. EMPLOYEE   \n");
	strcpy(str, "WELCOME TO FAST NUCES BOUTIQUE");
	strcpy(ptr, "SELECT USER TYPE");
	char ll[50];
	strcpy(ll, "Right-Click on Desired User Type");
	while (1) {


		myRect(0, 0, 1500, 800, green, white);
		myDrawTextWithFont(60, 70, 100, str, red, white);
		myDrawTextWithFont(340, 240, 80, ptr, red, white);
		myDrawTextWithFont(200, 370, 80, users, blue, white);
		
		myDrawText(200, 510, 50, ll, blue, white);
		//	myRect(400, 400, 420, 420, green, white);

		GetCursorPos(&cursorpos);
		//cout << "x= " << cursorpos.x << "y= " << cursorpos.y << endl;
		if (((cursorpos.x >= 200 && cursorpos.x <= 480)) && (cursorpos.y >= 300 && cursorpos.y <= 460) && (GetAsyncKeyState(VK_RBUTTON)))
		{
			cout << "you are Customer\n";
			myRect(0, 0, 1500, 800,black, black);
			return 1;
		}

		else if (((cursorpos.x >= 600 && cursorpos.x <= 800)) && (cursorpos.y >= 300 && cursorpos.y <= 460) && (GetAsyncKeyState(VK_RBUTTON)))
		{
			cout << "you are Admin\n";
			return 0;
		}

		Sleep(300);
	}
  }
int main()
{


	string id; string password; int type = -1;
	
	///login_customer(id,password);
	if (main_welcome() == 1)
	{
		Sleep(400);
		login_customer(id, password);
	}
	else 
	{
		login_employee(id, password, type);
		ClearScreen();
	}
	
	
	return 0;

}