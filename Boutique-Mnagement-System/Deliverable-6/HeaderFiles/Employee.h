#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Person.h"
using namespace std;



class Employee : public Person {
protected:
	int empSize ; //employee size 0 at first


	
	string eid;
	string password;
	int serviceYears;
	long long int salary;
	
	char type[30];
public:
	string designation;
	Employee();
	void addEmployee(int eid, int salary, string designation);
	void set_data(string name, string cnic, int age, string ph, string add, string eid, string pwd, int sy, int sal, string dest);
	void deleteEmployee(int eid);
	void printdetails(void);
	void empwrite(Employee*& E, int num);
	string get_id()
	{
		return eid;
	}
	string get_pwrd()
	{
		return password;
	}
	void get_data(string &name, string &cnic, int &age, string &ph, string &add, string &eid, string &pwd, int& sy, int &sal, string &dest);
	
};


//FILE WRITE CLASS
class efilewrite
{
public:
	void empwrite(Employee*& E, int num);

};

class efileRead : public Employee
{
	
public:
	
	void empRead(Employee*& E, int &num);

};