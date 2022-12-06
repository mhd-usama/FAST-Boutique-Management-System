#pragma once
#include<string>
#include<iostream>
#include<list>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include<windows.h>


using namespace std;

class Product {
protected:
	int productId;
	string productName;
	string productColour;

	int price;
	int discount;
	int productBarcode;

public:

	string getname()
	{
		return this->productName;
	}
	string getcolor()
	{
		return this->productColour;
	}
	void getadds(int& p, int& d, int& b)
	{
		p = this->price;
		d = this->discount;
		b= this->productBarcode;
	}
	void setproduct(int pid, string pname, string pcolor, int price, int discount, int barcode);
	void productDetails();
	void editDiscount(int disc);
	int get_price();
	int get_productid();
	void Show_Cart(list<Product> p);
	void clearCart(list<Product>& p);
	int calculatediscountedbill(int price, int discount)
	{
		return (price - int((price * discount *0.01)));
	}
	int BillAmount(list<Product> p);
	void setdisc(int d)
	{
		discount = d;
	}
	int DBillAmount(list<Product> p);
	void removeItemFromCart(list<Product>& r, int id);
	void paymentMethod();
	int getdisc()
	{
		return discount;
	}
};


class productfiles :public Product
{
public:
	void writeproduct(Product*&p,int n)
	{
		ofstream out;
		out.open("product.txt");
		out << n << endl;
		for (int i = 0; i < n; i++)
		{
			out << p[i].get_productid() <<" ";

			out << p[i].getdisc() << endl; 
		}
		out.close();
	}


	void fileread(int*&d,int&n)
	{
		ifstream file;
		file.open("product.txt");
		file >> n; int x = 0;
		for (int i = 0; i < n; i++)
		{
			file >> x;
			file >> d[i];

		}
		file.close();
	}
};

