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

bool DataEmployee::checkId(string id)
{
    bool flag = false;
    for (auto i = 0; i < listEmployee.size(); i++) {
        if (listEmployee.at(i).getIdOfEmployee().compare(id) == 0) {
            this->generateId += 1;
            flag = true;
            break;
        }
    }
    return flag;
}


void DataEmployee::insert()
{
    string name, address, phone_number;
    int day, month, year, bonus;
    long basic_salary;
    this->generateId = 1;
    plus1ToId:
    string idOfEmployee = to_string(generateId);
    if (checkId(idOfEmployee)) {
        goto plus1ToId;
    }
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

void DataEmployee::Delete(string id)
{
    int pos = findById(id);
    if (pos == -1){
        cout<<"can't find this employee"<<endl;
        return;
    }
    listEmployee.erase(listEmployee.begin() + pos);
    this->generateId += 1;

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

void DataEmployee::editAnEmployee()
{
    string oldID;
    string IdOfEmployee;
    string nameOfEmployeeWantToEdit;
    string addressWantToEdit;
    string phoneNumberOfEmployeeWantToEdit;
    int day, month, year;
    long basicSalary;
    int bonus;
    cout << "Enter id of employee: ";
    cin.ignore();
    getline(cin, IdOfEmployee);

    int pos = findById(IdOfEmployee);
    if (pos > -1) {
        oldID = listEmployee.at(pos).getIdOfEmployee();
        bonus = listEmployee.at(pos).getBonus();
        Delete(IdOfEmployee);
        cout << "Enter name you want to edit to: ";
        getline(cin, nameOfEmployeeWantToEdit);
        handleString(nameOfEmployeeWantToEdit);
        cout << "Enter address you want to edit to: ";
        getline(cin, addressWantToEdit);
        handleString(addressWantToEdit);
        cout << "Enter phone number you want to edit to: ";
        getline(cin, phoneNumberOfEmployeeWantToEdit);
        cout << "Enter Day-Month-Year you want to edit to: ";
        cin >> day >> month >> year;
        cout << "Enter basic salary you want to edit to: ";
        cin >> basicSalary;
        Employee emp(oldID, nameOfEmployeeWantToEdit, addressWantToEdit,phoneNumberOfEmployeeWantToEdit, day, month, year, basicSalary, bonus);
        listEmployee.insert(listEmployee.begin() + pos, emp);
        
        cout << "Success!" << endl;
        updateFile();
    }
    else {
        cout << "Can't find this employee!" << endl;
    }
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

void DataEmployee::handleString(string& str)
{
    while (str[0] == ' ')
    {
        str.erase(str.begin() + 0);
    }
    while (str[str.length() - 1] == ' ')
    {
        str.erase(str.begin() + str.length() - 1);
    }
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        //65 90
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    if (str[0] != ' ')
    {
        if (str[0] >= 97 && str[0] <= 122)
        {
            str[0] -= 32;
        }

    }
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {

            if (str[i + 1] >= 97 && str[i + 1] <= 122)
            {
                str[i + 1] -= 32;
            }
        }
    }
}

DataEmployee::~DataEmployee()
{
    listEmployee.clear();
}
