#include "DataItems.h"

DataItems::DataItems()
{
	readFile();
}

string DataItems::getIdTemp()
{
	return idTemp;
}

string DataItems::getNameTemp()
{
	return nameTemp;
}

long DataItems::getOldPrice()
{
	return oldPrice;
}

long DataItems::getNewPrice()
{
	return newprice;
}

int DataItems::getIndexTemp()
{
	return indexTemp;
}

string DataItems::getOldName()
{
	return oldName;
}

string DataItems::getNewName()
{
	return newName;
}

void DataItems::readFile()
{
	ifstream fi("ListItems.txt");
	while (!fi.eof()) {
		string str1, str2, str3;
		getline(fi, str1,'|');
		getline(fi, str2, '|');
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

void DataItems::insert(string nameOfItem, long price)
{
	string idOfItem = to_string(generateID);
	Items it(idOfItem,nameOfItem,price);
	listItems.push_back(it);
	this->nameTemp = nameOfItem;
}

void DataItems::Delete(string nameOfItem)
{
	int position = -1;
	for (int i = 0; (unsigned)i < listItems.size(); i++) {
		if (listItems.at(i).getNameOfItem().compare(nameOfItem) == 0) {
			position = i;
			this->nameTemp = nameOfItem;
			break;
		}
	}
	if (position > -1) {
		listItems.erase(listItems.begin() + position);
		cout << "Success!" << endl;
	}
	else {
		cout << "Can't find this item!" << endl;;
	}
	this->indexTemp = position;
}

//void DataItems::edit(string nameOfItem, long price)
//{
//	int position = -1;
//	for (int i = 0; i < listItems.size(); i++) {
//		if (listItems.at(i).getNameOfItem().compare(nameOfItem) == 0 && listItems.at(i).getPrice() == price) {
//			position = i;
//			break;
//		}
//	}
//	/*if (position > -1) {
//		
//	}*/
//	listItems.at(position).setNameOfItem(nameOfItem);
//	listItems.at(position).setPrice(price);
//	/*else {
//		cout << "Can't find your item! " << endl;
//	}*/
//}

bool DataItems::checkId(string id)
{
	bool flag = false;
	for (auto i = 0; (unsigned)i < listItems.size(); i++) {
		if (listItems.at(i).getIdOfItem().compare(id) == 0) {
			this->generateID += 1;
			flag = true;
			break;
		}
	}
	return flag;
}

void DataItems::updateFIle()
{
	ofstream fo("ListItems.txt");
	for (int i = 0; unsigned (i)< listItems.size(); i++) {
		fo << listItems.at(i).getIdOfItem() << "|" << listItems.at(i).getNameOfItem() << "|" << listItems.at(i).getPrice() << endl;
	}
	fo.close();
}

void DataItems::display()
{
	cout << "+---------------+-----------------------+---------------+" << endl;
	cout << "| Id\t\t| Name\t\t\t| Price\t\t|" << endl;

	cout << "+---------------+-----------------------+---------------+" << endl;
	for (int i = 0; unsigned(i) < listItems.size(); i++) {
		listItems.at(i).display();
		
	}
	cout << "+---------------+-----------------------+---------------+" << endl;
}

int DataItems::findById(string id)
{
	int posOfId = -1;
	for (int i = 0; (unsigned)i < listItems.size(); i++) {
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
	for (int i = 0; (unsigned)i < listItems.size(); i++) {
		if (listItems.at(i).getNameOfItem().compare(nameOfItem) == 0){
			posOfName = i;
			break;
		}
	}
	return posOfName;
}

void DataItems::HashDisplayByName()
{
	string name;
	cout << "Enter the name of item you want to find: ";
	cin.ignore();
	getline(cin,name);
	bool flag = false;
	cout << "+---------------+-----------------------+---------------+" << endl;
	cout << "| Id\t\t| Name\t\t\t| Price\t\t|" << endl;

	cout << "+---------------+-----------------------+---------------+" << endl;
	for (int i = 0; (unsigned)i < listItems.size(); i++) {
		if (listItems.at(i).getNameOfItem().find(name) != std::string::npos) {
			listItems.at(i).display();
			flag = true;
		}
	}
	if (flag == false) {
		cout <<"| " << setw(15) << "Can't find!\t\t\t\t\t\t|" << endl;
	}
	cout << "+---------------+-----------------------+---------------+" << endl;
}

void DataItems::insertAnItem()
{
	this->generateID = 1;
	plusToId:
	string idOfItem = to_string(generateID);
	if (checkId(idOfItem)) {
		goto plusToId;
		
	}
	this->idTemp = idOfItem;
	string nameOfItem;
	long price;
	inputName:
	bool flagForName = false;
	cout << "Enter name of item: ";
	cin.ignore();
	getline(cin, nameOfItem);
	for (int i = 0; (unsigned)i < nameOfItem.length(); i++) {
		if ((nameOfItem[i] != 32 && nameOfItem[i] >= 0 && nameOfItem[i] <= 43) || (nameOfItem[i] >= 58 && nameOfItem[i] <= 64) || (nameOfItem[i] >= 91 && nameOfItem[i] <= 96) || (nameOfItem[i] >= 123 && nameOfItem[i] <= 255)) {
			cout << "Character \"" << nameOfItem[i] << "\" is invalid! ";
			flagForName = true;
			break;
		}
	}
	if (flagForName == true) {
		cout << "Please re-enter" << endl;
		goto inputName;
	}
	fflush(stdin);
	do {
		cout << "Enter price: ";
		cin >> price;
		if (price <= 0) {
			cout << "Invalid! Please re-enter" << endl;
		}
	} while (price <= 0);
	insert(nameOfItem, price);
	Mysort();
	updateFIle();
}

void DataItems::DeleteAnItem()
{
	string nameOfItem;
	cout << "Enter name of Item: ";
	cin.ignore();
	getline(cin, nameOfItem);
	fflush(stdin);
	Delete(nameOfItem);
	updateFIle();
}

int DataItems::EditAnItem()
{
	string nameOfItem;
	string nameOfItemWantToEdit;
	long priceWantToEdit;
	cout << "Enter name of item: ";
	cin.ignore();
	getline(cin, nameOfItem);

	int pos = findByName(nameOfItem);
	
	if (pos > -1) {
		this->oldPrice = listItems.at(pos).getPrice();
		this->oldName = nameOfItem;
		inputName:
		bool flagForName = false;
		cout << "Enter name you want to edit to: ";
		getline(cin, nameOfItemWantToEdit);
		for (int i = 0; (unsigned)i < nameOfItemWantToEdit.length(); i++) {
			if ((nameOfItemWantToEdit[i] != 32 && nameOfItemWantToEdit[i] >= 0 && nameOfItemWantToEdit[i] <= 43) || (nameOfItemWantToEdit[i] >= 58 && nameOfItemWantToEdit[i] <= 64) || (nameOfItemWantToEdit[i] >= 91 && nameOfItemWantToEdit[i] <= 96) || (nameOfItemWantToEdit[i] >= 123 && nameOfItemWantToEdit[i] <= 255)) {
				cout << "Character \"" << nameOfItemWantToEdit[i] << "\" is invalid! ";
				flagForName = true;
				break;
			}
		}
		if (flagForName == true) {
			cout << "Please re-enter" << endl;
			goto inputName;
		}
		do {
			cout << "Enter price you want to edit to: ";
			cin >> priceWantToEdit;
			if (priceWantToEdit <= 0) {
				cout << "Invalid! Please re-enter" << endl;
			}
		} while (priceWantToEdit <= 0);

		this->newprice = priceWantToEdit;
		listItems.at(pos).setNameOfItem(nameOfItemWantToEdit);
		this->newName = listItems.at(pos).getNameOfItem();
		listItems.at(pos).setPrice(priceWantToEdit);
		cout << "Success!" << endl;
		updateFIle();
		return pos;
	}
	else {
		cout << "Can't find this item!"<<endl;
		cout << pos << endl;
		return -1;
	}
}

int DataItems::getPartition(vector<Items>& givenArray, int low, int high)
{
	int pivot = stoi(givenArray[high].getIdOfItem());
	int i = (low - 1);
	for (int j = low; j <= high; j++) {
		int tmp = stoi(givenArray[j].getIdOfItem());
		if (tmp < pivot) {
			i++;
			swap(givenArray[i], givenArray[j]);
		}
	}
	swap(givenArray[i + 1], givenArray[high]);
	return (i + 1);
}

void DataItems::quickSort(vector<Items>& givenArray, int low, int high)
{
	if (low < high) {
		int pi = getPartition(givenArray, low, high);
		quickSort(givenArray, low, pi - 1);
		quickSort(givenArray, pi + 1, high);
	}
}

void DataItems::Mysort()
{
	quickSort(this->listItems, 0, listItems.size() - 1);
}



DataItems::~DataItems()
{
	listItems.clear();
}
