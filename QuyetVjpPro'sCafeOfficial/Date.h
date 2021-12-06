#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int day, int month, int year);
	//getter
	int getDay();
	int getMonth();
	int getYear();
	//setter
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
};

