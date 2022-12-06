#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
#include"Product.h"
using namespace std;

class StoreManager :public Employee{
private:
	int storeid;
public:

	void set_manager(Employee& E, int storeid)
	{

		this->storeid = storeid;
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
	void view_manager()
	{
		cout << "StoreID: " << storeid << " ";
		Employee::printdetails();
	}

	void editdiscountpolicy(Product*& p,int n)
	{
		bool flag = false;
		cout << "Enter Product ID of Product whose Discount You Want to Edit\n";
		int pid = 0;
		cin >> pid;

		for (int i = 0; i < n; i++)
		{
			if (pid == p[i].get_productid())
			{
				cout << "Enter Discount value\n";
				int d;
				cin >> d;
				p[i].editDiscount(d);
				flag = true;
				break;
			}
		}

		if (flag == false)
		{
			cout << "Product Not Found\n";
		}


	}//just modify it

	void operation(Product*& p, int n)
	{
		int t = 0;
		while (1)
		{
			cout << "Press 1 to Edit Discount Policies\n";
			cout << "Press 2 to View All Products Offered\n";
			cout << "Press 3 to View Store ID\n";
			cout << "Press 4 to LOGOUT\n";
			cin >> t;

			if (t == 1)
			{
				cout << "*******************  EDIT DISCOUNT POLICY *******************\n";
				system("CLS");
				editdiscountpolicy(p, n);
				Sleep(4000);

			}

			else if (t == 2)
			{
				system("CLS");
				cout << "*******************  PRODUCT INFORMATION *******************\n";
				for (int i = 0; i < n; i++)
				{
					p[i].productDetails();
				}

				
			}

			else if (t == 3)
			{
				system("CLS");
				cout << "******************* STORE NUMBER *******************\n";

				cout << "Store Number  =   " << this->storeid << endl;
				Sleep(4000);
			}

			else
			{
				break;
			}
		}
	}
};



