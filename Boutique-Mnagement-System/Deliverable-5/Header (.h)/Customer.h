#pragma once
#include<iostream>
#include<string>
#include"Person.h"
using namespace std;

class Customer : public Person{
public:
	int id;
	string name;
	string customerType;
private:
	void createAccount(string pass,string username);
};