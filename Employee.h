#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include "Person.h" // Assuming Person class is defined in Person.h

class Employee : protected Person
{
private:
    string employee_position;
    float employee_salary;

public:
    // Constructors
    Employee();
    Employee(int person_id, string person_name, string employee_position, float employee_salary);
    Employee(const Employee& obj);

    // Setters
    void set_employee_position(string employee_position);
    void set_employee_salary(float employee_salary);

    // Getters
    string get_employee_position();
    float get_employee_salary();

    // Utility functions
    string tostring();
    void Employee_Menu();
    //void store_to_file();
    //void view_from_file();
    void promote(string new_position);

    // Stream operators
    friend ostream& operator<<(ostream& cout, const Employee& obj);
    friend istream& operator>>(istream& cin, Employee& obj);
};

#endif // EMPLOYEE_H
