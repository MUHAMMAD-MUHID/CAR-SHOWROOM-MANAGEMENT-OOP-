#include "Customer.h"
#include "string"
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
string Customer::tostring() {
    return Person::to_string() + ", Customer Vehicle Status: " + customer_vehicle_status + ", Payment Status: " + customer_payment_status;
}

void Customer::store_to_file() {
    ofstream file("customer_data.txt", ios::app);
    file << to_string() << endl;
    file.close();
}

void Customer::view_from_file() {
    ifstream file("customer_data.txt");
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

void Customer::membership(string new_membership) {
    // Logic for updating membership status
}

// Stream operator
ostream& operator<<(ostream& cout, const Customer& obj) {
    cout << obj.tostring();
    return cout;
}
