#include "Employee.h"

Employee::Employee():Person()
{
	this->idOfEmployee = "";
	this->basic_salary = 0;
	this->bonus = 0;
}



Employee::Employee(string idOfEmployee, string name, string address, string phone_number, int day, int month, int year, long basic_salary, int bonus):p(name,address,phone_number,day,month,year)
{
	this->idOfEmployee = idOfEmployee;
	this->basic_salary = basic_salary;
	this->bonus = bonus;
}

Person Employee::getPerson()
{
	return p;
}

string Employee::getIdOfEmployee()
{
	return idOfEmployee;
}

long Employee::getBasicSalary()
{
	return basic_salary;
}

int Employee::getBonus()
{
	return bonus;
}

void Employee::setIdOfEmployee(string idOfEmployee)
{
	this->idOfEmployee = idOfEmployee;
}

void Employee::setBasicSalary(long basic_salary)
{
	this->basic_salary = basic_salary;
}

void Employee::setBonus(int bonus)
{
	this->bonus = bonus;
}

void Employee::input()
{
}

void Employee::display()
{
	cout << "| " << setw(5) << left << idOfEmployee << "\t\t\| " << setw(15) << p.getName() << "\t| " << setw(15) << p.getAddress() << "\t| " << setw(15)<<p.getPhoneNumber() << "\t| " <<setw(5) << p.getDateOfBirth().getDay() << "\t| " << setw(5) << p.getDateOfBirth().getMonth()<< "\t| "<<setw(5)<< p.getDateOfBirth().getYear()<<"\t| " << setw(10)<<basic_salary<<"\t| " << setw(10) << bonus << "\t| "<<endl;
}




