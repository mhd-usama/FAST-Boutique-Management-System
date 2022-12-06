#include <list>
#include <stdlib.h>
#include<string>
#include<windows.h>
#include"Product.h"
#include"Inventory.h"
#include"SalesRecord.h"
#include"productmanagment.h"

void productmanagment::set_inventory(Inventory*& i)
{
	I = new Inventory();
	*I = *i;
}
void productmanagment::productpurchase(int prodid)
{

	if (I->purchasedproduct(prodid))
	{
		cout << "Succesfully Added to Cart\n";
	}
	else
	{
		cout << "Cant be  Added to Cart \n";
	}

}

int productmanagment::get_totalbill()
{
	return totalbill;
}


bool productmanagment::operation(int products, Product*& p)
{
	bool flag = true;
	int id;
	int input = 0;
	int sum = 0;
	int iter;

	while (flag != false) {

		cout << endl;
		for (int i = 0; i < products; i++) {
			p[i].productDetails();
		}

		cout << "Enter Product Id For Purchase | exit = -1" << endl;
		cin >> id;

		system("CLS"); //clear screen

		if (id == -1) {
			break;
		}
		if (I->purchasedproduct(id))
		{
			list1.push_back(p[id]);
		}
	}

	system("CLS"); //clear screen

	cout << endl << "Your Cart Items Are" << endl << endl;
	p->Show_Cart(list1);



	while (input != -3) {

		cout << "To Calculate Bill Press -1" << endl;
		cout << "Eneter Product ID to remove product from cart" << endl;
		cout << "To Delete All Cart Items Press -2" << endl;
		cout << "Enter -3 to confirm shopping\n";
		cin >> input;

		if (input == -1) {
			system("CLS"); //clear screen
			p->Show_Cart(list1);
			cout << "Your Calculated Bill is " << p->BillAmount(list1) << endl << endl;
			cout << "Your Bill After All Discounts is " << p->DBillAmount(list1) << endl << endl;
		}
		else if (input == -2) {
			//		p->clearCart(list1);
			int n = list1.size();

			for (int i = 0; i < n; i++) {
				Product x = list1.front();
				list1.pop_front();
				I->addProduct(x.get_productid());

				cout << "Item no " << i + 1 << "Removed Sucessfully\n";
				totalbill = 0;

			}
		}
		else {
			system("CLS"); //clear screen
			p->removeItemFromCart(list1, input);
			I->addProduct(input); p->Show_Cart(list1);


		}
	}
	system("CLS"); //clear screen

	if (!list1.empty()) {	//chech if there are items in cart
		p->paymentMethod();

		//updating sales record
		SalesRecord s;
		s.updateSalesRecord(list1);
		cout << endl << "Sales Record Updated!" << endl;
		return true;
	}

	else {
		return false;
	}
}
