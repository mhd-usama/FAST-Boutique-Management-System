#pragma once

#include <list>
#include <stdlib.h>
#include<string>
#include<windows.h>
#include"Product.h"
#include"Inventory.h"
#include"SalesRecord.h"

class productmanagment:public Product,public Inventory
{
	list<Product>list1;
	Inventory *I;
	int totalbill;
	public:
		void set_inventory(Inventory*& i);
		
		void productpurchase(int prodid);
	
	int  get_totalbill();


	bool operation(int products, Product*& p);
};
