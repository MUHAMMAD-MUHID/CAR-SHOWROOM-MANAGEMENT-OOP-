#include<iostream>
#include"Person.h"
#include "Customer.h"
#include<string>
using namespace std;
// Constructors
Customer::Customer() : Person()
{
    customer_vehicle_status = "N/A";
    customer_payment_status = "N/A";
    membership = "n/a";

}
Customer::Customer(int person_id, string person_name, string customer_vehicle_status, string customer_payment_status, string membership)
    : Person(person_id, person_name) {
    this->customer_vehicle_status = customer_vehicle_status;
    this->customer_payment_status = customer_payment_status;;
    this->membership = membership;
}
Customer::Customer(const Customer& obj) : Person(obj)
{
    this->customer_vehicle_status = obj.customer_vehicle_status;
    this->customer_payment_status = obj.customer_payment_status;
    this->membership = obj.membership;
}
// Setters
void Customer::set_customer_vehicle_status(string customer_vehicle_status) {
    this->customer_vehicle_status = customer_vehicle_status;
}
void Customer::set_customer_payment_status(string customer_payment_status) {
    this->customer_payment_status = customer_payment_status;
}
void Customer::set_customer_membership(string membership) {
    this->membership = membership;
}
// Getters
string Customer::get_customer_vehicle_status() {
    return customer_vehicle_status;
}
string Customer::get_customer_payment_status() {
    return customer_payment_status;
}
string Customer::get_customer_membership() { return membership; 
}
// Utility functions
string Customer::tostring()  {
    return Person::tostring() + "\t" + customer_vehicle_status + "\t" + customer_payment_status;
}
void Customer::store_to_file() {
    ofstream fout("Customer.txt", ios::app);
    if (fout.is_open()) {
        fout << tostring() << endl;
        fout.close();
        cout << "\nData Stored To Customer  File";
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
void Customer::view_from_file() {
    ifstream fin("Customer.txt");
    if (fin.is_open()) {
        string data;
        while (getline(fin, data)) {
            cout << data << endl;
        }
        fin.close();
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void Customer::search() {
    int id;
    cout << "Enter the ID of the Customer to search: ";
    cin >> id;
    ifstream fin("Customer.txt");
    if (fin.is_open()) {
        bool found = false;     
        int customer_id;
        string customer_name;
        while (fin >> customer_id >>customer_name >>customer_vehicle_status>>customer_payment_status) {
            if (customer_id == id) {
                found = true;
                cout << "\nCustomer ID: " << customer_id;
                cout << "\nCustomer Name: " << customer_name;
                cout << "\nCustomer Vehicle Staus: " << customer_vehicle_status ;
                cout << "\nCustomer Payment Status: " << customer_payment_status;
            }
            fin.close();
            if (!found) {
                cout << "Customer with ID " << id << " not found." << endl;
            }
        }
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void Customer::update() {
    int id;
    cout << "Enter the ID of the Customer to update: ";
    cin >> id;
    ifstream fin("Customer.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false;
        int  customer_id;
        string customer_name;
        while (fin >> customer_id >> customer_name >> customer_vehicle_status >>customer_payment_status) {
            if (customer_id == id) {
                found = true;
                cout << "Enter Customer ID: ";
                cin >> customer_id;
                cin.ignore();
                cout << "Enter Customer Name: ";
                getline(cin, customer_name);
                cout << "Enter Customer Vehicle Status: ";
                getline(cin, customer_vehicle_status);
                cout << "Enter Customer Payment Status: ";
                getline(cin, customer_payment_status);
                Customer::set_person_id(customer_id);
                Customer::set_person_name(customer_name);
                Customer::set_customer_vehicle_status(customer_vehicle_status);
                Customer::set_customer_payment_status(customer_payment_status);
            }
            fout << Customer::tostring() << endl;
        }
        fin.close();
        fout.close();
        remove("Customer.txt");
        rename("temp.txt", "Customer.txt");
        if (!found) {
            cout << "Customer with ID " << id << " not found." << endl;
        }
        else {
            cout << "Customer updated successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Customer::del() {
    int id;
    cout << "Enter the ID of the Customer to delete: ";
    cin >> id;
    ifstream fin("Customer.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false;
        int customer_id;
        string customer_name;
        while (fin >> customer_id >> customer_name >> customer_vehicle_status >> customer_payment_status){
            if (customer_id == id) {
                found = true;
            }
            else {
                fout << customer_id << "\t" << customer_name << "\t" << customer_vehicle_status<< "\t" << customer_payment_status << endl;
            }
        }
        fin.close();
        fout.close();
        remove("Customer.txt");
        rename("temp.txt", "Customer.txt");
        if (!found) {
            cout << "Customer with ID " << id << " not found." << endl;
        }
        else {
            cout << "Customer with ID " << id << " deleted successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Customer::menu(Customer& obj) {
    int choice;
    cout << "\nMenu 1- add 2- view 3- update 4- search 5- delete";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cin >> obj;
        break;
    }
    case 2:
    {
        obj.view_from_file();
        break;
    }
    case 3:
    {
        obj.update();
        break;
    }
    case 4:
    {
        obj.search();
        break;
    }
    case 5:
    {
        obj.del();
        break;
    }
    default:
    {
        cout << "\nInvalid Choice";
        break;
    }
    }
}
void Customer::customer_membership(string new_membership)
{
  membership = new_membership;
}
ostream& operator<<(ostream& cout, const Customer& obj) {
    cout << "Customer ID: "<<obj.get_person_id();
    cout << "Customer Name: "<<obj.get_person_name();
    cout << "Customer Membership: " << obj.membership;
    cout << "Customer Vehicle Status: " << obj.customer_vehicle_status;
    cout << "Customer Payment Status "<<obj.customer_payment_status;
    return cout;
}
istream& operator>>(istream& cin, Customer& obj) {
    int id;string name;
    cout << "Customer ID: ";cin >> id;
    obj.set_person_id(id);
    cin.ignore();
    cout << "Customer Name: ";
    getline(cin, name);
    obj.set_person_name(name);
    cout << "Customer Membership: ";getline( cin,obj.membership);
    cout << "Customer Vehicle Status: ";
    getline(cin, obj.customer_vehicle_status);
    cout << "Customer Payment Status: ";
    getline(cin,obj.customer_payment_status);

    obj.set_person_id(id);
    obj.set_person_name(name);
    obj.set_customer_vehicle_status(obj.customer_vehicle_status);
    obj.set_customer_payment_status(obj.customer_payment_status);

    obj.store_to_file();


    return cin;
}
