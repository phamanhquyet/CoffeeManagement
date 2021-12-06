#include "Person.h"

Person::Person():date_of_birth()
{
	this->name = "";
	this->address = "";
	this->phone_number = "";
}

Person::Person(string name, string address, string phone_number, int day, int month, int year):date_of_birth(day,month,year)
{
	this->name = name;
	this->address = address;
	this->phone_number = phone_number;
}

string Person::getName()
{
	return name;
}

string Person::getAddress()
{
	return address;
}

string Person::getPhoneNumber()
{
	return phone_number;
}

Date Person::getDateOfBirth()
{
	return date_of_birth;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setAddress(string address)
{
	this->address;
}

void Person::setPhoneNumber(string phone_number)
{
	this->phone_number;
}

void Person::setDateOfBirth(Date date_of_birth)
{
	this->date_of_birth = date_of_birth;
}
