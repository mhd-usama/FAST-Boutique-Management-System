#include <SFML/Graphics.hpp> 
#include<SFML/System.hpp>

#include<iostream>
#include"Person.h"
#include"Employee.h"
#include"floormanagers.h"
#include"Inventory.h"
#include"Product.h"
#include"StoreManager.h"
#include"SalesRecord.h"
#include"productmanagment.h"
#include"Customer.h"
#include"Admin.h"
#include"InventoryManager.h"

using namespace std;
using namespace sf;

//class of login (An Interface)
class login {
public:

	bool login_customer(Customer*& E, int n, int& index)
	{

		system("CLS");
		string id; string pwrd;
		cout << "Enter User ID: ";
		cin >> id;
		cout << "Enter Password: ";
		cin >> pwrd;

		bool flag = false;

		for (int i = 0; i < n; i++)
		{
			if (id == E[i].get_id() && pwrd == E[i].get_pwrd())
			{
				flag = true;
				index = i;
				cout << "Successfully Logged In \n";
				return true;
			}
		}

		if (flag == false)
		{
			cout << "Incorrect Id or Password Entered \n";

			return false;
		}

	}
	bool login_employee(Employee*& E, int n, int& index)
	{

		system("CLS");
		string id; string pwrd;
		cout << "Enter Employee ID: ";
		cin >> id;
		cout << "Enter Password: ";
		cin >> pwrd;

		bool flag = false;

		for (int i = 0; i < n; i++)
		{
			if (id == E[i].get_id() && pwrd == E[i].get_pwrd())
			{
				flag = true;
				index = i;
				cout << "Successfully Logged In \n";
				return true;
			}
		}

		if (flag == false)
		{
			cout << "Incorrect Id or Password Entered \n";

			return false;
		}

	}

};

//some functions to avoid coupling and These are actually Wrapper Functions
bool product_purchase(Product*& p, int products, Inventory*& inv1, productmanagment pm)
{
	pm.set_inventory(inv1);

	//	pm.productpurchase(1);

	if (pm.operation(products, p))
	{
		return true;
	}

	else
	{
		return false;
	}
}

void storeflooremployees(Employee*&E, int num, int& count, floormanager*& f)
{
	for (int i = 0; i < num; i++)
	{
		if (E[i].designation == "FloorManager")
		{
			int floor = count + 1;
			f[count++].set_manager(E[i], floor);
		}
	}
}

void store_storeemployee(Employee*&E, int num, int& count, StoreManager*& f)
{
	for (int i = 0; i < num; i++)
	{
		if (E[i].designation == "StoreManager")
		{
			int store = count + 1;
			f[count++].set_manager(E[i], store);
		}
	}
}

void store_salesagent(Employee*& E, int num, int& count, SalesAgent*& f)
{
	count = 0;
	for (int i = 0; i < num; i++)
	{
		if (E[i].designation == "SalesAgent")
		{
			int store = count + 1;
			f[count++].setmanager(E[i]);
		}
	}
}




//checktypeof employee
int  type_employee(Employee* E, int n, string id)
{
	int type = -1;
	for (int i = 0; i < n; i++)
	{
		if (E[i].get_id() == id)
		{
			if (E[i].designation == "StoreManager")
			{
				type = 1; break;
			}

			else if (E[i].designation == "FloorManager")
			{
				type = 2; break;
			}

			else if (E[i].designation == "SalesAgent")
			{
				type = 3; break;
			}
			else if (E[i].designation == "Admin")
			{
				type = 4; break;
			}
			else if (E[i].designation == "InventoryManager")
			{
				type = 5; break;
			}
			else
			{
				type = 6; break;
			}
		}
	}

	return type;
}





//-------------------------GOOD BYE SCREEN & SALE SCREEN-------------------------------//

