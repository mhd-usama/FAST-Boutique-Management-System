#pragma once
#include"Employee.h"
#include"floormanagers.h"
#include"StoreManager.h"
#include"SalesAgent.h"
#include"Customer.h"



class admin:public Employee
{
public:
	void set_admin(Employee& E, int floor);
	void add_employee(Employee*& e, int& n);
	bool remove_employee(Employee*& e, int& n);

	void add_customer(Customer*& e, int& n);

	//void add_product(Product*&p,int n);
	//void addcustomer(Customer*&c,int n);
	bool removecustomer(Customer*& e, int& n);

	void viewallcustomers(Customer*& c, int n);

	void viewallemployes(Employee*& c, int n);
};