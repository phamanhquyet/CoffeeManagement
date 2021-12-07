#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
class Account
{
private:
	string id;
	string username;
	string password;
	string permission;

public:
	Account();
	Account(string id, string username, string password, string permission);

	string getID();
	string getUsername();
	string getPassword();
	string getPermisstion();

	void setID(string id);
	void setUsername(string username);
	void setPassword(string password);
	void setPermisstion(string permission);

	void display();
};
