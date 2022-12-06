#include"Customer.h"
#include<string.h>


Customer::Customer() {
	cusSize = 0;
}



string Customer::get_id() {
	return id;
}


string Customer::get_pwrd() {
	return password;
}
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

void Customer::createAccount(Customer*& c, int& n) {

	string password;
	string name; string cnic; string id; string customertype; string ph; string add;

	cout << "\nEnter NAME (FIRST NAME ONLY):";
	cin >> name;
	
	cout << "\nEnter CNIC: ";
	cin >> cnic;
	cout << "\nEnter AGE: ";
	cin >> age;
	while (age <= 16)
	{
		cout << "\nEnter AGE";
		cin >> age;
	}
	cout << "\nEnter PHONENUMBER:";
	cin >> ph;
	cout << "\nEnter ADDRESS ";
	cin >> add;
	bool flag = true;
	while (flag) {
		cout << "\nEnter Customer ID ";
		cin >> id;
		for (int i = 0; i < n; i++)
		{
			if (id == c[i].get_id())
			{
				cout << "User ID Already Taken Enter a new One \n";
				flag = true;
				break;
			}

			else {
				flag = false;
			}
		}

	}

	customertype = "Registered";

	cout << "Enter Account Password\n";
	cin >> password;

	while (password.length() <= 3)
	{
		cout << "Enter  Accounnt Password\n";
		cin >> password;
	}

	expand(c, n);

	c[n - 1].set_data(name, cnic, id, password, customertype, ph, add);

	cout << "Sucessfully Added User \n";
	cout << "Here Are the Credenttials \n";
	c[n - 1].print();
}
void Customer::print()
{
	cout << "Name: "<< this->name << "  CNIC: " << this->cnic << "  User ID: " << this->id << " \n Address: " << this->address << " Phone Num: " << this->phonenum << " Customer Type: " << this->customerType << endl;
}

void Customer::set_data(string name, string cnic, string id,string password, string customertype, string phone, string add)
{
	this->name = name;
	this->cnic = cnic;
	this->address = add;
	this->id = id;
	this->password = password;
	this->customerType = customertype;
	this->phonenum = phone;
}

void Customer::get_data(string& name, string& cnic, string& id, string& password,string& customertype, string& phone, string& add)
{
	name = this->name;
	cnic = this->cnic;
	add = this->address;
	id = this->id;
	password = this->password;
	customertype = this->customerType;
	phone = this->phonenum;
}

void cfilewrite::cuswrite(Customer*& C, int num) {
	cout << "Adding New Customer In Database" << endl;

	ofstream out;
	out.open("customer.txt");
	out << num << endl;
	for (int i = 0; i < num; i++){
		string password;
		string name; string cnic; string id; string customertype; string phone; string add;
		C[i].get_data(name,cnic,id,password,customertype,phone,add);
		cout << name << " " << cnic << " " << id << " " << add << " " << phone << " " << customertype << endl;
		out << name << " " << cnic << " " << id << " " << password<<" " << add << " " << phone << " " << customertype << endl;
	}

	out.close();
}

void fileRead::cusRead(Customer*& C, int& num) {

	ifstream fin("customer.txt");
	if (fin.is_open()) {
		fin >> num;
		C = new Customer[num];
		int size = num;

		string name;  string cnic; string id; string customertype; string phone; string add;
		string password;
		for (int i = 0; i < size; i++) {
			name = '\0';
			cnic = '\0';
			id = '\0';
			password = '\0';
			customertype = '\0';
			phone = '\0';
			add = '\0';

			fin >> name;
			fin >> cnic;
			fin >> id;
			fin >> password;
			fin >> add;
			fin >> phone;
			fin >> customertype;
			
			

			if (cusSize == 0) {

				C = new Customer[cusSize + 1];
				cusSize++;

				C[0].set_data(name, cnic, id, password,customertype, phone, add);
			}
			else if (cusSize != 0) {
				expand<Customer>(C, cusSize);

				C[cusSize - 1].set_data(name, cnic, id,password, customertype, phone, add);
			}

		}
		fin.close();
		/*obj.showcs();*/

	}
}
