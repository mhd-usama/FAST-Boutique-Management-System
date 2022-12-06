#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
#include"Product.h"
#include"SalesRecord.h"
using namespace std;

class SalesAgent :Employee{
protected:
	int numofSales;
	string workshift;
	SalesRecord s;
public:
	string getshift()
	{
		return this->workshift;
	}
	void prints()
	{
		Employee::printdetails();
	}

	void setworkshift(string w)
	{
		this->workshift = w;
	}
	string getid()
	{
		return this->eid;
	}
	SalesAgent()
	{
		numofSales = 1;
		workshift = "9 to 5";
	}

	void setmanager(Employee&E)
	{
		string name; string cnic; int age; string ph; string add; string eid; string pwd; int sy; int sal; string dest;
		E.get_data(name, cnic, age, ph, add, eid, pwd, sy, sal, dest);
		this->name = name;
		this->cnic = cnic;
		this->age = age;
		this->address = add;
		this->phonenum = ph;
		this->eid = eid;
		this->serviceYears = sy;
		this->salary = sal;
		this->designation = dest;
		this->password = pwd;

	}

	void changeworkshift(SalesAgent& f, string newshift)
	{
		workshift = newshift;
	}
	void getSales()
	{
		s.viewsalesrecord();
	}
	void addSales(Product*&p,int n)
	{
		s.updatesales(p, n);
		numofSales++;
	}
};
