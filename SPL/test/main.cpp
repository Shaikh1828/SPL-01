// #include "Student.h"
// #include "Teacher.h"
#include "worker.cpp"
#include "check.cpp"

int main() 
{
    // Student student("Alice", 18);
    // Teacher teacher("Mr. Smith", "Math");
    Worker w1("ALi",28), w2("Sobuj",26), w3("Goni",30);
    Check c1 ;

    c1.method() ;
    w1.introduce();
    w2.introduce();
    w3.introduce() ;
    // w1.work();
    // w1.working() ;


    // student.introduce();
    // student.study();

    // teacher.introduce();
    // teacher.teach();

    return 0;
}