#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "DataAccount.h"
using namespace std;
class AppCoffee
{
private:
	int index = -1;
	DataAccount listAcc;
public:
	void login();
};

