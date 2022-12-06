#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

class FloorManager :public Employee {
private:
	int floorNumber;
public:
	void viewfloorNumber();
	void getReports();
};