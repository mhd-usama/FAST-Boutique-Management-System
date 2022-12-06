#pragma once
#include"Employee.h"
#include"Inventory.h"
#include"SalesAgent.h"
#include<fstream>
class floormanager :public Employee {
	int floornumber;
	
public:
	void view_floor()
	{
		cout << "FloorNumber = "<<floornumber << endl;
	}
	int get_floor()
	{
		return this->floornumber;
	}

	string get_eid()
	{
		string a = Employee::get_id();
		return a;
	}
	void set_manager(Employee& E, int floor)
	{
	
		this->floornumber = floor;
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

	void write_to_file(floormanager f)
	{

		ofstream out;
		out.open("floormanagers.txt");
		out << f.eid << " " << f.floornumber << endl;

		out.close();
	}
	
	void printdetails()
	{
		cout << "Floor Number is = " << this->floornumber << endl;
		Employee::printdetails();
	
	}



	void loadintofloormanager(Employee*& e, int n)
	{
		string id = this->eid;
		int x = this->floornumber;
		for (int i = 0; i < n; i++)
		{
			string b = e[i].get_id();
			if (id == b)
			{
				string name; string cnic; int age; string ph; string add; string eid; string pwd; int sy; int sal; string dest;
				e[i].get_data(name, cnic, age, ph, add, eid, pwd, sy, sal, dest);
				this->set_manager(e[i], x);
				break;
			}
		}
	}

	void  return_product(int productid, Inventory*& i)
	{
		system("CLS");

		cout << "				Product -  Return								\n";
		if (i->returnproduct(productid) == true)
		{
			cout << "Dear Floor Manager Product is Returned\n";

		}
		else
		{
			cout << "Sorry Floor Manager Product is not Returned\n";
		}
	}

	void changeworkshift(SalesAgent*& E, int n)
	{
		cout << "Enter ID of Sales Agent whose work-shift you want to be changed\n";
		string id;
		cin >> id; 
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (E[i].getid() == id)
			{
				flag = false;
				cout << "Enter New Work Shift of Sales Agent \n";
				string work;
				cin.ignore();
				getline(cin,work);
				E[i].setworkshift(work);
				cout << "Successfully Updated Work-Shift of Sales Agent " << E[i].getid() << endl;
				break;
			}
		}

		if (flag)
		{
			cout << "Unable to Update Workshift\n";
		}

		Sleep(4000);
	}


	void operation(Inventory*&I,SalesAgent*&e,int n)
	{
		int a = 0;
		while (1)
		{
			system("CLS");
			cout << "Enter 1 to Return Product\n";
			cout << "Enter 2 to View your Floornumber\n";
			cout << "Enter 3 to View All Sales Agent\n";
			cout << "Enter 4 to Change WorkShift of Sales Agent\n";
			cout << "Enter -1 to Exit\n";
			cin >> a;

			if (a == 1)
			{

				system("CLS");
				
				cout << "************* RETURN PRODUCT *************" << endl;
				cout << "Enter Product ID of Product whose Return to be added\n";
				int prodid = 0;
				cin >> prodid;
				this->return_product(prodid, I);
				Sleep(4000);
			}

			else if (a == 2)
			{
				system("CLS");
				cout << "************* FLOOR NUMBER *************" << endl;
				this->view_floor();
				Sleep(4000);
			
			}

			else if (a == 3)
			{
				system("CLS");
				cout << "************* SALES AGENT(S) *************" << endl;
				for (int i = 0; i < n; i++)
				{
					cout<<"ID = "<<e[i].getid();
					cout << "   WorkShift = " << e[i].getshift();
					cout << endl;
				}

				Sleep(4000);
			}

			else if (a == 4)
			{
				system("CLS");
				cout << "************* SALES AGENT(S) *************" << endl;
				changeworkshift(e, n);
			}
			else
			{
				system("CLS");
				cout << "Good Bye	:" << this->eid << endl;
				return;
			}



		}
	}
};