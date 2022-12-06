#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Person.h"
using namespace std;

class Customer : public Person{
protected:
	int cusSize;

private:
	string id;
	string customerType;
	string password;
public:
	Customer();
	void createAccount(Customer*&c,int &n);
	void set_data(string name, string cnic, string id,string password, string customertype, string phone, string add);
	void print();
	void get_data(string& name, string& cnic, string& id, string& password,string& customertype, string& phone, string& add);
	string get_id();
	string get_pwrd();

};

//FILE WRITE CLASS
class cfilewrite{
public:
	void cuswrite(Customer*& C, int num);
};

class fileRead : public Customer{
public:
	void cusRead(Customer*& C, int &num);
};

/*int main() {

	Customer* c1; filewrite f; fileRead r;
	r.cusRead(c1, 3);


	for (int i = 0; i < 3; i++)
		c1[i].print();
	f.cuswrite(c1, 3);

	return 0;
}*/