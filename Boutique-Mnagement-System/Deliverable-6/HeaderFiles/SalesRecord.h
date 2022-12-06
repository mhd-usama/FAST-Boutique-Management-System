#pragma once
#include"Product.h"
class SalesRecord {
protected:
	int sId;

public:
	void updateSalesRecord(list<Product> r);

	void updatesales(Product*& p, int n); 

	void viewsalesrecord()
	{
		ifstream file;
		file.open("sales_record.txt");
		char ch;
		if (file)
		{
			char arr[50];
			while (!file.eof())
			{
				memset(arr, '\0', 50);
				file.getline(arr,50);
				cout << arr<<endl;
			}

			cout << endl;
			file.close();
		}
		else {
			cout << "Couldnot open file/n";
			return;
		}
	}
	
};
