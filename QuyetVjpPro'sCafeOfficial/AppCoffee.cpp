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
		cout << "|\t\t\t\t1. Them Nhan Vien" << setw(39) << "|\n";
		cout << "|\t\t\t\t2. Xoa Nhan Vien" << setw(40) << "|\n";
		cout << "|\t\t\t\t3. Sua Nhan Vien" << setw(40) << "|\n";
		cout << "|\t\t\t\t4. Tim Kiem Nhan Vien" << setw(35) << "|\n";
		cout << "|\t\t\t\t5. Danh Sach Nhan Vien" << setw(34) << "|\n";
		cout << "|\t\t\t\t6. Them Item" << setw(44) << "|\n";
		cout << "|\t\t\t\t7. Xoa Item" << setw(45) << "|\n";
		cout << "|\t\t\t\t8. Sua Item" << setw(45) << "|\n";
		cout << "|\t\t\t\t9. Tim Item" << setw(45) << "|\n";
		cout << "|\t\t\t\t0. Danh Sach Item" << setw(39) << "|\n";
		cout << "|\t\t\t\te. Thoat" << setw(48) << "|\n";
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
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		case '9':
			break;
		case '0':
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
	cout << "+-------------------------------------MENU EMPLOYEE------------------------------------+\n";
	cout << "|\t\t\t\t1. Them Item" << setw(44) << "|\n";
	cout << "|\t\t\t\t2. Xoa Item" << setw(45) << "|\n";
	cout << "|\t\t\t\t3. Sua Item" << setw(45) << "|\n";
	cout << "|\t\t\t\t4. Tim Item" << setw(45) << "|\n";
	cout << "|\t\t\t\t5. Danh Sach Item" << setw(39) << "|\n";
	cout << "+-------------------------------------------------------------------------------------+\n";

}
