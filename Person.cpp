#include <iostream>
#include"Person.h"
#include "string"
#include <fstream>

using namespace std;
    Person::Person()
    {
        person_id = 0;
        person_name = "N/A";
    }
    Person::Person(int person_id, string person_name)
    {
        this->person_id = person_id;
        this->person_name = person_name;
    }
    Person::Person(const Person& obj)
    {
        this->person_id = obj.person_id;
        this->person_name = obj.person_name;
    }
    
    //Setter methods
    void Person::set_person_id(int person_id) { this->person_id = person_id; }
    void Person::set_person_name(string person_name) { this->person_name = person_name; }

    // Getter methods
    int Person::get_person_id() const { return person_id; }
    string Person::get_person_name() const { return person_name; }

    // Convert to string 
    string Person::tostring() const {
        return "Person ID: " + to_string(person_id) + ", Person Name: " + person_name;
    }

    // Store data to file
    void Person::store_to_file() {
        ofstream file("person_data.txt", ios::app);
        if (file.is_open()) 
        {
            file << person_id << " " << person_name << endl;
            file.close();
        }
        else {
            cout << "Unable to open file for storing." << endl;
        }
    }

    // View data from file
    void Person::view_from_file() {
        ifstream file("person_data.txt");
        int id;
        string name;
        if (file.is_open()) {
            while (file >> id >> name) {
                cout << "Person ID: " << id << ", Person Name: " << name << endl;
            }
            file.close();
        }
        else {
            cout << "Unable to open file for viewing." << endl;
        }
    }

    // Overloading << operator for output
    ostream& operator<<(ostream& cout, const Person& obj) {
        cout << obj.tostring();
        return cout;
    }
    // Overloading >> operator for input
    istream& operator>>(istream& cin, Person& obj) {
        cout << "Enter Person ID: ";
        cin >> obj.person_id;
        cout << "Enter Person Name: ";
        cin.ignore();
        getline(cin, obj.person_name);
        return cin;
    }


