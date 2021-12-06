#pragma once
#include "Employee.h"
class DataEmployee
{
private:
	vector<Employee>listEmployee;
	int generateId = 1;
public:
	DataEmployee();
	void readFile();
	void insert(string name, string address, string phone_number, int day, int month, int year, long basic_salary, int bonus);
	void updateFile();
	void display();
	int findById(string id);
	int findByName(string name);
	vector<Employee>getListEmployee();
	void HashDisplayByName(string name);
	
	//goi toi tinh tien cua Employee (id)
	//...
	~DataEmployee();
};

