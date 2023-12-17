#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std ;

class Student {
public:
    Student(string name, int age);
    void study() const;
    void introduce() const;

private:
    string name;
    int age;
};

#endif