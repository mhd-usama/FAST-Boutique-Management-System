#ifndef SALESRECORD_H
#define SALESRECORD_H
#include "Product.h"
class SalesRecord :public Product {
private:
	int saleIde;
	string salePerson;
public:
	void displaySale();
};

#endif // !SALESRECORD_H

