#pragma once
#include<iostream>
#include<string>
using namespace std;

class Staff {
private:
	int eid;
	string attendance;
	string workshift;
public:
	void manageAttendance(int eid, string status);
	void manageWorkshift(int eid, string newshift);
	void viewAttendance();
	void viewWorkshift()
};
