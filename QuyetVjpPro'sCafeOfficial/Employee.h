#pragma once
#include "Person.h"
#include "FunctionInterface.h"
#include <vector>
#include"Items.h"
#include"DataItems.h"
class Employee:Person,public DataItems
{
private:
	string idOfEmployee;
	long basic_salary;
	int bonus;
	Person p;
	vector<Items> Bill;
	
public:
	Employee();
	Employee(string idOfEmployee, string name, string address, string phone_number, int day, int month, int year, long basic_salary, int bonus);
	Person getPerson();
	string getIdOfEmployee();
	long getBasicSalary();
	int getBonus();
	void setIdOfEmployee(string idOfEmployee);
	void setBasicSalary(long basic_salary);
	void setBonus(int bonus);
	void input();
	void display();
	//----------------Bill----------------------//
	void createBill();
	long totalBill(string idBill);
	void displayBill(string idBill);
	void readBill();
	void exportBill(string idBill);
	~Employee();
};

