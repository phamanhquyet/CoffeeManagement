#include "AppCoffee.h"

void AppCoffee::readFileLog()
{
	ifstream fi("Log.txt",ios::in);
	while (!fi.eof())
	{
		string log;
		getline(fi, log, '\n');
		if (log == "") {
			break;
		}
		LogOfSystem.push_back(log);
	}
	fi.close();
	
}

void AppCoffee::updateFileLog()
{
	ofstream fo("Log.txt");
	for (int i = 0; (unsigned)i < LogOfSystem.size(); i++) {
		fo << LogOfSystem.at(i)<<endl;
	}
}



void AppCoffee::login()
{
	readFileLog();
	string username;
	string password;
	cout << "INPUT USERNAME: ";
	getline(cin, username);
	cout << "INPUT PASSWORD: ";
	getline(cin, password);
	//cout << listAcc.getListAccount().size();
	for (int i = 0; (unsigned)i < listAcc.getListAccount().size(); i++) {
		if ((listAcc.getListAccount().at(i).getUsername().compare(username) == 0) && (listAcc.getListAccount().at(i).getPassword().compare(password)) == 0) {
			cout << "Access!\n";
			system("cls");
			this->index = i;
		}
	}
	if (index == -1) {
		cout << "Wrong!\n";
		login();
		return;
	}
	else {
		vector<string>::iterator it;
		it = LogOfSystem.begin();
		string time = log.Time();
		time.erase(time.end()-1);
		cout << "WELCOME \"" << listAcc.getListAccount().at(index).getUsername() << "\" TO QUYETVJPPRO'S CAFE\n";
		cout << "TIME LOGIN: " << time << endl;
		string str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" login into system at " + time;
		LogOfSystem.insert(it,str1);
		updateFileLog();
	}
	if (listAcc.getListAccount().at(index).getPermisstion() == "admin") {
		cout << "PERMISSION: " << listAcc.getListAccount().at(index).getPermisstion() << endl;;
		showCaseAdmin();
	}	
	else if (listAcc.getListAccount().at(index).getPermisstion() == "employee") {
		cout << "PERMISSION: " << listAcc.getListAccount().at(index).getPermisstion() << endl;
		showCaseEmployee();
	}
	else
		return;
}

