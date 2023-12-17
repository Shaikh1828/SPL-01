#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std ;

class Teacher {
public:
    Teacher(string name, string subject);
    void teach() const;
    void introduce() const;

private:
    string name;
    string subject;
};

#endif