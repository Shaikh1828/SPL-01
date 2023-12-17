#include "Student.h"
#include <iostream>
using namespace std ;

Student::Student(string name, int age) : name(name), age(age) {}

void Student::study() const {
    cout << name << " is studying.\n";
}

void Student::introduce() const {
    cout << "I am a student named " << name << " and I am " << age << " years old.\n";
}