//#include "DataAccount.h"
#include "AppCoffee.h"
#include <iostream>
#include"Employee.h"
int main()
{
	//DataAccount dt;
	//dt.findUserByUsername();
	/*AppCoffee app;
	app.login();*/
	Employee m;
	m.addBill("tra sua", 2, "1");
	m.addBill("tra sua", 4, "1");
	m.addBill("tra sua", 2, "2");
	m.displayBill("2");
	cout << "--------------"<<endl;
	cout << m.totalBill("2");
	return 0;
}

