#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
	string cnic;
	string name;
	int age;
	string phonenum;
	string address;
public:
	 void printdetails(void);

	 string getname()
	 {
		 return name;
	 }
};