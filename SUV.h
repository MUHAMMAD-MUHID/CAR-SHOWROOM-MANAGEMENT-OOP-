#pragma once
#include "Car.h"
using namespace std;
class SUV : public Car {
private:
    int offroad_capability, towing_capacity;
public:
    SUV();
    SUV(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, int offroad_capability, int towing_capacity);
    SUV(const SUV& obj);
    ~SUV();
    void set_offroad_capability(int offroad_capability);
    void set_towing_capacity(int towing_capacity);

    int get_offroad_capability();
    int get_towing_capacity();
    string tostring();

    void store_to_file();
    void view_from_file();

    friend ostream& operator<<(ostream& cout, const SUV& obj);
    friend istream& operator>>(istream& cin,const SUV& obj);
};

