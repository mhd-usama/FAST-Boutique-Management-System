#ifndef PHYSICALBOUTIQUE_H
#define PHYSICALBOUTIQUE_H
#include "Boutique.h"
class PhysicalBoutique : public Boutique {
private:
	string storeName;
	string storeLocation;
	int storeNumber;
	string storeTimings;
public:
	void storeDetails();
};
#endif // !PHYSICALBOUTIQUE_H

