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

}
Customer::Customer(int person_id, string person_name, string customer_vehicle_status, string customer_payment_status)
    : Person(person_id, person_name) {
    this->customer_vehicle_status = customer_vehicle_status;
    this->customer_payment_status = customer_payment_status;
}
Customer::Customer(const Customer& obj) : Person(obj)
{
    this->customer_vehicle_status = obj.customer_vehicle_status; 
    this->customer_payment_status = obj.customer_payment_status;
}

// Setters
void Customer::set_customer_vehicle_status(string customer_vehicle_status) {
    this->customer_vehicle_status = customer_vehicle_status;
}
void Customer::set_customer_payment_status(string customer_payment_status) {
    this->customer_payment_status = customer_payment_status;
}

// Getters
string Customer::get_customer_vehicle_status() {
    return customer_vehicle_status;
}
string Customer::get_customer_payment_status() {
    return customer_payment_status;
}

// Utility functions
string Customer::tostring() const {
    return Person::tostring() +"\t" + customer_vehicle_status + "\t" + customer_payment_status;
}
void Customer::Customer_Menu()
{
    int option, person_id, confirm;
    string person_name, vehicle_status, payment_status;
    do
    {
        cout << "\nSelect Option : \n1.ADD\n2.VIEW\n3.SEARCH\n4.UPDATE\n5.DELETE";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            ofstream file("Customer.txt", ios::app);
            if (file.is_open())
            {
                // Prompt user for input
                cout << "Enter Customer ID: ";
                cin >> person_id;
                cin.ignore(); // Ignore newline character in input buffer
                cout << "Enter Customer name: ";
                getline(cin, person_name);
                cout << "Enter vehicle status: ";
                getline(cin, vehicle_status);
                cout << "Enter payment status: ";
                getline(cin, payment_status);

                // Write data to file
                file << person_id << "\t" << person_name << "\t" << vehicle_status << "\t" << payment_status << endl;

                file.close();
                cout << "Customer data stored successfully!" << endl;

            }
            else
            {
                cerr << "Unable to open file!" << endl;
            }
            break;
        }
        case 2:
        {
            ifstream fin("Customer.txt");
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
            ifstream fin("Customer.txt");
            cout << "\nEnter ID of customer : "; cin >> temp;
            while (fin >> person_id >> person_name >> vehicle_status >> payment_status)
            {
                if (temp == person_id)
                {
                    flag = true;
                    cout << "\nCUSTOMER ID : " << person_id << "\nCUSTOMER NAME : " << person_name << "\nCUSTOMER VEHICLE STATUS : "
                        << vehicle_status << "\nCUSTOMER PAYMENT STATUS : " << payment_status;
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
            ifstream fin_file("Customer.txt");
            ofstream fout_file("temp.txt", ios::app);
            cout << "\nEnter ID of customer : "; cin >> temp;
            while (fin_file >> person_id >> person_name >> vehicle_status >> payment_status)
            {
                if (temp == person_id)
                {
                    flag = true;
                    cout << "Enter Customer ID: ";
                    cin >> person_id;
                    cin.ignore(); // Ignore newline character in input buffer
                    cout << "Enter Customer name: ";
                    getline(cin, person_name);
                    cout << "Enter vehicle status: ";
                    getline(cin, vehicle_status);
                    cout << "Enter payment status: ";
                    getline(cin, payment_status);

                    set_person_id(person_id);
                    set_person_name(person_name);
                    set_customer_vehicle_status(vehicle_status);
                    set_customer_payment_status(payment_status);
                }
                fout_file << "\n" << person_id << "\t" << person_name << "\t" << vehicle_status << "\t" << payment_status;
            }
            fin_file.close();
            fout_file.close();
            remove("Customer.txt");
            rename("temp.txt", "Customer.txt");
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
            ifstream fin("Customer.txt");
            ofstream fout("temp.txt");
            if (fin.is_open() && fout.is_open()) {
                bool found = false;
                while (fin >> person_id >> person_name >> vehicle_status >> payment_status) {
                    if (temp == person_id) {
                        found = true;
                    }
                    else {
                        fout << "\n" << person_id << "\t" << person_name << "\t" << vehicle_status << "\t" << payment_status;
                    }
                }
                fin.close();
                fout.close();
                remove("Customer.txt");
                rename("temp.txt", "Customer.txt");
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
void Customer::membership(string new_membership) 
{
    // Logic for updating membership status
}
ostream& operator<<(ostream& cout, const Customer c) {
    cout << c.tostring();
    return cout;
}
