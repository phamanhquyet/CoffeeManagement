#include "AppCoffee.h"

void AppCoffee::readFileLog()
{
	ifstream fi("Log.txt");
	while (fi.good())
	{
		string log;
		getline(fi,log,'\n');
		if (log == "") {
			break;
		}
		LogOfSystem.push_back(log);
	}
	fi.close();
	
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
	for (int i = 0; i < listAcc.getListAccount().size(); i++) {
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
	    ofstream fo("Log.txt");
		string time = log.Time();
		cout << "WELCOME \"" << listAcc.getListAccount().at(index).getUsername() << "\" TO QUYETVJPPRO'S CAFE\n";
		cout << "TIME LOGIN: " << time << endl;
		string str1 = "User " + listAcc.getListAccount().at(index).getUsername() + " login into system at " + time;
		LogOfSystem.push_back(str1);
		cout << LogOfSystem.size();
		for (int i = 0; i < LogOfSystem.size(); i++) {
			fo << LogOfSystem.at(i)<<endl;
		}
		fo.close();
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
		cout << "|                               1. Them Nhan Vien                                     |\n";
		cout << "|                               2. Xoa Nhan Vien                                      |\n";
		cout << "|                               3. Sua Nhan Vien                                      |\n";
		cout << "|                               4. Tim Kiem Nhan Vien                                 |\n";
		cout << "|                               5. Danh Sach Nhan Vien                                |\n";
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
		case '1':
			listEmp.insert();
			system("pause");
			break;
			
		case '2':
			listEmp.deleteEmployee();
			system("pause");
			break;
		case '3':
			listEmp.editAnEmployee();
			system("pause");
			break;
		case '4':
			listEmp.HashDisplayByName();
			system("pause");
			break;
		case '5':
			listEmp.display();
			system("pause");
			break;
		case '6':
			listItems.insertAnItem();
			system("pause");
			break;
		case '7':
			listItems.DeleteAnItem();
			system("pause");
			break;
		case '8':
			listItems.EditAnItem();
			system("pause");
			break;
		case '9':
			listItems.HashDisplayByName();
			system("pause");
			break;
		case '0':
			listItems.display();
			system("pause");
			break;
		case 'e':
			return;
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
