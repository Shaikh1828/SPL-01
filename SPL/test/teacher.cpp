#include "Teacher.h"
#include <iostream>
using namespace std ;

Teacher::Teacher(string name, string subject) : name(name), subject(subject) 
{}

void Teacher::teach() const {
    cout << name << " is teaching " << subject << ".\n";
}

void Teacher::introduce() const {
    cout << "I am a teacher named " << name << " teaching " << subject << ".\n";
}