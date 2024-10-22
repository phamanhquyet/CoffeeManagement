#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
using namespace std;
class Items
{
private:
	string idOfItem;
	string nameOfItem;
	long price;
	long amount;
	string idBill;
public:
	Items();
	Items(string idOfItem, string nameOfItem, long price);
	Items(string idOfItem, string nameOfItem, long price, long amount, string idBill);
	//getter
	string getIdOfItem();
	string getNameOfItem();
	long getPrice();
	long getAmount();
	string getIdBill();
	//setter
	void setIdOfItem(string idOfItem);
	void setNameOfItem(string nameOfItem);
	void setPrice(long price);
	void setAmount(long amount);
	void setIdBill(string idBill);
	long total();
	//method
	void display();
	void displaybyBill();
};

