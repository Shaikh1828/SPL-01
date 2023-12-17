#include<bits/stdc++.h>
using namespace std ;

class user
{
    private:
        
    public:
        string name ;
        string phoneNo ;
        string ID ;
        string password ;
    
        user( string Name, string Phone, string Id, string Password )
        {
            name = Name ;
            phoneNo = Phone ;
            ID = Id ;
            password = Password ;
        }

        void print ()
        {
            cout << name << " " << phoneNo << " " << ID << " " << password << endl ;
        }

        void login( string Id, string Password )
        {
            if( ID == Id && Password == password )
            {

            }
        }
        
};

int main()
{
    vector< user >  Users  ;
    user u1( "Shaikh", "01212", "3773", "asdf1234" );
    user u2( "Samad", "01212", "3773", "asdf1234" );
    user u3( "Shahidul", "01212", "3773", "asdf1234" );
    Users.push_back( u1 );
    Users.push_back( u2 );
    Users.push_back( u3 );

     
    for ( int i = 0; i < Users.size(); i++ )
    {
        Users[i].print() ;
    }
    
}
