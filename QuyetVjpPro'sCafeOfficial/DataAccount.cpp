#include "DataAccount.h"

DataAccount::DataAccount()
{
	readFile();
}

void DataAccount::readFile()
{
	ifstream fi("ListAccount.txt");
	while (fi.good())
	{
		string id, username, password, permission;
		getline(fi, id, ',');
		getline(fi, username, ',');
		getline(fi, password, ',');
		getline(fi, permission, '\n');
		if (id == "" || username == "" || password == "" || permission == "")
			break;
		this->generateId += 1;
		Account acc(id, username, password, permission);
		listAccount.push_back(acc);
	}
	fi.close();
}

void DataAccount::updateFile()
{
	ofstream fo("ListEmployee.txt");
	for (int i = 0; unsigned(i) < listAccount.size(); i++) {
		fo << listAccount.at(i).getID() << "," << listAccount.at(i).getPassword() << "," << listAccount.at(i).getPassword() << "," << listAccount.at(i).getPermisstion() << endl;
	}
	fo.close();
}

void DataAccount::display()
{
	cout << setw(68) << "LIST ACCOUNTS QUYETVJPPRO'S CAFE OFFICIAL" << endl;
	cout << "+---------------+-----------------------+-----------------------+---------------+" << endl;
	cout << "| ID\t\t| Username\t\t| Password\t\t| Permission\t|" << endl;
	cout << "+---------------+-----------------------+-----------------------+---------------+" << endl;
	for (int i = 0; unsigned(i) < listAccount.size(); i++) {
		listAccount.at(i).display();
	}
	cout << "+---------------+-----------------------+-----------------------+---------------+" << endl;
}

void DataAccount::findUserByUsername()
{
	string username;
	cout << "INPUT USERNAME: ";
	cin >> username;
	cout << setw(50) << "FIND USER BY USERNAME" << endl;
	cout << "+---------------+-----------------------+-----------------------+---------------+" << endl;
	cout << "| ID\t\t| Username\t\t| Password\t\t| Permission\t|" << endl;
	cout << "+---------------+-----------------------+-----------------------+---------------+" << endl;
	bool flag = false;
	for (int i = 0; (unsigned)i < listAccount.size(); i++) {
		if (listAccount.at(i).getUsername().find(username) != string::npos ){
			listAccount.at(i).display();
			flag = true;
			cout << "+---------------+-----------------------+-----------------------+---------------+" << endl;
			break;
		}
	}
	if (flag == false) {
		cout << "| NULL\t\t| NULL\t\t\t| NULL\t\t\t| NULL\t\t|" << endl;
		cout << "+---------------+-----------------------+-----------------------+---------------+" << endl;
	}
}

vector<Account> DataAccount::getListAccount()
{
	return listAccount;
}

DataAccount::~DataAccount()
{
	listAccount.clear();
}
