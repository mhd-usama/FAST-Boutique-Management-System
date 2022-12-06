#pragma once
#include"Employee.h"
#include"floormanagers.h"
#include"StoreManager.h"
#include"SalesAgent.h"
#include"Customer.h"
#include"Admin.h"
template<typename t1>
void expand(t1*& p, int& size) {
	t1* ptr = new t1[size + 1];
	for (int i = 0; i < size; i++) {
		ptr[i] = p[i];
	}
	delete[]p;
	p = nullptr;
	p = ptr;
	size++;
}

template<typename t2>
void shrink(t2*& pr, int& size, int index) {

	t2* pri = new t2[size];
	for (int i = 0; i < size; i++) {
		pri[i] = pr[i];
	}
	pr[index] = pr[size - 1];
	pr[size - 1] = pri[index];

	t2* ptr = new t2[size - 1];

	for (int i = 0; i < size - 1; i++) {
		ptr[i] = pr[i];
	}
	delete[]pr;
	pr = nullptr;
	pr = ptr;
	size--;

}




void admin::set_admin(Employee& E, int floor)
{

	//this->floornumber = floor;
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
void admin::add_employee(Employee*& e, int& n)
{
	string name; string cnic; int age = 10; string ph; string add; string eid; string pwd; int sy; int sal = 30000; string dest;
	cout << "\nEnter Name of Employee:";
	cin >> name;
	cout << "\nEnter CNIC of Employee:";
	cin >> cnic;
	while (age <= 17)
	{
		cout << "\nEnter AGE of Employee:";
		cin >> age;
	}
	cout << "\nEnter PHONE of Employee:";
	cin >> ph;
	cout << "\nEnter ADDRESS of Employee:";
	cin >> add;
	cout << "\nEnter EMPLOYEEID of Employee:";
	cin >> eid;
	cout << "\nEnter PASSWORD of Employee:";
	cin >> pwd;
	while (sal <= 30000)
	{
		cout << "\nEnter SALARY of Employee:" << name;
		cin >> sal;
	}
	cout << "\nEnter SERVICE YEARS of Employee:" << name;
	cin >> sy;
	cout << "\nEnter DESIGNATION/POSITION of Employee:";
	//	cin >> dest;
	int opt = -1;


	while (opt <= 0 || opt > 5)
	{
		cout << "Press 1 for Store Manager\nPress 2 for Floor Manager\nPress 3 for Sales Agent\n Press 4 for Inventory Manager\n Press 5 for Ordinary Staff\n";
		cin >> opt;
		if (opt == 1)
		{
			dest = "StoreManager";
		}
		else if (opt == 2)
		{
			dest = "FloorManager";
		}
		else if (opt == 3)
		{
			dest = "Sales Agent";
		}

		else if (opt == 4)
		{
			dest = "Inventory Manager";
		}
		else if (opt == 5)
		{
			dest = "Staff";
		}
	}


	expand(e, n);
	int index = n - 1;

	e[index].set_data(name, cnic, age, ph, add, eid, pwd, sy, sal, dest);

	//n++;

}
bool admin:: remove_employee(Employee*& e, int& n)
{
	cout << "Enter ID of Employee You Want  to Remove \n";
	string id;
	cin >> id;

	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (id == e[i].get_id())
		{
			if (e[i].designation == "Admin")
			{
				cout << " Admin Can't be Deleted\n";
				flag = false;
				break;
			}
			else {
				flag = true;
				shrink(e, n, i);
				break;
			}
		}
	}
	if (flag == false)
	{
		cout << "Invalid ID was Entered\n";
	}


	return flag;
}

void admin::add_customer(Customer*& e, int& n)
{
	Customer s;
	s.createAccount(e, n);
}

//void add_product(Product*&p,int n);
//void addcustomer(Customer*&c,int n);
bool admin::removecustomer(Customer*& e, int& n)
{
	cout << "Enter ID of Customer You Want  to Remove \n";
	string id;
	cin >> id;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (id == e[i].get_id())
		{
			flag = true;
			shrink(e, n, i);
			break;
		}
	}
	if (flag == false)
	{
		cout << "Invalid ID was Entered\n";
	}


	return flag;
}

void admin::viewallcustomers(Customer*& c, int n)
{
	system("CLS");
	cout << "***************************** ALL CUSTOMERS ************************************\n";
	for (int i = 0; i < n; i++)
	{

		cout << "Customer : " << i + 1 << endl;
		c[i].print();
		cout << "----------------------------------------------------------------------------------------\n";
	}
}

void admin:: viewallemployes(Employee*& c, int n)
{
	system("CLS");
	cout << "***************************** ALL EMPLOYEES ************************************\n";
	for (int i = 0; i < n; i++)
	{

		cout << "Employee : " << i + 1 << endl;
		c[i].printdetails();
		cout << "----------------------------------------------------------------------------------------\n";
	}
}