#pragma once
#include "Items.h"
class DataItems
{
private:
	vector<Items>listItems;
	int generateID = 1;
	string idTemp;
	string nameTemp;
	int indexTemp = -1;
	string oldName;	
	string newName;
	long oldPrice;
	long newprice;
	
public:
	DataItems();
	string getIdTemp();
	string getNameTemp();
	long getOldPrice();
	long getNewPrice();
	int getIndexTemp();
	string getOldName();
	string getNewName();
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
	int EditAnItem();
	int getPartition(vector<Items>& givenArray, int low, int high);
	void quickSort(vector<Items>& givenArray, int low, int high);
	void Mysort();
	//destructor
	~DataItems();
};

