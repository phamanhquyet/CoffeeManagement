#include "AppCoffee.h"

void AppCoffee::login()
{
	string username;
	string password;
	cout << "INPUT USERNAME: ";
	getline(cin, username);
	cout << "INPUT PASSWORD: ";
	getline(cin, password);
	//cout << listAcc.getListAccount().size();
	for (int i = 0; i < listAcc.getListAccount().size(); i++) {
		if ((listAcc.getListAccount().at(i).getUsername().compare(username) == 0) && (listAcc.getListAccount().at(i).getPassword().compare(password)) == 0) {
			cout << "Access!\n";
			this->index = i;
		}
	}
	if (index == -1) {
		cout << "Wrong!\n";
		return;
	}
	else
		cout << "WELCOME \"" << listAcc.getListAccount().at(index).getUsername() << "\" TO QUYETVJPPRO'S CAFE\n";
}
