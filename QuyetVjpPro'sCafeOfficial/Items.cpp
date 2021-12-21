#include "Items.h"

Items::Items()
{
	this->idOfItem = "";
	this->nameOfItem = "";
	this->price = 0;
	this->amount = 0;
	this->idBill = "";
}

Items::Items(string idOfItem, string nameOfItem, long price)
{
	this->idOfItem = idOfItem;
	this->nameOfItem = nameOfItem;
	this->price = price;
}

Items::Items(string idOfItem, string nameOfItem, long price, long amount, string idBill)
{
	this->idOfItem = idOfItem;
	this->nameOfItem = nameOfItem;
	this->price = price;
	this->amount = amount;
	this->idBill = idBill;
}

string Items::getIdOfItem()
{
	return idOfItem;
}

string Items::getNameOfItem()
{
	return nameOfItem;
}

int Items::getPrice()
{
	return price;
}

long Items::getAmount()
{
	return amount;
}

string Items::getIdBill()
{
	return idBill;
}

void Items::setIdOfItem(string idOfItem)
{
	this->idOfItem = idOfItem;
}

void Items::setNameOfItem(string nameOfItem)
{
	this->nameOfItem = nameOfItem;
}

void Items::setPrice(int price)
{
	this->price = price;
}

void Items::setAmount(long amount)
{
	this->amount = amount;
}

void Items::setIdBill(string idBill)
{
	this->idBill = idBill;
}

long Items::total()
{
	return getAmount()*getPrice();
}

void Items::display()
{

	cout<< "| "<<setw(5) << left << idOfItem << "\t\t| " << setw(20) << nameOfItem << "\t| " << setw(10) << price << "\t|" << endl;
	
}

void Items::displaybyBill()
{
	cout << "+---------------+---------------+---------------+-------+---------------+\n";
	cout << "|ID BILL        | NAMEOFITEM    | PRICE         | AMOUNT| TOTAL         |\n";
	cout << "+---------------+---------------+---------------+-------+---------------+\n";
	cout << "| " << setw(5) << left << this->idBill  << "\t\t| " << setw(10) << nameOfItem << "\t| " << setw(10) << price << "\t| " << setw(5) << this->amount << "\t|" << setw(10) << total() << "\t|\n";
	cout << "+---------------+---------------+---------------+-------+---------------+\n";

}
