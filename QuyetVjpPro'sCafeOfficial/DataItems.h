#pragma once
#include "Items.h"
class DataItems
{
private:
	vector<Items>listItems;
	int generateID = 1;
public:
	DataItems();
	void readFile();
	void insert(string nameOfItem, int price);
	void updateFIle();
	void display();
	int findById(string id);
	vector<Items>getListItems();
	int findByName(string nameOfItem);
	void HashDisplayByName(string name);
	//destructor
	~DataItems();
};

