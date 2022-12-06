#pragma once
#include<string>
#include"Inventory.h"
#include"Employee.h"
#include"Product.h"
class InventoryManager :public Employee
{
	string  inv;

public:

	void set_manager(Employee& E, string inv)
	{
		this->inv = inv;
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
	void add_products(Inventory*& i, Product*& p, int n,int quantity)
	{

		cout << "************************************* ADD PRODUCT  **************************************************\n";
		int pid = -1;
		cout << "Enter Product ID That You want to Add Into Inventory\n";
		cin >> pid;

		for (int j = 0; j < n; j++)
		{
			if (pid == p[j].get_productid())
			{
				cout << "Enter Quantity of Product that you want to Enter \n";
				int q = 0;
				cin >> q;
				if (q <= 0)
				{
					cout << "Invalid Quantity Number Added \n";
					return;
				}
				else 
				{   for(int k=0;k<q;k++)
					i->addProduct(pid);

				cout << "Successfully Added " << q << " Number of  Product ID:" << pid << endl;
				Sleep(4000);
				return;
				}
			}


		}

		
	}
	void remove_products(Inventory*& i, int prodid)
	{
		cout << "************************************* REMOVE PRODUCT **************************************************\n";
		cout << "Enter Product ID You Want to Remove from the Inventory\n";
		cin >> prodid;
		
		i->removeproduct(prodid);
	}

	void deleteproduct(Inventory*& I)
	{
		int n = I->getquantity();
		int a = -1;
		cout << "Enter ID OF PRODUCT YOU WANT TO REMOVE\n";
		cin >> a;
		I->deleteproduct(a);
		Sleep(4000);

	}

	void viewinventory(Inventory*& I)
	{
		system("CLS");
		cout << "************************************* INVENTORY **************************************************\n";
		I->printinventory();
	}
};

