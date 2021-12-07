#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "DataAccount.h"
#include "DataEmployee.h"
using namespace std;
class AppCoffee
{
private:
	int index = -1;
	DataAccount listAcc;
	DataEmployee listEmp;
public:
	void login();
	void showCaseAdmin();
	void showCaseEmployee();
};

