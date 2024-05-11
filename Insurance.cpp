#include "Insurance.h"

// Default constructor
Insurance::Insurance()
{
    Insurance_id = 0;
    Insurance_type = "";
}

// Parameterized constructor
Insurance::Insurance(int Insurance_id, string Insurance_type)
{
    this->Insurance_id = Insurance_id;
    this->Insurance_type = Insurance_type;
}

// Copy constructor
Insurance::Insurance(Insurance& obj)
{
    Insurance_id = obj.Insurance_id;
    Insurance_type = obj.Insurance_type;
}

// Setter for Insurance_id
void Insurance::set_Insurance_id(int Insurance_id)
{
    this->Insurance_id = Insurance_id;
}
void Insurance::set_Insurance_type(string Insurance_type)
{
    this->Insurance_type = Insurance_type;
}

// Getter for Insurance_id
int Insurance::get_Insurance_id()
{
    return Insurance_id;
}
string Insurance::get_Insurance_type()
{
    return Insurance_type;
}
