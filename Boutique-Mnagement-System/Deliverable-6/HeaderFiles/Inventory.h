using namespace std;
#ifndef INVENTORY_H
#define INVENTORY_H
#include<string>
#include<iostream>
#include"Product.h"



class inventoryproduct {
public:
	int  pid;
	int quantity;
};



class Inventory {
private:
	string invName;
	inventoryproduct* invproduct;

	//list<int,int> data; //one is product id other is quantity
public:
	int totalproducts;
	Inventory()
	{
		invName = "Inventory-1";
		invproduct = new inventoryproduct[50];
		totalproducts = 0;
	}

	int getquantity() {
		return totalproducts;
	}
	void addInventory(int invId);

	void deleteproduct(int pid);
	string getname()
	{
		return invName;
	}
	bool purchasedproduct(int proid);
	bool removeproduct(int proid);
	bool returnproduct(int proid);
	void addProduct(int proId);
	void printinventory()
	{
		cout << "Inventory Name = " << invName << "  ";
		cout << "Total Products = " << totalproducts << endl;
		for (int i = 0; i < totalproducts; i++)
			cout << "Product ID = " << invproduct[i].pid << " Quantity = " << invproduct[i].quantity << endl;
	}

	void invRead();
	void invWrite();

};

#endif