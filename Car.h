#include <iostream>
using namespace std;
class Car {
private:
    int car_id, car_seating_capacity, car_ground_clearance;
    string car_make, car_model;
    float car_price;
    bool is_car_available = false;
public:
    Car();
    Car(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance);
    Car(const Car& obj);
    ~Car();

    void set_car_id(int id);
    void set_car_make(string make);
    void set_car_model(string model);
    void set_car_seating_capacity(int seating_capacity);
    void set_car_ground_clearance(int ground_clearance);
    void set_car_price(float price);
    void set_car_availability(bool is_available);

    int get_car_id();
    string get_car_make();
    string get_car_model();
    int get_car_seating_capacity();
    int get_car_ground_clearance();
    float get_car_price();
    bool get_car_availability() const;

    string tostring();
    void store_to_file();
    void view_from_file();

    friend ostream& operator<<(ostream& cout, const Car& obj);
    friend istream& operator>>(istream& cin, Car& obj);
};