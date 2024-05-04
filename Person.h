#pragma once 
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
private:
    int person_id;
    string person_name;

public:
    Person();
    Person(int person_id,string person_name);
    Person(const Person& obj);

    //setter methods
    void set_person_id(int person_id);
    void set_person_name(const string person_name);

    // Getter methods
    int get_person_id() const;
    string get_person_name() const;

    //Member functions
    string tostring() const;
    void store_to_file();
    void view_from_file();

    //Assignment operators
    friend ostream& operator<<(ostream& cout, const Person& obj);
    friend istream& operator>>(istream& cin, Person& obj);

};

#endif 
