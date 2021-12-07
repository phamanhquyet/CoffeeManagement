#include "DataEmployee.h"

DataEmployee::DataEmployee()
{
    readFile();
}

void DataEmployee::readFile()
{
    ifstream fi("ListEmployee.txt");
    while (fi.good()) {
        string id, name, address, phoneNumber, day, month, year, basicSalary, bonus;
        getline(fi, id, ',');
        getline(fi, name, ',');
        getline(fi, address, ',');
        getline(fi, phoneNumber, ',');
        getline(fi, day, ',');
        getline(fi, month, ',');
        getline(fi, year, ',');
        getline(fi, basicSalary, ',');
        getline(fi, bonus, '\n');
        if (id == "" || name == "" || address == "" || phoneNumber == "" || day == "" || month == "" || year == "" || basicSalary == "" || bonus == "") {
            break;
        }
        this->generateId += 1;
        //56789
        int temp1 = stoi(day);
        int temp2 = stoi(month);
        int temp3 = stoi(year);
        int temp4 = stoi(basicSalary);
        int temp5 = stoi(bonus);
        Employee emp(id,name,address,phoneNumber,temp1,temp2,temp3,temp4,temp5);
        listEmployee.push_back(emp);
    }
    fi.close();
    
}


void DataEmployee::insert()
{
    string name, address, phone_number;
    int day, month, year, bonus;
    long basic_salary;
    string idOfEmployee = to_string(generateId);
    cin.ignore();
    cout << "Input Name: ";
    getline(cin, name);
    cout << "Input Address: ";
    getline(cin, address);
    cout << "Input PhoneNumber: ";
    getline(cin, phone_number);
    cout << "Input Day-Month-Year: ";
    cin >> day >> month >> year;
    cout << "Input Basic Salary: ";
    cin >> basic_salary;
    cout << "Input Bonus: ";
    cin >> bonus;
    Employee emp(idOfEmployee, name, address, phone_number, day, month, year, basic_salary, bonus);
    listEmployee.push_back(emp);
    updateFile();
}

void DataEmployee::updateFile()
{
    ofstream fo("ListEmployee.txt");
    for (int i = 0; unsigned(i) < listEmployee.size(); i++) {
         fo << listEmployee.at(i).getIdOfEmployee() << "," << listEmployee.at(i).getPerson().getName() << ","
            << listEmployee.at(i).getPerson().getAddress() << "," << listEmployee.at(i).getPerson().getPhoneNumber() << ","
            << listEmployee.at(i).getPerson().getDateOfBirth().getDay() << "," << listEmployee.at(i).getPerson().getDateOfBirth().getMonth() << ","
            << listEmployee.at(i).getPerson().getDateOfBirth().getYear() << "," << listEmployee.at(i).getBasicSalary() << ","
            << listEmployee.at(i).getBonus()<<endl;
    }
    fo.close();
}

void DataEmployee::deleteEmployee()
{
    int index = -1;
    string name;
    cin.ignore();
    cout << "Input Name: ";
    getline(cin, name);
    for (int i = 0; i < listEmployee.size(); i++) {
        if (listEmployee.at(i).getPerson().getName().compare(name) == 0) {
            index = i;
            listEmployee.erase(listEmployee.begin() + index);
            cout << "DONE!\n";
        }
        updateFile();
    }
    if (index == -1) {
        cout << "NULL!\n";
    }
}

void DataEmployee::display()
{
    cout << setw(100) << "List of employees are working at Quyet Vjp Pro's Cafe" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| Id\t\t| Name\t\t\t| Address\t\t| Phone Number\t\t| Day\t| Month\t| Year\t| Basic Salary\t| Bonus\t\t|" << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; unsigned(i) < listEmployee.size(); i++) {
        listEmployee.at(i).display();

    }
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

int DataEmployee::findById(string id)
{
    int posOfId = -1;
    for (int i = 0; i < listEmployee.size(); i++) {
        if (listEmployee.at(i).getIdOfEmployee().compare(id) == 0) {
            posOfId = i;
            break;
        }
    }
    return posOfId;
}

int DataEmployee::findByName(string name)
{
    int posOfName = -1;
    for (int i = 0; i < listEmployee.size(); i++) {
        if (listEmployee.at(i).getPerson().getName().compare(name) == 0) {
            posOfName = i;
            break;
        }
    }
    return posOfName;
}

vector<Employee> DataEmployee::getListEmployee()
{
    return listEmployee;
}

void DataEmployee::HashDisplayByName()
{
    string name;
    cin.ignore();
    cout << "Input Name: ";
    getline(cin, name);
    bool flag = false;
    cout << "+---------------+-----------------------+-----------------------+-----------------------+-------+-------+-------+---------------+---------------+" << endl;
    cout << "| Id\t\t| Name\t\t\t| Address\t\t| Phone Number\t\t| Day\t| Month\t| Year\t| Basic Salary\t| Bonus\t\t|" << endl;
    cout << "+---------------+-----------------------+-----------------------+-----------------------+-------+-------+-------+---------------+---------------+" << endl;
    for (int i = 0; i < listEmployee.size(); i++) {
        if (listEmployee.at(i).getPerson().getName().find(name) != string::npos) {
            listEmployee.at(i).display();
            flag = true;
        }
    }
    if (flag == false) {
        cout << "| NULL\t\t| NULL\t\t\t| NULL\t\t\t| NULL\t\t\t| NULL\t| NULL\t| NULL\t| NULL\t\t| NULL\t\t|" << endl;
    }
    cout << "+---------------+-----------------------+-----------------------+-----------------------+-------+-------+-------+---------------+---------------+" << endl;
}

DataEmployee::~DataEmployee()
{
    listEmployee.clear();
}
