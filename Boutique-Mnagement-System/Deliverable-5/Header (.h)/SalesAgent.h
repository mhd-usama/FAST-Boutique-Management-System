#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

class SalesAgent :Employee{
private:
	int numofSales;
public:
	void getSales();
	void addSales();
};
