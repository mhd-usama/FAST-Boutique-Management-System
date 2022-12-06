#include "Employee.h"
#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <conio.h>

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
Employee::Employee() {

	empSize = 0;


}

void Employee::addEmployee(int eid, int salary, string designation) {

}

void Employee::deleteEmployee(int eid) {

}

void Employee::set_data(string name, string cnic, int age, string ph, string add, string eid, string pwd, int sy, int sal, string dest)
{
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



void Employee::get_data(string& name, string& cnic, int& age, string& ph, string& add, string& eid, string& pwd, int& sy, int& sal, string& dest)
{
	name= this->name;
	cnic= this->cnic;
	age= this->age;
	 add= this->address;
	ph= this->phonenum ;
	eid= this->eid;
	sy= this->serviceYears ;
	sal= this->salary ;
	 dest=this->designation ;
	 pwd= this->password ;
}

void Employee::printdetails(void)
{
	cout <<" Designation: " <<designation << "  Employee ID: " << eid << " Salary: " << salary << " Service Years: " << serviceYears << " \nName: " << name << " CNIC:" << cnic << "  Age: " << age << "  Phone No:" << phonenum << "  Adress: " << address << endl;
}


void efileRead::empRead(Employee*& E, int& num) {
	
	ifstream fin("employee.txt");
	if (fin.is_open()) {
		
		fin >> num;
		int size = num;
		
		string name; string cnic; int age; string ph; string add; string eid; string pwd; int sy; long long int sal; string dest;


		
		
		for (int i = 0; i < size; i++) {
			

			name = '\0';
			cnic= '\0';
			age= 0;
			ph='\0';
			add= '\0';
			eid= '\0';
			pwd= '\0';
			sy=0;
			sal=0;
			dest= '\0';
			

			    fin >> dest;
				fin >> eid;
				fin >> pwd;
				fin >> sal;
				fin >> sy;
				fin >> name;
				fin >> cnic;
				fin >> age;
				fin >> ph;
				fin >> add;
			
				if (empSize == 0) {

					E = new Employee[empSize + 1];
					empSize++;
					
					E[0].set_data(name, cnic, age, ph, add, eid, pwd, sy, sal, dest);
				}
				else if (empSize != 0) {
					expand<Employee>(E, empSize);
					
					E[empSize - 1].set_data(name, cnic, age, ph, add, eid, pwd, sy, sal, dest);
					
				}
			
		}
		num = empSize;
		fin.close();
		/*obj.showcs();*/

	}
}


void efilewrite::empwrite(Employee*& E, int num) {
	cout << "Updating Records" << endl;

	ofstream out;
	out.open("employee.txt");
	out << num << endl;
	for (int i = 0; i < num; i++)
	{
		string name; string cnic; int age; string ph; string add; string eid; string pwd; int sy; int sal; string dest;
		E[i].get_data(name, cnic, age, ph, add, eid, pwd, sy, sal, dest);
		out << dest << " "<< eid << " " << pwd << " " << sal << " " << sy << " " << name << " " << cnic << " " << age << " " << ph<< " " << add << " " << endl;
	}
	out.close();
}








