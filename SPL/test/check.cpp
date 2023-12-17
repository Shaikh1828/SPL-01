#include<iostream>
using namespace std ;

class Check
{
    public:
        void method()
        {
            int i;
            cout << "All ok : " << endl ;
            cin >> i ; 

            if ( i == 1 ) ch1() ;
            else ch2() ;
        }

        void ch1();
        void ch2();
};

void  Check::ch1()
{
    cout << "Check 1 ok.\n" ;
}

void Check::ch2()
{
    cout << "Check 2 ok.\n" ;
}

int main()
{
    Check ch;
    ch.method();
}