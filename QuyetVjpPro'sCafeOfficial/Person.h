#pragma once
#include "Date.h"
#include <string>
#include<iomanip>
#include <fstream>
#include <iostream>
#include <vector>
class Person
{
private:
	string name;
	string address;
	string phone_number;
	Date date_of_birth;
public:
	Person();
	Person(string name , string address, string phone_number, int day, int month, int year);
	//getter
	string getName();
	string getAddress();
	string getPhoneNumber();
	Date getDateOfBirth();
	//setter
	void setName(string name);
	void setAddress(string address);
	void setPhoneNumber(string phone_number);
	void setDateOfBirth(Date date_of_birth);
};

