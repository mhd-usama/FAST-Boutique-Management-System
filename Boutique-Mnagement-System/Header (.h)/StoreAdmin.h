#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

class StoreAdmin :public Employee {
private:
	int stodeId;
public:
	void editOutlet(int storeid);
	void deleteOutlet(int storeid);
};