void AppCoffee::showCaseAdmin()
{
	char key;
	//cout << "\n";
	while (true)
	{
		cout << "+-------------------------------------MENU ADMIN--------------------------------------+\n";
		cout << "|                               1. Add an Employee                                    |\n";
		cout << "|                               2. Remove an Employee                                 |\n";
		cout << "|                               3. Edit an Employee                                   |\n";
		cout << "|                               4. Find an Employee                                   |\n";
		cout << "|                               5. List of Employee's information                     |\n";
		cout << "|                               6. Them Item                                          |\n";
		cout << "|                               7. Xoa Item                                           |\n";
		cout << "|                               8. Sua Item                                           |\n";
		cout << "|                               9. Tim Item                                           |\n";
		cout << "|                               0. Danh Sach Item                                     |\n";
		cout << "|                               e. Thoat                                              |\n";
		cout << "+-------------------------------------------------------------------------------------+\n";
		cout << "\nINPUT BUTTON: ";
		cin >> key;
		switch (key)
		{
		case '1': {
			listEmp.insert();
			vector<string>::iterator it;
			it = LogOfSystem.begin();
			string str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" add an employee to system has id \'" + listEmp.getIdTemp() + "\' at " + log.Time();
			str1.erase(str1.end() - 1);
			LogOfSystem.insert(it, str1);
			updateFileLog();
			system("pause");
			break;
		}
		case '2':{
			if (listEmp.deleteEmployee() > -1) {
				vector<string>::iterator it;
				it = LogOfSystem.begin();
				string str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" delete an employee has id \'" + listEmp.getIdTemp() + "\' from system at " + log.Time();
				str1.erase(str1.end() - 1);
				LogOfSystem.insert(it, str1);
				updateFileLog();
			}
			system("pause");
			break;
		}
		case '3': {
			if (listEmp.editAnEmployee() >-1) {
				vector<string>::iterator it;
				it = LogOfSystem.begin();
				string str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" edit an employee has id \'" + listEmp.getIdTemp() + "\' from system at " + log.Time();
				str1.erase(str1.end() - 1);
				LogOfSystem.insert(it, str1);
				updateFileLog();
			}
			system("pause");
			break;
		}
		case '4': {
			listEmp.HashDisplayByName();
			system("pause");
			break;
		}
		case '5': {
			listEmp.display();
			system("pause");
			break;
		}
		case '6': {
			listItems.insertAnItem();
			vector<string>::iterator it;
			it = LogOfSystem.begin();
			string str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" add an item to system has id \'" + listItems.getIdTemp() + "\' named \""+ listItems.getNameTemp() + "\" at " + log.Time();
			str1.erase(str1.end() - 1);
			LogOfSystem.insert(it, str1);
			updateFileLog();
			system("pause");
			break;
		}
		case '7': {
			listItems.DeleteAnItem();
			if (listItems.getIndexTemp() > -1) {
				vector<string>::iterator it;
				it = LogOfSystem.begin();
				string str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" delete an item named \'" + listItems.getNameTemp() + "\' from system at " + log.Time();
				str1.erase(str1.end() - 1);
				LogOfSystem.insert(it, str1);
				updateFileLog();
			}
			system("pause");
			break;
		}
		case '8': {
			if (listItems.EditAnItem() > -1) {
				string str1;
				vector<string>::iterator it;
				it = LogOfSystem.begin();
				if (listItems.getOldName().compare(listItems.getNewName()) != 0) {
					if (listItems.getOldPrice() == listItems.getNewPrice()) {
						 str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" edit an item named \"" + listItems.getOldName() + "\" to \"" + listItems.getNewName() + "\" and keep the same price of item at " + log.Time();
					}
					else {
						 str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" edit an item named \"" + listItems.getOldName() + "\" to \"" + listItems.getNewName() + "\" and edit the price from " + to_string(listItems.getOldPrice()) + " to " + to_string(listItems.getNewPrice()) + " at " + log.Time();
					}
				}
				else {
					if (listItems.getOldPrice() == listItems.getNewPrice()) {
						 str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" access edit an item feature but do not edit and keep the information at " + log.Time();
					}
					else {
						 str1 = "User: \"" + listAcc.getListAccount().at(index).getUsername() + "\" keep the name of \"" + listItems.getOldName() + "\" and edit the price from " + to_string(listItems.getOldPrice()) + " to " + to_string(listItems.getNewPrice()) + " at " + log.Time();
					}
				}
				str1.erase(str1.end() - 1);
				LogOfSystem.insert(it, str1);
				updateFileLog();
			}
			system("pause");
			break;
		}
		case '9': {
			listItems.HashDisplayByName();
			system("pause");
			break;
		}
		case '0': {
			listItems.display();
			system("pause");
			break;
		}
		case 'e': {
			return;
		}
		default:
			break;
		}
		system("cls");
	}
}

void AppCoffee::showCaseEmployee()
{
	char key;
	while (true) {
		cout << "\t\t\t\tQuyetVjpPro's Cafe Menu"<<endl;
		listItems.display();
		cout << "+-------------------------------------MENU EMPLOYEE-----------------------------------+\n";
		cout << "|                               1. Them & Tinh Bill                                   |\n";
		cout << "|                               2. Xoa Bill                                           |\n";
		cout << "|                               3. Sua Bill                                           |\n";
		cout << "|                               4. Tim Kiem Bill                                      |\n";
		cout << "|                               5. Hien thi Bill                                      |\n";
		cout << "|                               e. Thoat                                              |\n";
		cout << "+-------------------------------------------------------------------------------------+\n";
		cout << "\nINPUT BUTTON: ";
		cin >> key;
		switch (key)
		{
		case '1': {
			emp.createBill();
			system("pause");
			break;
		}
		case '2':
			listItems.DeleteAnItem();
			system("pause");
			break;
		case '3':
			listItems.EditAnItem();
			system("pause");
			break;
		case '4':
			listItems.HashDisplayByName();
			system("pause");
			break;
		case '5':{
			string id;
			cout << "Enter id of bill: ";
			cin.ignore();
			getline(cin, id);
			emp.exportBill(id);
			system("pause");
			break;
		}
		case 'e':
			return;
		default:
			break;
		}
		system("cls");
	}
	
}
