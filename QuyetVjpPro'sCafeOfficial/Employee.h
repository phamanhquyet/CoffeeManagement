#pragma once
#include "Person.h"
#include "FunctionInterface.h"
#include <vector>
class Employee:Person
{
private:
	string idOfEmployee;
	long basic_salary;
	int bonus;
	Person p;

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
	//tinh tien
	//....
};

