#ifndef ONLINEBOUTIQUE
#define ONLINEBOUTIQUE
#include "Boutique.h"
class OnlineBoutique : public Boutique {
private:
	string website;
public:
	void viewBoutique();
	void manageOrders();
};

#endif // !ONLINEBOUTIQUE


