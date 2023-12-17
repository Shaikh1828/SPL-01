#include <iostream>
using namespace std ;

int ID = 1010 ;

class Worker
{
    public:
        
//     //Worker(string name, int age);
//     void study() const;
//     void introduce() const;

private:
    string name;
    int age;
    int num ;

public:
    Worker (string name, int age) : name(name), age(age) 
    {
        num = ++ID ;
    }

    void working() const ;

    void work() const 
    {
        cout << name << " is working.\n";
    }

    void introduce() const 
    {
        cout << "I am a worker named " << name << " and I am " << age << " years old. ID : "<< num <<"\n";
    }
};

void Worker::working() const 
{
    cout << "I have been working for " << age-15 << " years.\n";
}
