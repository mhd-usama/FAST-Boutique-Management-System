#include"SalesRecord.h"
void SalesRecord::updateSalesRecord(list<Product> r) {
	ofstream out;
	out.open("sales_record.txt", ios::app);

	srand(time(nullptr));
	int id = rand() % 200;

	list<Product>::iterator iter;
	for (iter = r.begin(); iter != r.end(); ++iter) {
		out << "Sales Id: " << id << " " << "Product Id: " << iter->get_productid();
		out << endl;
	}
	out.close();
}



void SalesRecord::updatesales(Product*& p, int n) {
	ofstream out; int pid = -1;
	out.open("sales_record.txt", ios::app);

	srand(time(nullptr));
	int id = rand() % 200;
	cout << "Enter Product ID Sold : ";
	cin >> pid; bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (pid == p[i].get_productid())
		{
			flag = false;
			out << "Sales Id: " << id << " " << "Product Id: " << pid << endl;
			out.close();
			cout << "Successfully updated Sales Record\n";
			break;
		}

		if (flag)
		{
			cout << "Unable to update Sales Record\n";
		}
	}

}