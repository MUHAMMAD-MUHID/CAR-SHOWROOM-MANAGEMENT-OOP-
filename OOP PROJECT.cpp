#include <iostream>
#include"Person.h"
using namespace std;

int main() {
    // Example usage
    Person person1(101, "John Doe");
    cout << person1 << endl;

    Person person2;
    cin >> person2;
    cout << person2 << endl;

    person2.store_to_file();
    person2.view_from_file();

    return 0;
}