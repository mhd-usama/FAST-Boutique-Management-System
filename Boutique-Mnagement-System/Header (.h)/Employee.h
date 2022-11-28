#pragma once
#include<iostream>
#include<string>
#include"Person.h"
using namespace std;

class Employee : public Person {
private:
	int eid;
	int serviceYears;
	int salary;
	string designation;
public:
	void addEmployee(int eid, int salary, string designation);
	void deleteEmployee(int eid);
};
