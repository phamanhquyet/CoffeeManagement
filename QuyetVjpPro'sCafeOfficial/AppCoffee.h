#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "DataAccount.h"
#include "DataEmployee.h"
#include "Log_Time.h"
using namespace std;
class AppCoffee
{
private:
	int index = -1;
	DataAccount listAcc;
	DataEmployee listEmp;
	Log_Time log;
public:
	void login();
	void showCaseAdmin();
	void showCaseEmployee();
};

