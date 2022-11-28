#ifndef PRODUCT_H
#define PRODUCT_H
#include<string>
#include<iostream>
using namespace std;
class Product {
private:
	int productId;
	string productName;
	string productColour;
	int productBarcode;
public:
	void productDetails();
	void editDiscount(int productId);

};
#endif // !PRODUCT_H

