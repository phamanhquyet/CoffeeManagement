#include"DataItems.h"
#include"DataEmployee.h"
#include <iostream>
int main()
{
	DataEmployee dt;
	string name;
	getline(cin,name);
	dt.HashDisplayByName(name);
	//string id;
	//cout << "Nhap id cua san pham: ";
	//cin >> id;
	//dt.getListItems().at(dt.findByName("banh quy")).display();
	//cout << dt.getListItems().size() << endl;;
	//dt.getListItems().at(dt.findById(id)).display();
	//dt.display();
	cout << "done!";
	cout << "ICVJppro";
	return 0;
}