int sale()
{

	sf::RenderWindow window(sf::VideoMode(1200, 800), "WELCOME TO FAST NUCES BOUTIQUE SYSTEM");

	Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		return 0;
	}
	sf::Text text("\n\n			   ORDER CONFIRMED \n\n\n\n\n\n\n\n\n\n Your Order Will Arrive in 2 to 3 Days\n\n\n\n\n", font);
	// text.setFont(font);
	text.setCharacterSize(44);
	text.Underlined;
	text.setStyle(sf::Text::Bold);
	// text.setStyle(sf::Text::Underlined);
	text.setFillColor(Color::Red);

	sf::Image Img;
	sf::Texture t;
	sf::Sprite playerimg;

	if (!t.loadFromFile("yend.jpg"))
	{
		return -1;
	}
	playerimg.setTexture(t);
	
	playerimg.setPosition(10, 10);
	//  text.setString("Usman");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if ((event.type == (sf::Event::KeyPressed)) || event.type == sf::Event::Closed || event.type == sf::Event::MouseButtonPressed) {

				window.close();
				window.clear();
				//  fun();
				return 0;

			}
		}

		window.clear(Color::White);
		window.draw(playerimg);
		//window.draw(text);
		window.display();
	}
}
int purchasing()
{

	sf::RenderWindow window(sf::VideoMode(1200, 800), "WELCOME TO FAST NUCES BOUTIQUE SYSTEM");

	Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		return 0;
	}
	sf::Text text("\n\n			   ORDER CONFIRMED \n\n\n\n\n\n\n\n\n\n Your Order Will Arrive in 2 to 3 Days\n\n\n\n\n", font);
	// text.setFont(font);
	text.setCharacterSize(44);
	text.Underlined;
	text.setStyle(sf::Text::Bold);
	// text.setStyle(sf::Text::Underlined);
	text.setFillColor(Color::Red);

	sf::Image Img;
	sf::Texture t;
	sf::Sprite playerimg;

	if (!t.loadFromFile("purchase.png"))
	{
		return -1;
	}
	playerimg.setTexture(t);
	playerimg.setPosition(290, 200);
	//  text.setString("Usman");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if ((event.type == (sf::Event::KeyPressed)) || event.type == sf::Event::Closed || event.type == sf::Event::MouseButtonPressed) {

				window.close();
				window.clear();
				//  fun();
				return 0;
				
			}
		}

		window.clear(Color::White);
		window.draw(playerimg);
		window.draw(text);
		window.display();
	}
}
int goodbye()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "WELCOME TO FAST NUCES BOUTIQUE SYSTEM");

	Font font;
	if (!font.loadFromFile("COOPBL.ttf"))
	{
		return 0;
	}
	sf::Text text("\n\n  THANKS FOR VISITING FAST BOUTIQUE \n\n\n\n  HAVE A NICE DAY ! \n\n\n\n", font);
	// text.setFont(font);
	text.setCharacterSize(44);
	text.Underlined;
	text.setStyle(sf::Text::Bold);
	// text.setStyle(sf::Text::Underlined);
	text.setFillColor(Color::Cyan);

	sf::Image Img;
	sf::Texture t;
	sf::Sprite playerimg;

	if (!t.loadFromFile("th.png"))
	{
		return -1;
	}
	playerimg.setTexture(t);
	playerimg.setPosition(290, 400);
	//  text.setString("Usman");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if ((event.type == (sf::Event::KeyPressed)) || event.type == sf::Event::Closed || event.type == sf::Event::MouseButtonPressed) {

				window.close();
				window.clear();
				//  fun();
				return 0;
				//    window.draw(text);

					// window.display();

			}


		}

		window.clear(Color::Transparent);
		window.draw(playerimg);
		window.draw(text);
		window.display();
	}

}
int welcome()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "WELCOME TO FAST NUCES BOUTIQUE SYSTEM");

    Font font;
    if (!font.loadFromFile("COOPBL.ttf"))
    {
        return 0;
    }
    sf::Text text("\n\n\n        WELCOME TO FAST NUCES  BOUTIQUE  \n\n\n\n        We serve All Ladies, Gents Variety\n\n\n\n", font);
    // text.setFont(font);
    text.setCharacterSize(44);
    text.Underlined;
    text.setStyle(sf::Text::Bold);
    // text.setStyle(sf::Text::Underlined);
    text.setFillColor(Color::Blue);

    sf::Image Img;
    sf::Texture t;
    sf::Sprite playerimg;

    if (!t.loadFromFile("Online.png"))
    {
        return -1;
    }
    playerimg.setTexture(t);
    playerimg.setPosition(290, 400);
	sf::Image Imge;
	sf::Texture te;
	sf::Sprite playerimge;

	if (!te.loadFromFile("fast.png"))
	{
		return -1;
	}
	playerimge.setTexture(te);
	playerimge.setPosition(290, 10);
    //  text.setString("Usman");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if ((event.type == (sf::Event::KeyPressed)) || event.type == sf::Event::Closed || event.type == sf::Event::MouseButtonPressed) {

                window.close();
                window.clear();
              //  fun();
				return 0;
                //    window.draw(text);

                    // window.display();

            }


        }

        window.clear(Color::White);
        window.draw(playerimg);
		window.draw(playerimge);
        window.draw(text);
        window.display();
    }

}



//-----------------------------------------------------------------------------------//




