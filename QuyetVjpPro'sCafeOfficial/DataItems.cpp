#include "DataItems.h"

DataItems::DataItems()
{
	readFile();
}

void DataItems::readFile()
{
	ifstream fi("ListItems.txt");
	while (!fi.eof()) {
		string str1, str2, str3;
		getline(fi, str1,',');
		getline(fi, str2, ',');
		getline(fi, str3, '\n');
		if (str1 == "" || str2 == ""||str3 == "") {
			break;
		}
		this->generateID += 1;
		long temp = stol(str3);
		Items it(str1, str2, temp);
		listItems.push_back(it);
	}
	fi.close();

}

void DataItems::insert(string nameOfItem, int price)
{
	string idOfItem = to_string(generateID);
	Items it(idOfItem,nameOfItem,price);
	listItems.push_back(it);
}

void DataItems::updateFIle()
{
	ofstream fo("ListItems.txt");
	for (int i = 0; unsigned (i)< listItems.size(); i++) {
		fo << listItems.at(i).getIdOfItem() << "," << listItems.at(i).getNameOfItem() << "," << listItems.at(i).getPrice() << endl;
	}
	fo.close();
}

void DataItems::display()
{
	cout << "-------------------------------------------------" << endl;
	cout << "| Id\t\t| Name\t\t| Price\t\t|" << endl;

	cout << "-------------------------------------------------" << endl;
	for (int i = 0; unsigned(i) < listItems.size(); i++) {
		listItems.at(i).display();
		
	}
	cout << "-------------------------------------------------" << endl;
}

int DataItems::findById(string id)
{
	int posOfId = -1;
	for (int i = 0; i < listItems.size(); i++) {
		if (listItems.at(i).getIdOfItem().compare(id) == 0) {
			posOfId = i;
			break;
		}
	}
	return posOfId;
}

vector<Items> DataItems::getListItems()
{
	return listItems;
}

int DataItems::findByName(string nameOfItem)
{
	int posOfName = -1;
	for (int i = 0; i < listItems.size(); i++) {
		if (listItems.at(i).getNameOfItem().compare(nameOfItem) == 0){
			posOfName = i;
			break;
		}
	}
	return posOfName;
}

void DataItems::HashDisplayByName(string name)
{
	bool flag = false;
	cout << "-------------------------------------------------" << endl;
	cout << "| Id\t\t| Name\t\t| Price\t\t|" << endl;

	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i < listItems.size(); i++) {
		if (listItems.at(i).getNameOfItem().find(name) != std::string::npos) {
			listItems.at(i).display();
			flag = true;
		}
	}
	if (flag == false) {
		cout <<setw(15)<< "Can't find!\t\t\t\t\t|" << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

DataItems::~DataItems()
{
	listItems.clear();
}
