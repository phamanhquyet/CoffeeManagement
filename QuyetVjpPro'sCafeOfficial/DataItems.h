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
	void insert(string nameOfItem, long price);
	void Delete(string nameOfItem);
	//void edit(string nameOfItem, long price);
	bool checkId(string id);
	void updateFIle();
	void display();
	int findById(string id);
	vector<Items>getListItems();
	int findByName(string nameOfItem);
	void HashDisplayByName();
	void insertAnItem();
	void DeleteAnItem();
	void EditAnItem();
	int getPartition(vector<Items>& givenArray, int low, int high);
	void quickSort(vector<Items>& givenArray, int low, int high);
	void Mysort();
	//destructor
	~DataItems();
};