int main()
{
    welcome();
	

	cout << "Press 0 for Employee\n";
	cout << "Press 1 for Customer\n";
	int type = 0;
	cin >> type;
	//------------------------------------------------------DATA----------------------------------------------------------------------
	productmanagment pm;

	int products = 6;

	Product* p = new Product[products];
	p[0].setproduct(0, "Kurta", "Black", 5000, 0, 909090);
	p[1].setproduct(1, "Sherwani", "White", 10000, 30, 0);
	p[2].setproduct(2, "2 Piece Ladies Suit", "Pink", 4000, 20, 300);
	p[3].setproduct(3, "Kurta", "Black", 5000, 0, 909090);
	p[4].setproduct(4, "Sherwani", "White", 10000, 30, 0);
	p[5].setproduct(5, "2 Piece Ladies Suit", "Pink", 4000, 20, 300);

	productfiles fp; int po = 0;
//	fp.writeproduct(p, products);
	int* discounts = new int[products];
	int dd = products;
	fp.fileread(discounts, products);
	for (int i = 0; i < dd; i++)
	{
		p[i].setdisc(discounts[i]);
	}



	Inventory* inv1 = new Inventory();
	
	inv1->invRead();

	login d;


	Employee* emps = nullptr;

	cfilewrite cust; fileRead cread;

	efileRead empfile;
	int num = 0;
	empfile.empRead(emps, num);
	cout << "total employees read are:" << num << endl;
	int fm = 0;
	efilewrite e_write;
	//emps[0].printdetails();

	SalesAgent* sa = nullptr;
	sa = new SalesAgent[num];
	int sc = 1;
	store_salesagent(emps, num, sc, sa);

	floormanager* y = new floormanager[num];
	storeflooremployees(emps, num, fm, y);
	StoreManager* x = new StoreManager[num];
	int sm = 0;
	store_storeemployee(emps, num, sm, x);


	int type2 = 0;
	int i = -1;


	Customer* e = nullptr;
	int q = 0;
	cread.cusRead(e, q);
	//---------------------------------------------------------------------------------------------------------


	//----------------------------------------------FUNCTIONALITY OF EMPLOYEE AND CUSTOMER -------------------------------------------

	//EMPLOYYEEE
	if (type == 0)
	{

		d.login_employee(emps, num, i);
		if (i != -1)
		{
			string e_id = emps[i].get_id();

			cout << "Welcome " << e_id << endl;
			//types case

			if (type_employee(emps, num, e_id) == 2)
			{
				floormanager temp;
				cout << "FloorManager\n";

				for (int j = 0; j < fm; j++)
				{
					if (y[j].get_id() == e_id)
					{
						temp = y[j];
						break;
					}
				}

				temp.operation(inv1,sa,sc);

				system("CLS");
				cout << "logged Out\n";
				goodbye();
				exit(0);
			}

			else if (type_employee(emps, num, e_id) == 1)
			{
				cout << "StoreManager\n";
				StoreManager temp;
				//	cout << "FloorManager\n";
				system("CLS");
				for (int j = 0; j < sm; j++)
				{
					if (x[j].get_id() == e_id)
					{
						temp = x[j];
						break;
					}
				}

				temp.operation(p, products);
				fp.writeproduct(p, products);
				system("CLS");
				cout << "logged Out\n";
				goodbye();
				exit(0);

			}

			else if (type_employee(emps, num, e_id) == 3)
			{
				cout << "SalesAgent\n";

				SalesAgent agent; int t = 0;
				agent.setmanager(emps[i]);
				while (1)
				{
					system("CLS");
					cout << "***************** SALES AGENT *****************\n";
					cout << "Press 1 to View All Sales of Store \n";
					cout << "Press 2 to Update Sales Record\n";
					cout << "Press 3 to View Your Work-Shift\n";
					cout << "Press -1 to Exit\n";
					cin >> t;
					if (t == 1)
					{
						agent.getSales();
						Sleep(4000);
					}
					else if (t == 2)
					{
						agent.addSales(p, products);
					}
					else if (t == 3)
					{
						system("CLS");
						cout << "***************** WORK_SHIFT *****************\n";
						cout << " WORK SHIFT = " << agent.getshift() << endl;
						Sleep(4000);
					}

					else if (t == -1)
					{

						system("CLS");
						cout << "logged Out\n";
						goodbye();
						return 1;
					}

				}
			}
			else if (type_employee(emps, num, e_id) == 4)
			{
				cout << "StoreAdmin\n";
				admin B;
				string adid = emps[i].get_id();
				for (int j = 0; j < num; j++)
				{
					if (adid == emps[i].get_id())
					{
						B.set_admin(emps[i], 3);

					}
				}

				system("CLS");
				int k = 0;
				while (1)
				{
					system("CLS");
					cout << "Press 1 to Add Employee\n";
					cout << "Press 2 to Remove an  Employee\n";
					cout << "Press 3 to Add a Customer \n";
					cout << "Press 4 to Remove a Customer\n";
					cout << "Press 5 to View All Customer \n";
					cout << "Press 6 to View All Employees \n";
					cout << "Press -1 to Logout\n";
					cin >> k;
					if (k == 1)
					{
						B.add_employee(emps, num);

					}
					else if (k == 2)
					{
						B.remove_employee(emps, num);
					}

					else if (k == 3)
					{
						B.add_customer(e, q);
					}
					else if (k == 4)
					{
						B.removecustomer(e, q);
					}
					else if (k == 5)
					{
						B.viewallcustomers(e, q);
						Sleep(4000);
					}
					else if (k == 6)
					{
						B.viewallemployes(emps, num);
						Sleep(4000);
					}

					else if (k == -1)
					{

						//writing back all
						cust.cuswrite(e, q);
						e_write.empwrite(emps, num);
						system("CLS");

						//SetCursorPos(400, 400);
						cout << "Logging Out ...\n";
						cout << "Good Bye \n";
						goodbye();
						return 0;
					}

				}
			}

			else if (type_employee(emps, num, e_id) == 5)
			{



				InventoryManager w;
				string adid = emps[i].get_id();
				string in = inv1->getname();

				w.set_manager(emps[i], in);

				while (1)
				{
					system("CLS");
					cout << "*************************** Inventory Manager **************************************\n";
					cout << "Press 1 to ADD PRODUCT(s)\n";
					cout << "Press 2 to REMOVE PRODUCT\n";
					cout << "Press 3 to VIEW INVENTORY\n";

					cout << "Press 4 to Delete Product From Inventory\n";
					cout << "Press -1 to LOGOUT\n";
					int cd = 0;
					cin >> cd;
					if (cd == 1)
					{
						int quantity = 1;
						w.add_products(inv1, p, products, quantity);
						Sleep(4000);
					}

					if (cd == 2)
					{
						int pid = 0;
						w.remove_products(inv1, pid);
						Sleep(4000);
					}

					if (cd == 3)
					{
						w.viewinventory(inv1);
						Sleep(4000);
					}

					if (cd == 4)
					{
						w.deleteproduct(inv1);
					}

					if (cd == -1)
					{
						inv1->invWrite();
						system("CLS");

						//SetCursorPos(400, 400);
						cout << "Logging Out ...\n";
						cout << "Good Bye \n";
						goodbye();
						return 0;
					}
				}


			}

		}
	}
	//	g.write_to_file(g);*/



		//Customers Loading
	if (type == 1)
	{

		int cindex = -1; int opt = -1;

		while (1)
		{
			system("CLS");
			if (opt != -1)
				cout << "Incorrect ID or Password Was Entered\n";
			cout << "Press 0 to Exit \n";
			cout << "Press 1 to login \n";
			cout << "Press 2 to SignUp\n";
			cin >> opt;
			if (opt == -1)
			{
				exit(0);
			}
			else if (opt == 1)
			{

				if (d.login_customer(e, q, cindex))
				{
					system("CLS");
					cout << "Welcome    " << e[cindex].get_id() << endl;
					//system("pause");

					int a = -1;

					while (1)
					{
						cout << "Press 0 to Purchase a Product\n";
						cout << "Press 1 to exit Fast Boutique\n";
						cin >> a;
						if (a == 0)
						{

							sale();
							if (product_purchase(p, products, inv1, pm))
							{
								system("CLS");
								purchasing();
								inv1->invWrite();
							}
							else
							{
								system("CLS");

							}
							return 0;
						}

						else
						{


							cout << "Good Bye " << e[cindex].get_id() << endl;
							cout << "Visit Us Again, Have  A Nice Day\n";

							cust.cuswrite(e, q);
							inv1->invWrite();
							system("CLS");
							goodbye();
							return 1;
						}

					}
					break;
				}
				else
				{
					cout << "Incorrect ID or Password Was Entered\n";
				}


			}

			else if (opt == 2)
			{
				Customer temp;
				temp.createAccount(e, q);
				//writing back all
				cust.cuswrite(e, q);
			}
			else if (opt == 0)
			{
				goodbye();
				break;
			}
		}



	}
	//


	int index = -1;
	login l;
	



	//PRoduct _ Purchase
	return 0;
}