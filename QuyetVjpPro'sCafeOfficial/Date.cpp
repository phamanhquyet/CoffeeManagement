#include "Date.h"

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay()
{
	if (this->day < 0 || this->day > maxDay(this->month, this->year))
		return 1;

	else
		return this->day;
}

int Date::getMonth()
{
	if (this->month < 0 || this->month > 12)
		return 1;
	else
		return this->month;
}

int Date::getYear()
{
	if (this->year < 1900 || this->year > 2500)
		return 1900;
	else
		return this->year;
}


void Date::setDay(int day)
{
	this->day = day;

}
void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::maxDay(int month, int year)
{
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			return 29;
		else
			return 28;
		break;
	}
}
