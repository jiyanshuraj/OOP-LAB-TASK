#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string eID;
    string name;
    string dep;
    float salary;
};

Employee* AllocateMemory(int size) {
    return new Employee[size];
}

void inputUser(Employee* emp, int size) {
    cin.ignore();  // Clear newline from buffer before taking getline inputs
    for (int i = 0; i < size; i++) {
        cout << "Employee's ID: ";
        cin >> emp[i].eID;
        cin.ignore();
        cout << "Employee's Name: ";
        getline(cin, emp[i].name);
        cout << "Employee's Department: ";
        getline(cin, emp[i].dep);
        cout << "Employee's Salary: ";
        cin >> emp[i].salary;
        cin.ignore();
    }
}

void Display(const Employee* emp, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Employee's ID: " << emp[i].eID << endl;
        cout << "Employee's Name: " << emp[i].name << endl;
        cout << "Employee's Department: " << emp[i].dep << endl;
        cout << "Employee's Salary: " << emp[i].salary << endl;
        cout << "--------------------------------------------------" << endl;
    }
}

void search(const Employee* emp, int size, const string& searchID) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (emp[i].eID == searchID) {
            cout << "Employee Found!" << endl;
            cout << "Employee's ID: " << emp[i].eID << endl;
            cout << "Employee's Name: " << emp[i].name << endl;
            cout << "Employee's Department: " << emp[i].dep << endl;
            cout << "Employee's Salary: " << emp[i].salary << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found!" << endl;
    }
}

void DeAllocate(Employee* emp) {
    delete[] emp;
    emp = nullptr;  // Avoid dangling pointer
}

int main() {
    int size;
    cout << "Enter No. of employees: ";
    cin >> size;

    Employee* emp = AllocateMemory(size);
    inputUser(emp, size);
    Display(emp, size);

    string SearchID;
    cout << "Enter Employee's ID to search: ";
    cin >> SearchID;
    search(emp, size, SearchID);

    DeAllocate(emp);
    return 0;
}
