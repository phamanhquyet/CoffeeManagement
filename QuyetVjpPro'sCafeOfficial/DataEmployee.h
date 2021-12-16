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
	bool checkId(string id);
	void insert();
	void Delete(string id);
	void updateFile();
	void editAnEmployee();
	void deleteEmployee();
	void display();
	int findById(string id);
	int findByName(string name);
	vector<Employee>getListEmployee();
	void HashDisplayByName();
	void handleString(string& str);
	int getPartition(vector<Employee>& givenArray, int low, int high);
	void quickSort(vector<Employee>& givenArray, int low, int high);
	void Mysort();
	//goi toi tinh tien cua Employee (id)
	//...
	~DataEmployee();
};

