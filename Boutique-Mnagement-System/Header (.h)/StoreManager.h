#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

class StoreManager :public Employee{
private:
	int storeId;
public:
	void getmonthlyRecords(int storeid);
	void analyzeRecords(int storeid);
	void viewfetchedzRecords(int storeid);
};
