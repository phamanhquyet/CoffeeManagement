#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "DataAccount.h"
#include "DataEmployee.h"
#include "Log_Time.h"
#include "DataItems.h"
#include "Items.h"
#include "Employee.h"
using namespace std;
class AppCoffee
{
private:
	int index = -1;
	DataAccount listAcc;
	DataEmployee listEmp;
	DataItems listItems;
	Log_Time log;
	Items it;
	Employee emp;
	vector<string>LogOfSystem;
public:
	void readFileLog();
	void login();
	void showCaseAdmin();
	void showCaseEmployee();
};

