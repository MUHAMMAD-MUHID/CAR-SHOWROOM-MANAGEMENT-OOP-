#include "Employee.h"
#include"Person.h"
#include<iostream>
using namespace std;

// Constructors
Employee::Employee() : Person()
{
    employee_position = "n\a";
    employee_salary = 0.0;
}
Employee::Employee(int person_id, string person_name, string employee_position, float employee_salary) : Person(person_id, person_name)
{
    this->employee_position = employee_position;
    this->employee_salary = employee_salary;
}
Employee::Employee(const Employee& obj) : Person(obj)
{
    this->employee_position = obj.employee_position;
    this->employee_salary = obj.employee_salary;
} 

void Employee::set_employee_position(string employee_position) {
    this->employee_position = employee_position;
}
void Employee::set_employee_salary(float employee_salary) {
    this->employee_salary = employee_salary;
}

string Employee::get_employee_position() {
    return employee_position;
}
float Employee::get_employee_salary() {
    return employee_salary;
}

// Member functions
string Employee::tostring() {
    return Person::tostring() + employee_position + to_string(employee_salary);
}
void Employee::Employee_Menu()
{
    int option, person_id, confirm;
    string person_name, employee_position;
    float employee_salary;

    do
    {
        cout << "\nSelect Option : \n1.ADD\n2.VIEW\n3.SEARCH\n4.UPDATE\n5.DELETE";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            ofstream file("Employee.txt", ios::app);
            if (file.is_open())
            {
                // Prompt user for input
                cout << "Enter Employee ID: ";
                cin >> person_id;
                cin.ignore(); // Ignore newline character in input buffer
                cout << "Enter Employee name: ";
                getline(cin, person_name);
                cout << "Enter Emplyee position: ";
                getline(cin, employee_position);
                cout << "Enter Employee salary: ";
                cin >> employee_salary;

                // Write data to file
                file << person_id << "\t" << person_name << "\t" << employee_position << "\t" << employee_salary << endl;

                file.close();
                cout << "Employee data stored successfully!" << endl;

            }
            else
            {
                cerr << "Unable to open file!" << endl;
            }
            break;
        }
        case 2:
        {
            ifstream fin("Employee.txt");
            if (fin.is_open()) {
                string line;
                while (getline(fin, line)) {
                    cout << line << endl;
                }
                fin.close();
            }
            else {
                cerr << "Unable to open file!" << endl;
            }
            break;
        }
        case 3:
        {
            int temp;
            bool flag = false;
            ifstream fin("Employee.txt");
            cout << "\nEnter ID of Employee : "; cin >> temp;
            while (fin >> person_id >> person_name >> employee_position >> employee_salary)
            {
                if (temp == person_id)
                {
                    flag = true;
                    cout << "\nEmployee ID : " << person_id << "\nEmployee NAME : " << person_name << "\nEmployee emplyee position : "
                        << employee_position << "\nEmployee employee salary : " << employee_salary;
                }

            }
            if (flag == false)
            {
                cout << "\nRecord not found.";
            }
            break;
        }
        case 4:
        {
            int temp;
            bool flag = false;
            ifstream fin_file("Employee.txt");
            ofstream fout_file("temp.txt", ios::app);
            cout << "\nEnter ID of Employee : "; cin >> temp;
            while (fin_file >> person_id >> person_name >> employee_position >> employee_salary)
            {
                if (temp == person_id)
                {
                    flag = true;
                    cout << "Enter Employee ID: ";
                    cin >> person_id;
                    cin.ignore(); // Ignore newline character in input buffer
                    cout << "Enter Employee name: ";
                    getline(cin, person_name);
                    cout << "Enter Emplyee position: ";
                    getline(cin, employee_position);
                    cout << "Enter Employee salary: ";
                    cin >> employee_salary;

                    set_person_id(person_id);
                    set_person_name(person_name);
                    set_employee_position(employee_position);
                    set_employee_salary(employee_salary);
                }
                fout_file << "\n" << person_id << "\t" << person_name << "\t" << employee_position << "\t" << employee_salary;
            }
            fin_file.close();
            fout_file.close();
            remove("Employee.txt");
            rename("temp.txt", "Employee.txt");
            if (flag == false)
            {
                cout << "\nRecord not found.";
            }
            break;
        }
        case 5:
        {
            int temp;
            cout << "Enter the ID of the Showroom to delete: ";
            cin >> temp;
            ifstream fin("Employee.txt");
            ofstream fout("temp.txt");
            if (fin.is_open() && fout.is_open()) {
                bool found = false;
                while (fin >> person_id >> person_name >> employee_position >> employee_salary) {
                    if (temp == person_id) {
                        found = true;
                    }
                    else {
                        fout << "\n" << person_id << "\t" << person_name << "\t" << employee_position << "\t" << employee_salary;
                    }
                }
                fin.close();
                fout.close();
                remove("Employee.txt");
                rename("temp.txt", "Employee.txt");
                if (!found) {
                    cout << "Showroom with ID " << temp << " not found." << endl;
                }
                else {
                    cout << "Showroom with ID " << temp << " deleted successfully." << endl;
                }
            }
            else {
                cerr << "Error: Unable to open file for reading or writing." << endl;
            }
            break;
        }
        }
        cout << "\nEnter 1 to use menu again.";
        cin >> confirm;
    } while (confirm == 1);

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
