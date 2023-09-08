#include<bits/stdc++.h>
using namespace std ;

class Clients ;
vector < Clients > clientList ;

#include "Room.cpp"
#include "FoodPackage.cpp"

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
        FoodPackage fooding ;
        //vector < Clients > clientList ;
        
    
        Clients( string Name, string Phone, string Password )
        {
            name = Name ;
            phoneNo = Phone ;
            ID = Id++ ;
            password = Password ;
            roomNo = total = due = 0 ;
            fooding.package = "" ;
        }

        Clients( )
        {
            name = "" ;
            phoneNo = "" ;
            ID = 0 ;
            password = "" ;
            fooding.package = "" ;

            // Clients u1( "Shaikh", "01212", "asdf1234" );
            // Clients u2( "Samad", "01212",  "asdf1234" );
            // Clients u3( "Shahidul", "01212", "asdf1234" );
            // clientList.push_back( u1 );
            // clientList.push_back( u2 );
            // clientList.push_back( u3 );
        }

        int getID()
        {
            return this->ID ;
        }

        // string getPassword()
        // {
        //     return this->password ;
        // }

        void print()
        {
            cout << name << " " << phoneNo << " " << ID << " " << password << endl ;
        }

        void printList( )
        {
            for( auto it : clientList )
            {
                it.print();
            }
        }

        int login( Clients client )
        {
            int n = 3 , match;
            while ( n-- )
            {
                cout << "Please enter ID : " ;
                cin >> client.ID ;
                cout << "Please enter password : " ;
                cin >> client.password ;
                match = client.matchClient( client );
                if( match != -1 ) break;
                if( n != 0 ) cout << "Incorrect ID or Password. Try again.\n" ;
            }
          
            return match ;              
        }

        void bookRoom( )
        {
            Room room ;
            int roomChoice ;
            room.showRoomList();
            if( rooms.size() != 0 )
            {
                do
                {
                    cout << "Enter the prefered room no : " ;
                    cin >> roomChoice ;
                    room.roomNo = roomChoice ;
                    roomNo = roomChoice ;
                    
                } while ( !room.booking( room, ID ) );
                total += rooms[ room.roomMatch(room) ].price ;
                due += rooms[ room.roomMatch(room) ].price ;
            }
        }

        void changeRoom( )
        {
            Room room;
            room.roomNo = roomNo ;
            bookRoom() ;
            room.roomChanging( room );
        }

        void enrollFood()
        {
            FoodPackage food;
            int foodChoice ;
            food.showFoodList();
            cout << "Enter prefered food-package no : ";
            cin >> foodChoice ;
            foodChoice -- ;
            fooding = foods[foodChoice] ;
            total += fooding.cost ;
            due += fooding.cost ;
        }

        void foodChange()
        {
            if( fooding.package.size() < 5 )
            {
                cout << "No Food package was enrolled.\n\n" ;
                enrollFood() ;
            }
            else
            {
                cout << "Current Food package : " << fooding.package << endl << endl  ;
                enrollFood() ;
            }
            
        }

        int matchClient( Clients client )
        {
            for ( int i = 0; i < clientList.size(); i++ )
            {
                if ( client.ID == clientList[i].ID && client.password == clientList[i].password )
                {
                    cout << "Matched!!" << endl ;
                    return i;
                }    
            }
            return -1 ;
        }

        void printStatus()
        {
            cout << endl ;
            cout << name << "  ID- " << ID << "  Phone : " << phoneNo << endl ;
            cout << "Room : " << roomNo << " Fooding - " << fooding.package << endl ;
            cout << "Total : " << total << "  Due : " << due << endl << endl ;
            cout << "Press any key to continue :\n" ;
            _getwche() ;
        }
        
};

// int main()
// {
//     Clients c1( "Shaikh", "01212", "asdf1234" );
//     c1.enrollFood();
//     c1.printStatus();
// }