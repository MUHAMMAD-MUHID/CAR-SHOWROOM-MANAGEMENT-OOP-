#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Car.h"
Car::Car() {
    car_id = 0;
    car_make = "n/a";
    car_model = "n/a";
    car_price = 0.0;
    car_seating_capacity = 0;
    car_ground_clearance = 0;
    }
Car::Car(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance){
    this->car_id=car_id;
    this->car_make = car_make ;
    this->car_model = car_model;
    this->car_price = car_price ;
    this->car_seating_capacity = car_seating_capacity;
    this->car_ground_clearance = car_ground_clearance ;
}
Car::Car(const Car& obj) {
    car_id = obj.car_id;
    car_make = obj.car_make;
    car_model = obj.car_model;
    car_price = obj.car_price;
    car_seating_capacity = obj.car_seating_capacity;
    car_ground_clearance = obj.car_ground_clearance;
}
Car::~Car(){}

void Car::set_car_id(int id) {
    car_id = id;
}
void Car::set_car_make(string make) {
    car_make = make;
}
void Car::set_car_model(string model){
    car_model = model;
}
void Car::set_car_seating_capacity(int seating_capacity){
    car_seating_capacity = seating_capacity;
}
void Car::set_car_ground_clearance(int ground_clearance) {
    car_ground_clearance =ground_clearance;
}
void Car::set_car_price(float price) {
    car_price = price;
}
void Car::set_car_availability(bool is_available) {
    is_car_available = is_available;
}

int Car::get_car_id() {
    return car_id;
}
string Car::get_car_make() {
    return car_make;
}
string Car::get_car_model() {
    return car_model;
}
int Car::get_car_seating_capacity() {
    return car_seating_capacity;
}
int Car::get_car_ground_clearance() {
    return car_ground_clearance;
}
float Car::get_car_price() {
    return car_price;
}
bool Car::get_car_availability() const {
    return is_car_available;
}

string Car::tostring() {
    return to_string(car_id) + "\t" + car_make + "\t" + car_model + "\t" + to_string(car_seating_capacity) + "\t" + to_string(car_ground_clearance) + "\t" + to_string(car_price) + "\t"+ to_string(is_car_available);
}
void Car::store_to_file() {
    ofstream fout;
    fout.open("Cars.txt",ios::app);
    if (!fout.fail())
    {
        fout << tostring();
        cout << "\nData Stored to Cars.txt";
    }
    else 
        cerr << "Error: Unable to open file for writing." << endl;
    fout.close();
}
void Car::view_from_file() {
    ifstream fin;
    fin.open("Cars.txt");
    if (!fin.fail()) {

        cout << "\n------------------------------------------------------------------";
        cout << "\nID--Make--Model--Seating Capacity--Ground Clearance--Price--";
        cout << "\n------------------------------------------------------------------";
        string row;
        while (getline(fin, row))
        {
            if (!row.empty())
            {
                cout << "\n";
                cout << row;
            }
        }
    }
    else
        cerr << "Error: Unable to open file for Viewing." << endl;
    fin.close();
}

ostream& operator<<(ostream& cout, const Car& obj) {
    cout << "\nCar ID : "<<obj.car_id;
    cout << "\nCar make : "<<obj.car_make;
    cout << "\nCar model : " << obj.car_model;
    cout << "\nCar price : " << obj.car_price;
    cout << "\nCar seating capacity : " << obj.car_seating_capacity;
    cout << "\nCar ground clearance : " << obj.car_ground_clearance;
    cout << "\nCar availability : " << obj.is_car_available;
    return cout;
}
istream& operator>>(istream& cin, Car& obj) {
    cout << "Enter car ID: ";
    cin >> obj.car_id;
    cout << "Enter car make: ";
    cin >> obj.car_make;
    cout << "Enter car model: ";
    cin >> obj.car_model;
    cout << "Enter car price: ";
    cin >> obj.car_price;
    cout << "Enter car seating capacity: ";
    cin >> obj.car_seating_capacity;
    cout << "Enter car ground clearance: ";
    cin >> obj.car_ground_clearance;
    cout << "Is car available? (1 for Yes, 0 for No): ";
    cin >> obj.is_car_available;
    return cin;
}