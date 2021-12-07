#pragma once
#include "Account.h"
#include <iomanip>
#include <fstream>
#include <iostream>
class DataAccount
{
private:
	vector<Account> listAccount;
	int generateId = 1;
public:
	DataAccount();
	void readFile();
	void updateFile();
	void display();
	void findUserByUsername();
	vector<Account> getListAccount();

	~DataAccount();
};

