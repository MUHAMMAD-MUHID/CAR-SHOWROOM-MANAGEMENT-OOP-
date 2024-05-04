#include "Employee.h"
#include"Person.h"
#include<iostream>
using namespace std;

// Constructors
Employee::Employee() : employee_position(""), employee_salary(0.0) {}
Employee::Employee(int person_id, string person_name, string employee_position, float employee_salary)
    : employee_position(employee_position), employee_salary(employee_salary), Person(person_id, person_name) {}
Employee::Employee(const Employee& obj) : employee_position(obj.employee_position), employee_salary(obj.employee_salary) {}

// Setters
void Employee::set_employee_position(string employee_position) {
    this->employee_position = employee_position;
}
void Employee::set_employee_salary(float employee_salary) {
    this->employee_salary = employee_salary;
}

// Getters
string Employee::get_employee_position() {
    return employee_position;
}
float Employee::get_employee_salary() {
    return employee_salary;
}

// Member functions
string Employee::to_string() {
    return "Employee Position: " + employee_position + ", Salary: " + to_string(employee_salary);
}
void Employee::store_to_file() {
    ofstream file("employee_data.txt", ios::app);
    file << to_string() << endl;
    file.close();
}
void Employee::view_from_file() {
    ifstream file("employee_data.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cerr << "Unable to open file!" << endl;
    }
}
void Employee::promote(string new_position) {
    employee_position = new_position;
}

// Stream operators
ostream& operator<<(ostream& cout, const Employee& obj) {
    cout << "Employee Position: " << obj.employee_position << ", Salary: " << obj.employee_salary;
    return cout;
}
istream& operator>>(istream& cin, Employee& obj) {
    cout << "Enter Employee Position: ";
    getline(cin, obj.employee_position);

    cout << "Enter Employee Salary: ";
    cin >> obj.employee_salary;

    return cin;
}
