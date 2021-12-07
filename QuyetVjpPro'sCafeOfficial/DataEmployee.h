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
	void insert();
	void updateFile();
	void deleteEmployee();
	void display();
	int findById(string id);
	int findByName(string name);
	vector<Employee>getListEmployee();
	void HashDisplayByName();
	
	//goi toi tinh tien cua Employee (id)
	//...
	~DataEmployee();
};

