#include<bits/stdc++.h>
using namespace std ;

#include "Room.cpp"

int Id = 101010 ;

class Clients
{
    private:
        int ID ;
        string password ; 
        int total ;
        int due ;
    public:
        string name ;
        string phoneNo ;
        int roomNo;
        vector < Clients > clientList ;
        
    
        Clients( string Name, string Phone, string Password )
        {
            name = Name ;
            phoneNo = Phone ;
            ID = Id++ ;
            password = Password ;
        }

        Clients( )
        {
            name = "" ;
            phoneNo = "" ;
            ID = 0 ;
            password = "" ;

            Clients u1( "Shaikh", "01212", "asdf1234" );
            Clients u2( "Samad", "01212",  "asdf1234" );
            Clients u3( "Shahidul", "01212", "asdf1234" );
            clientList.push_back( u1 );
            clientList.push_back( u2 );
            clientList.push_back( u3 );
        }

        void print()
        {
            cout << name << " " << phoneNo << " " << ID << " " << password << endl ;
        }

        void printList()
        {
            for( auto it : clientList )
            {
                it.print();
            }
        }

        void login( int Id, string Password )
        {
            if( ID == Id && Password == password )
            {
                // After login interface ..
            }
        }

        void bookRoom()
        {
            Room room ;
            int roomChoice ;
            room.showRoomList();
            cout << "Enter the prefered room no : " ;
            cin >> roomChoice ;
            room.booking( room );
        }


        
};

