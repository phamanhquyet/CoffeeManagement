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
		cout << "WELCOME \"" << listAcc.getListAccount().at(index).getUsername() << "\" TO QUYETVJPPRO'S CAFE\n";
		cout << "TIME LOGIN: " << log.Time() << endl;
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
			break;
			
		case '2':
			listEmp.deleteEmployee();
			break;
		case '3':
			break;
		case '4':
			listEmp.HashDisplayByName();
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
		cout << "+-------------------------------------MENU ADMIN--------------------------------------+\n";
		cout << "|                               1. Them & Tinh Bill                                   |\n";
		cout << "|                               2. Xoa Bill                                           |\n";
		cout << "|                               3. Sua Bill                                           |\n";
		cout << "|                               4. Tim Kiem Bill                                      |\n";
		cout << "|                               5. Danh Sach Bill                                     |\n";
		cout << "|                               e. Thoat                                              |\n";
		cout << "+-------------------------------------------------------------------------------------+\n";
		cout << "\nINPUT BUTTON: ";
		cin >> key;
		switch (key)
		{
		case '1': {
			emp.addBill();
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
		case '5':
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
