#include "DataEmployee.h"

DataEmployee::DataEmployee()
{
    readFile();
}

string DataEmployee::getIdTemp()
{
    return idTemp;
}

void DataEmployee::readFile()
{
    ifstream fi("ListEmployee.txt");
    while (fi.good()) {
        string id, name, address, phoneNumber, day, month, year, basicSalary, bonus;
        getline(fi, id, '|');
        getline(fi, name, '|');
        getline(fi, address, '|');
        getline(fi, phoneNumber, '|');
        getline(fi, day, '|');
        getline(fi, month, '|');
        getline(fi, year, '|');
        getline(fi, basicSalary, '|');
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
void DataEmployee::updateFile()
{
    ofstream fo("ListEmployee.txt");
    for (int i = 0; unsigned(i) < listEmployee.size(); i++) {
        fo << listEmployee.at(i).getIdOfEmployee() << "|" << listEmployee.at(i).getPerson().getName() << "|"
            << listEmployee.at(i).getPerson().getAddress() << "|" << listEmployee.at(i).getPerson().getPhoneNumber() << "|"
            << listEmployee.at(i).getPerson().getDateOfBirth().getDay() << "|" << listEmployee.at(i).getPerson().getDateOfBirth().getMonth() << "|"
            << listEmployee.at(i).getPerson().getDateOfBirth().getYear() << "|" << listEmployee.at(i).getBasicSalary() << "|"
            << listEmployee.at(i).getBonus() << endl;
    }
    fo.close();
}

bool DataEmployee::checkId(string id)
{
    bool flag = false;
    for (auto i = 0; (unsigned)i < listEmployee.size(); i++) {
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
    string day, month, year;
    int dayOfBirth, monthOfBirth, yearOfBirth;
    string bonusTemp, basicSalaryTemp;
    int bonus;
    long basic_salary;
    this->generateId = 1;
    plus1ToId:
    string idOfEmployee = to_string(generateId);
    if (checkId(idOfEmployee)) {
        goto plus1ToId;
    }
   
    cin.ignore();
    inputName:
    bool flagForName = false;
    cout << "Input Name: ";
    getline(cin, name);
    for (int i = 0; (unsigned)i < name.length(); i++) {
        if ((name[i] != 32 && name[i] >= 0 && name[i] <= 64) || (name[i] >= 91 && name[i] <= 96) || (name[i] >= 123 && name[i] <= 255)) {
            cout << "Character \"" << name[i] << "\" is invalid! ";
            flagForName = true;
            break;
        }
    }
    if (flagForName == true) {
        cout << "Please re-enter" << endl;
        goto inputName;
    }
    handleString(name);
    inputAddress:
    bool flagForAddress = false;
    cout << "Input Address: ";
    getline(cin, address);
    for (int i = 0; (unsigned)i < address.length(); i++) {
        if ((address[i] != 32 && address[i] >= 0 && address[i] <= 43) || (address[i] >= 58 && address[i] <= 64) || (address[i] >= 91 && address[i] <= 96) || (address[i] >= 123 && address[i] <= 255)) {
            cout << "Character \"" << address[i] << "\" is invalid! ";
            flagForAddress = true;
            break;
        }
    }
    if (flagForAddress == true) {
        cout << "Please re-enter" << endl;
        goto inputAddress;
    }
    handleString(address);
    inputPhoneNumber:
    bool flagForPhoneNumber = false;
    cout << "Input PhoneNumber: ";
    getline(cin, phone_number);
    for (int i = 0; (unsigned)i < phone_number.length(); i++) {
        if (phone_number[i] < 48 || phone_number[i] > 57) {
            cout << "Number \"" << phone_number[i] << "\" is invalid! ";
            flagForPhoneNumber = true;
            break;
        }
    }
    if (flagForPhoneNumber == true) {
        cout << "Please re-enter" << endl;
        goto inputPhoneNumber;
    }
    do {
        inputDayOfBirth:
        bool flagForDateOfBirth = false;
        cout << "Input Day Of Birth: ";
        
        getline(cin, day);
        
        for (int i = 0;(unsigned) i < day.length(); i++) {
            if (day[i] < 48 || day[i] > 57) {
                cout << "Character '" << day[i] << "' is invalid! ";
                flagForDateOfBirth = true;
                break;
            }
        }
        if (flagForDateOfBirth == true) {
            cout << "Please re-enter" << endl;
            goto inputDayOfBirth;
        }
        dayOfBirth = stoi(day);
        inputMonthOfBirth:
        bool flagForMonthOfBirth = false;
        cout << "Input Month Of Birth: ";
        getline(cin, month);
        for (int i = 0; (unsigned)i < month.length(); i++) {
            if (month[i] < 48 || month[i] > 57) {
                cout << "Character '" << month[i] << "' is invalid! ";
                flagForMonthOfBirth = true;
                break;
            }
        }
        if (flagForMonthOfBirth == true) {
            cout << "Please re-enter" << endl;
            goto inputMonthOfBirth;
        }
        monthOfBirth = stoi(month);
        inputYearOfBirth:
        bool flagForYearOfBirth = false;
        cout << "Input Year Of Birth: ";
        getline(cin, year);
        for (int i = 0; (unsigned)i < year.length(); i++) {
            if (year[i] < 48 || year[i] > 57) {
                cout << "Character '" << year[i] << "' is invalid! ";
                flagForYearOfBirth = true;
                break;
            }
        }
        if (flagForYearOfBirth == true) {
            cout << "Please re-enter" << endl;
            goto inputYearOfBirth;
        }
        yearOfBirth = stoi(year);
        if (dayOfBirth > emp.getPerson().getDateOfBirth().maxDay(monthOfBirth, yearOfBirth) || (monthOfBirth < 0 || monthOfBirth > 12) || (yearOfBirth < 1900 || yearOfBirth > 2500)) {
            cout << "This date is Invalid, please re-enter" << endl;
        }
    } while (dayOfBirth > emp.getPerson().getDateOfBirth().maxDay(monthOfBirth, yearOfBirth) || (monthOfBirth < 0 || monthOfBirth > 12) || (yearOfBirth < 1900 || yearOfBirth > 2500));
    do {
        inputBasicSalary:
        bool flagForBasicSalary = false;
        cout << "Input Basic Salary: ";
        getline(cin, basicSalaryTemp);

        for (int i = 0; (unsigned)i < basicSalaryTemp.length(); i++) {
            if (basicSalaryTemp[i] < 48 || basicSalaryTemp[i] > 57) {
                cout << "Character '" << basicSalaryTemp[i] << "' is invalid! ";
                flagForBasicSalary = true;
                break;
            }
        }
        if (flagForBasicSalary == true) {
            cout << "Please re-enter" << endl;
            goto inputBasicSalary;
        }
        basic_salary = stoi(basicSalaryTemp);
        if (basic_salary <= 0) {
            cout << "Invalid, please re-enter" << endl;
        }
    } while (basic_salary <= 0);
    do {
        inputBonus:
        bool flagForBonus = false;
        cout << "Input Bouns: ";
        getline(cin, bonusTemp);

        for (int i = 0; (unsigned)i < bonusTemp.length(); i++) {
            if (bonusTemp[i] < 48 || bonusTemp[i] > 57) {
                cout << "Character '" << bonusTemp[i] << "' is invalid! ";
                flagForBonus = true;
                break;
            }
        }
        if (flagForBonus == true) {
            cout << "Please re-enter" << endl;
            goto inputBonus;
        }
        bonus = stoi(bonusTemp);
        if (bonus <= 0) {
            cout << "Invalid, please re-enter" << endl;
        }
    } while (bonus <= 0);
    Employee emp(idOfEmployee, name, address, phone_number, dayOfBirth, monthOfBirth, yearOfBirth, basic_salary, bonus);
    listEmployee.push_back(emp);
    Mysort();
    this->idTemp = to_string(generateId);
    updateFile();
}

void DataEmployee::Delete(string id)
{
    int pos = findById(id);
    if (pos == -1){
        cout<<"Can't find this employee"<<endl;
        return;
    }
    listEmployee.erase(listEmployee.begin() + pos);
    this->generateId += 1;

}


int DataEmployee::editAnEmployee()
{
    string oldID;
    string IdOfEmployee;
    string nameOfEmployeeWantToEdit;
    string addressWantToEdit;
    string phoneNumberOfEmployeeWantToEdit;
    string day, month, year;
    int dayWantToEdit, monthWantToEdit, yearWantToEdit;
    long basicSalary;
    int bonus;
    cout << "Enter id of employee: ";
    cin.ignore();
    getline(cin, IdOfEmployee);

    int pos = findById(IdOfEmployee);
    if (pos > -1) {
        
        oldID = listEmployee.at(pos).getIdOfEmployee();
        bonus = listEmployee.at(pos).getBonus();
        this->idTemp = oldID;
        Delete(IdOfEmployee);
        inputName:
        bool flagForName = false;
        cout << "Enter name you want to edit to: ";
        getline(cin, nameOfEmployeeWantToEdit);
        for (int i = 0; (unsigned)i < nameOfEmployeeWantToEdit.length(); i++) {
            if ((nameOfEmployeeWantToEdit[i] != 32 && nameOfEmployeeWantToEdit[i] >= 0 && nameOfEmployeeWantToEdit[i] <= 64) || (nameOfEmployeeWantToEdit[i] >= 91 && nameOfEmployeeWantToEdit[i] <= 96) || (nameOfEmployeeWantToEdit[i] >= 123 && nameOfEmployeeWantToEdit[i] <= 255)) {
                cout << "Character \"" << nameOfEmployeeWantToEdit[i] << "\" is invalid! ";
                flagForName = true;
                break;
            }
        }
        if (flagForName == true) {
            cout << "Please re-enter" << endl;
            goto inputName;
        }
        handleString(nameOfEmployeeWantToEdit);
        inputAddress:
        bool flagForAddress = false;
        cout << "Enter address you want to edit to: ";
        getline(cin, addressWantToEdit);
        for (int i = 0; (unsigned)i < addressWantToEdit.length(); i++) {
            if ((addressWantToEdit[i] != 32 && addressWantToEdit[i] >= 0 && addressWantToEdit[i] <= 43) || (addressWantToEdit[i] >= 58 && addressWantToEdit[i] <= 64) || (addressWantToEdit[i] >= 91 && addressWantToEdit[i] <= 96) || (addressWantToEdit[i] >= 123 && addressWantToEdit[i] <= 255)) {
                cout << "Character \"" << addressWantToEdit[i] << "\" is invalid! ";
                flagForAddress = true;
                break;
            }
        }
        if (flagForAddress == true) {
            cout << "Please re-enter" << endl;
            goto inputAddress;
        }
        handleString(addressWantToEdit);
        inputPhoneNumber:
        bool flagForPhoneNumber = false;
        cout << "Enter phone number you want to edit to: ";
        getline(cin, phoneNumberOfEmployeeWantToEdit);
        for (int i = 0; (unsigned)i < phoneNumberOfEmployeeWantToEdit.length(); i++) {
            if (phoneNumberOfEmployeeWantToEdit[i] < 48 || phoneNumberOfEmployeeWantToEdit[i] > 57) {
                cout << "Number \"" << phoneNumberOfEmployeeWantToEdit[i] << "\" is invalid! ";
                flagForPhoneNumber = true;
                break;
            }
        }
        if (flagForPhoneNumber == true) {
            cout << "Please re-enter" << endl;
            goto inputPhoneNumber;
        }
        do {
            inputDayOfBirth:
            bool flagForDateOfBirth = false;
            cout << "Input Day Of Birth: ";

            getline(cin, day);

            for (int i = 0; (unsigned)i < day.length(); i++) {
                if (day[i] < 48 || day[i] > 57) {
                    cout << "Character '" << day[i] << "' is invalid! ";
                    flagForDateOfBirth = true;
                    break;
                }
            }
            if (flagForDateOfBirth == true) {
                cout << "Please re-enter" << endl;
                goto inputDayOfBirth;
            }
            dayWantToEdit = stoi(day);
            inputMonthOfBirth:
            bool flagForMonthOfBirth = false;
            cout << "Input Month Of Birth: ";
            getline(cin, month);
            for (int i = 0; (unsigned)i < month.length(); i++) {
                if (month[i] < 48 || month[i] > 57) {
                    cout << "Character '" << month[i] << "' is invalid! ";
                    flagForMonthOfBirth = true;
                    break;
                }
            }
            if (flagForMonthOfBirth == true) {
                cout << "Please re-enter" << endl;
                goto inputMonthOfBirth;
            }
            monthWantToEdit = stoi(month);
            inputYearOfBirth:
            bool flagForYearOfBirth = false;
            cout << "Input Year Of Birth: ";
            getline(cin, year);
            for (int i = 0; (unsigned)i < year.length(); i++) {
                if (year[i] < 48 || year[i] > 57) {
                    cout << "Character '" << year[i] << "' is invalid! ";
                    flagForYearOfBirth = true;
                    break;
                }
            }
            if (flagForYearOfBirth == true) {
                cout << "Please re-enter" << endl;
                goto inputYearOfBirth;
            }
            yearWantToEdit = stoi(year);
            if (dayWantToEdit > emp.getPerson().getDateOfBirth().maxDay(monthWantToEdit, yearWantToEdit) || (monthWantToEdit < 0 || monthWantToEdit > 12) || (yearWantToEdit < 1900 || yearWantToEdit > 2500)) {
                cout << "Invalid, please re-enter" << endl;
            }
        } while (dayWantToEdit > emp.getPerson().getDateOfBirth().maxDay(monthWantToEdit, yearWantToEdit) || (monthWantToEdit < 0 || monthWantToEdit > 12) || (yearWantToEdit < 1900 || yearWantToEdit > 2500));
        
        do {
            cout << "Enter basic salary you want to edit to: ";
            cin >> basicSalary;
            if (basicSalary < 0) {
                cout << "Invalid, please re-enter" << endl;
            }
        } while (basicSalary < 0);
        Employee emp(oldID, nameOfEmployeeWantToEdit, addressWantToEdit,phoneNumberOfEmployeeWantToEdit, dayWantToEdit, monthWantToEdit, yearWantToEdit, basicSalary, bonus);
        listEmployee.insert(listEmployee.begin() + pos, emp);
        cout << "Success!" << endl;
        updateFile();
    }
    else {
        cout << "Can't find this employee!" << endl;
    }
    return pos;
}


int DataEmployee::deleteEmployee()
{
    int index = -1;
    string id;
    cin.ignore();
    cout << "Input Id of employee you want to delete: ";
    getline(cin, id);
    for (int i = 0; (unsigned)i < listEmployee.size(); i++) {
        if (listEmployee.at(i).getIdOfEmployee().compare(id) == 0) {
            index = i;
            this->idTemp = listEmployee.at(i).getIdOfEmployee();  //giu lai id cua nguoi da bi xoa de khi them vao nhan vien moi nhan vien do se nam o vi tri bi xoa truoc do
            listEmployee.erase(listEmployee.begin() + index);
            cout << "DONE!\n";
        }
        updateFile();
    }
    if (index == -1) {
        cout << "NULL!\n";
    }
    return index;
    
}

void DataEmployee::display()
{
    cout << setw(100) << "List of employees are working at Quyet Vjp Pro's Cafe" << endl;
    cout << "+---------------+-----------------------+---------------------------------------------------------------+---------------+-----------------------+---------------+---------------+" << endl;
    cout << "| Id\t\t| Name\t\t\t| Address\t\t\t\t\t\t\t| Phone Number\t| Date Of Birth\t\t| Basic Salary\t| Bonus\t\t|" << endl;

    cout << "+---------------+-----------------------+---------------------------------------------------------------+---------------+-----------------------+---------------+---------------+" << endl;
    for (int i = 0; unsigned(i) < listEmployee.size(); i++) {
        listEmployee.at(i).display();

    }
    cout << "+---------------+-----------------------+---------------------------------------------------------------+---------------+-----------------------+---------------+---------------+" << endl;
}

int DataEmployee::findById(string id)
{
    int posOfId = -1;
    for (int i = 0; (unsigned)i < listEmployee.size(); i++) {
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
    for (int i = 0; (unsigned)i < listEmployee.size(); i++) {
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
    cout << "+---------------+-----------------------+---------------------------------------------------------------+---------------+-----------------------+---------------+---------------+" << endl;
    cout << "| Id\t\t| Name\t\t\t| Address\t\t\t\t\t\t\t| Phone Number\t| Date Of Birth\t\t| Basic Salary\t| Bonus\t\t|" << endl;
    cout << "+---------------+-----------------------+---------------------------------------------------------------+---------------+-----------------------+---------------+---------------+" << endl;
    for (int i = 0; (unsigned)i < listEmployee.size(); i++) {
        if (listEmployee.at(i).getPerson().getName().find(name) != string::npos) {
            listEmployee.at(i).display();
            flag = true;
        }
    }
    if (flag == false) {
        cout << "| NULL\t\t| NULL\t\t\t| NULL\t\t\t\t\t\t\t\t| NULL\t\t| NULL\t\t\t| NULL\t\t| NULL\t\t|" << endl;
    }
    cout << "+---------------+-----------------------+---------------------------------------------------------------+---------------+-----------------------+---------------+---------------+" << endl;
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
    for (int i = 0; (unsigned)i < str.length(); i++)
    {

        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
    }
    for (int i = 0; (unsigned)i < str.length(); i++) {
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
    for (int i = 0; (unsigned)i < str.length() - 1; i++)
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

int DataEmployee::getPartition(vector<Employee>& givenArray, int low, int high)
{
    int pivot = stoi(givenArray[high].getIdOfEmployee());
    int i = (low - 1);
    for (int j = low; j <= high; j++) {
        int tmp = stoi(givenArray[j].getIdOfEmployee());
        if (tmp < pivot) {
            i++;
            swap(givenArray[i], givenArray[j]);
        }
    }
    swap(givenArray[i + 1], givenArray[high]);
    return (i + 1);
}

void DataEmployee::quickSort(vector<Employee>& givenArray, int low, int high)
{
    if (low < high) {
        int pi = getPartition(givenArray, low, high);
        quickSort(givenArray, low, pi - 1);
        quickSort(givenArray, pi + 1, high);
    }
}

void DataEmployee::Mysort()
{
    quickSort(this->listEmployee, 0, listEmployee.size() - 1);
}

DataEmployee::~DataEmployee()
{
    listEmployee.clear();
}
