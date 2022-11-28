#pragma once
#include<iostream>
#include<string>
using namespace std;

class LoyaltyCard {
public:
	int id;
	string type;
private:
	void assignCustomer(string name);
	void removeCard(int id);
};