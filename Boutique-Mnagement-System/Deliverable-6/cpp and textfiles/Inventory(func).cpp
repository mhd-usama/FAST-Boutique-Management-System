//implementation file for Inventory.h
#include "Inventory.h"
#include<fstream>
template<typename t1>
void expand(t1*& p, int& size) {
	t1* ptr = new t1[size + 1];
	for (int i = 0; i < size; i++) {
		ptr[i] = p[i];
	}
	delete[]p;
	p = nullptr;
	p = ptr;
	size++;
}

template<typename t2>
void shrink(t2*& pr, int& size, int index) {

	t2* pri = new t2[size];
	for (int i = 0; i < size; i++) {
		pri[i] = pr[i];
	}
	pr[index] = pr[size - 1];
	pr[size - 1] = pri[index];

	t2* ptr = new t2[size - 1];

	for (int i = 0; i < size - 1; i++) {
		ptr[i] = pr[i];
	}
	delete[]pr;
	pr = nullptr;
	pr = ptr;
	size--;

}



void Inventory::deleteproduct(int pid)
{
	bool flag = true;

	for (int i = 0; i < totalproducts; i++)
	{
		if (invproduct[i].pid == pid)
		{
			shrink(invproduct, totalproducts, i);

			cout << "Successfully Deleted Product\n";
			flag = false;
			break;
		}


	}
	if (flag == true)
	{
		cout << "Unable to  Delete  Product\n ";
	}
}
void Inventory::addProduct(int proId) {
	{
		bool flag = false;
		for (int i = 0; i < totalproducts; i++)
		{
			if (invproduct[i].pid == proId)
			{
				invproduct[i].quantity++;
				flag = true;
				cout << "Existing Product Added To Inventory Successfully\n";
				break;
			}
		}

		if (flag == false)
		{
			cout << "New Product Added" << endl;
			int n = totalproducts;
			invproduct[n].pid = proId;
			invproduct[n].quantity = 1;
			totalproducts++;
		}
	}

}

bool Inventory::purchasedproduct(int proid)
{
	bool flag = false;
	for (int i = 0; i < totalproducts; i++)
	{
		if (invproduct[i].pid == proid)
		{

			if (invproduct[i].quantity == 0)
			{
				cout << "Product is Sold-Out (Not Enough Articles Available)\n";
				return false;
			}
			invproduct[i].quantity--;
			flag = true;
			cout << "Product Purchased remove from inventory\n";
			return true;
		}
	}

	return flag;
}


bool Inventory::returnproduct(int proid)
{

	bool flag = false;
	for (int i = 0; i < totalproducts; i++)
	{
		if (invproduct[i].pid == proid)
		{
			invproduct[i].quantity++;
			flag = true;
			cout << "Product Successfully Returned\n";
			return true;
		}
	}

	if (flag == false)
	{
		cout << "Unable To Return the Product\n";
		return false;
	}
}




bool Inventory::removeproduct(int proid)
{
	bool flag = false;
	for (int i = 0; i < totalproducts; i++)
	{
		if (invproduct[i].pid == proid)
		{
			invproduct[i].quantity--;
			flag = true;
			cout << "Product Successfully Removed : ";
			cout << "left articles of it are = " << invproduct[i].quantity << endl;
			return true;
		}
	}

	if (flag == false)
	{
		cout << "Unable To Remove the Product\n";
		return false;
	}
}

void Inventory::invRead() {
	cout << "READING FROM FILE";

	ifstream fin("inventory.txt");
	if (fin.is_open()) {

		int size = 0;





		fin >> size;
		for (int i = 0; i < size; i++) {


			int pid = 0;
			int quantity = 0;

			fin >> pid;
			fin >> quantity;

			if (totalproducts == 0) {

				invproduct = new inventoryproduct[totalproducts + 1];
				totalproducts++;

				invproduct[0].pid = pid;
				invproduct[0].quantity = quantity;
			}
			else if (totalproducts != 0) {
				expand<inventoryproduct>(invproduct, totalproducts);

				invproduct[totalproducts - 1].pid = pid;
				invproduct[totalproducts - 1].quantity = quantity;

			}

		}
		fin.close();
		/*obj.showcs();*/

	}

}

void Inventory::invWrite() {
	cout << "WRITING TO FILE";

	ofstream out;
	out.open("inventory.txt");
	out << totalproducts << endl;
	for (int i = 0; i < totalproducts; i++)
	{

		out << invproduct[i].pid << " " << invproduct[i].quantity << endl;
	}
	out.close();
}



