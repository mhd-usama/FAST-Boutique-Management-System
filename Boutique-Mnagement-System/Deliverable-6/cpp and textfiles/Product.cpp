#include"Product.h"

void Product::setproduct(int pid, string pname, string pcolor, int price, int discount, int barcode)
{
	productId = pid;
	productBarcode = barcode;
	productColour = pcolor;
	productName = pname;
	this->price = price;
	this->discount = discount;
}

void Product::productDetails()
{
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "Product ID: " << productId << "   ArticleName: " << productName << " Color: " << productColour << endl;
	cout << "Price : PKR" << price;
	if (discount > 0)
	{
		cout << " Discount On Article : " << discount << " %";
	}
	cout << endl << "-------------------------------------------------------------------------------------------------\n";
}

void Product::editDiscount(int disc) {
	if (disc <= 100 && disc >= 0)
	{
		discount = disc;
		cout << disc << "% ";
		cout << "Discount Applied Successfully\n ";				return;
	}
	else {
		cout << "Discount Can't be Applied \n ";
	}
}

int Product::get_price() {
	return this->price;
}

int Product::get_productid() {
	return this->productId;
}

void Product::Show_Cart(list<Product> p)
{
	list<Product>::iterator iter;
	for (iter = p.begin(); iter != p.end(); ++iter)
		iter->productDetails();
	cout << endl;
}

int Product::DBillAmount(list<Product> p)
{
	int sum = 0;
	list<Product>::iterator iter;
	for (iter = p.begin(); iter != p.end(); ++iter)
		sum = sum +  iter->calculatediscountedbill(iter->get_price(), iter->discount);
	return sum;
}

int Product::BillAmount(list<Product> p)
{
	int sum = 0;
	list<Product>::iterator iter;
	for (iter = p.begin(); iter != p.end(); ++iter)
		sum = sum + (iter->get_price());
	return sum;
}

void Product::removeItemFromCart(list<Product>& r, int id) {
	list<Product>::iterator iter;
	for (iter = r.begin(); iter != r.end(); ++iter) {
		if (iter->get_productid() == id) {
			r.erase(iter);

			cout << "Item removed from cart!\n";

			break;
		}
	}
}

void Product::clearCart(list<Product>& r)
{
	int n = r.size();
}

void Product::paymentMethod() {
	int met = 0;
	cout << "Enter Payment Method: 1) Cash On Delivery  2) Online Payement\n";
	cin >> met;
	if (met == 1) {
		cout << "your order has been placed and will be deliverd in next 2-3 working days\n";
		cout << "Thank You for Choosing Our Brand\n\n";
		
	}
	else if (met == 2) {
		int cardno = 0;
		int cvc = 0;
		string exp;
		cout << "Enter your Card Number: "; cin >> cardno; cout << endl;
		cout << "Enter CVC code: "; cin >> cvc; cout << endl;
		cout << "Enter card's expiray date (DD/MM/YYYY): "; cin >> exp; cout << endl;
		system("CLS"); //clear screen
		cout << "\nProcessing...\n";
		Sleep(4000);
		system("CLS"); //clear screen
		cout << "\nPayment Successful!\n";
		cout << "your order has been placed and will be deliverd in next 2-3 working days\n";
		cout << "Thank You for Choosing Our Brand\n\n";
		Sleep(2000);

		
	}
}
