#include <fstream>
#include <string>
#include <iostream>
#include "Car.h"
#include "SUV.h"
using namespace std;
SUV::SUV():Car() {
    offroad_capability = 0;
    towing_capacity = 0;
}
SUV::SUV(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, int offroad_capability, int towing_capacity) :Car(car_id,car_make,car_model,car_price,car_seating_capacity,car_ground_clearance)
{
    this->offroad_capability= offroad_capability;
    this->towing_capacity= towing_capacity;
}
SUV::SUV(const SUV& obj):Car(obj){
    offroad_capability = obj.offroad_capability;
    towing_capacity = obj.towing_capacity;
}
SUV::~SUV(){}
void SUV::set_offroad_capability(int offroad_capability){
    this->offroad_capability = offroad_capability;
}
void SUV::set_towing_capacity(int towing_capacity) {
    this->towing_capacity = towing_capacity;
}

int SUV::get_offroad_capability() {
    return offroad_capability;
}
int SUV::get_towing_capacity() {
    return towing_capacity;
}

string SUV::tostring() {
    return Car::tostring() + "\t" + to_string(offroad_capability) + "\t" + to_string(towing_capacity);
}

void SUV::store_to_file() {
    ofstream fout("SUV.txt", ios::app);
    if (fout.is_open()) {
        fout << tostring() << endl;
        fout.close();
        cout << "\nData Stored To SUV File";
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void SUV::view_from_file() {
    ifstream fin("SUVs.data");
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

ostream& operator<<(ostream& cout, const SUV& obj) {
    cout << obj.tostring(); // Assuming you have implemented the to_string() member function
    return cout;
}

istream& operator>>(istream& cin, SUV& obj) {
    Car& base_obj = obj;
    cin >> base_obj;
    cout << "Enter Offroad Capability : ";
    cin >> obj.get_offroad_capability;
    cout << "Enter Towing Capacity : ";
    return cin;
}
