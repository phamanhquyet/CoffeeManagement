#include "Account.h"

Account::Account()
{
	this->id = "";
	this->username = "";
	this->password = "";
	this->permission = "employee";
}

Account::Account(string id, string username, string password, string permission)
{
	this->id = id;
	this->username = username;
	this->password = password;
	this->permission = permission;
}

string Account::getID()
{
	return this->id;
}

string Account::getUsername()
{
	return this->username;
}

string Account::getPassword()
{
	return this->password;
}

string Account::getPermisstion()
{
	return this->permission;
}

void Account::setID(string id)
{
	this->id = id;
}

void Account::setUsername(string username)
{
	this->username = username;
}

void Account::setPassword(string password)
{
	this->password = password;
}

void Account::setPermisstion(string permission)
{
	this->permission = permission;
}

void Account::display()
{
	cout << "| " << setw(5) << left << id << "\t\t| " << setw(15) << username << "\t| " << setw(15) << password << "\t| " << setw(14) << permission << "|" << endl;
}
