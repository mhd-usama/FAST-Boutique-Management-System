#ifndef RETURNPRODUCT_H
#define RETURNPRODUCT_H
#include "Product.h"
class ReturnProduct :public Product {
private:
	int salesId;
	string dateOfPurchase;
public:
	bool returnProduct(int productId);

};
#endif // !RETURNPRODUCT_H

