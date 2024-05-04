#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include "Person.h" // Assuming Person class is defined in Person.h
using namespace std;

class Customer : public Person {
private:
    string customer_vehicle_status, customer_payment_status;
public:
    // Constructors
    Customer();
    Customer(int person_id, string person_name, string customer_vehicle_status, string customer_payment_status);
    Customer(const Customer& obj);

    // Setters
    void set_customer_vehicle_status(string customer_vehicle_status);
    void set_customer_payment_status(string customer_payment_status);

    // Getters
    string get_customer_vehicle_status();
    string get_customer_payment_status();

    // Utility functions
    string to_string();
    void store_to_file();
    void view_from_file();
    void membership(string new_membership);

    // Stream operator
    friend ostream& operator<<(ostream& cout, const Customer& obj);
};

#endif // CUSTOMER_H
