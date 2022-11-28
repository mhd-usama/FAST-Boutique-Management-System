#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>
#include<iostream>
using namespace std;
class Inventory {
private:
	string invName;
public:
	void addInventory(int invId);
	void addProduct(int invId, int proId);
};
#endif // !INVENTORY_H

