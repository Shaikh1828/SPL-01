#include<bits/stdc++.h>
using namespace std ;

#include "Room.cpp"
#include "FoodPackage.cpp"

class Clients ;
vector < Clients > clientList ;

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
        
        Clients( )
            {
                name = "" ;
                phoneNo = "" ;
                ID = 0 ;
                password = "" ;
                fooding.package = "" ;

            }

        Clients( string Name, string Phone, string Password )
        {
            int Id = clientList[clientList.size()-1].getID() ;
            name = Name ;
            phoneNo = Phone ;
            ID = ++Id ;
            password = Password ;
            roomNo = total = due = 0 ;
            fooding.package = "null" ;
        }

        Clients( int initializer )
        {
            clientUpdate() ;
        }

        void clientUpdate()
        {
            clientList.clear();
            ifstream my_file;
            my_file.open( "clients.txt", ios::in );
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                string Pass, Phone, Name , Food ;
                int id , Room , Due, Total;

                while ( 1 ) 
                {
                    Clients addClient ;
                    if ( my_file.eof() ) break;
				        
                    my_file >> id >> Pass >> Name >> Phone >> Food >> Room >> Total >> Due ;
                    addClient.ID = id ;
                    addClient.password = Pass ;
                    addClient.name = Name ;
                    addClient.phoneNo = Phone ;
                    addClient.fooding.package = Food ;
                    addClient.roomNo = Room ;
                    addClient.total = Total ;
                    addClient.due = Due ;

                    clientList.emplace_back( addClient );
                }
            }

            my_file.close();
        }

        void updateBack()
        {
            ofstream my_file ;
            string str ;
            my_file.open( "clients.txt", ios::trunc );
            
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                for ( int i = 0; i < clientList.size(); i++ )
                { 
                    if( i > 0 ) my_file << endl ;
                    my_file << clientList[i].getID() << " " << clientList[i].getPassword() << " " << clientList[i].name <<  
                    " " << clientList[i].phoneNo << " " << clientList[i].fooding.package << " " << clientList[i].roomNo << 
                    " " << clientList[i].getTotal() << " " << clientList[i].getDue() ;
                }
                
            } 
            my_file.close() ;
            
        }

        void signUp(  )
        {
            string Name, Phone, Pass;
            cout << "Enter Your Name : ";
            cin >> Name ;
            cout << "Enter Your Phone No : " ;
            cin >> Phone ;
            cout << "Enter Password : " ;
            cin >> Pass ;
            Clients newClient( Name, Phone, Pass ) ;
            cout << "\n      !!! New account created !!! \n\n ";
            cout << "ID - " << newClient.ID << "  Password - " << newClient.password << endl << endl ;
            cout << "**  Keep these informations safe and secured  ** \n\n" ;
            clientList.push_back( newClient ) ;
        }

        
        int getID()
        {
            return this->ID ;
        }

        string getPassword()
        {
            return this->password ;
        }

        int getTotal()
        {
            return this->total ;
        }

        int getDue()
        {
            return this->due ;
        }

        void getAccount()
        {
            cout << "Total : " << total << "  Due : " << due << endl ;
        }

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
                getchar() ;
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
                    cout << "\nEnter the prefered room no : " ;
                    cin >> roomChoice ;
                    room.roomNo = roomChoice ;
                    roomNo = roomChoice ;
                    
                } while ( !room.booking( room, ID ) );
                total += rooms[ room.roomMatch(room) ].price ;
                due += rooms[ room.roomMatch(room) ].price ;
            }
            else
            {
                cout << "\n   Sorry, No room available.\n\n" ;
            }
            cout << "Press any key to continue :\n" ;
            _getwche() ;
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
            cout << "\n\nEnter prefered food-package no : ";
            cin >> foodChoice ;
            foodChoice -- ;
            fooding = foods[foodChoice] ;
            total += fooding.cost ;
            due += fooding.cost ;
            cout << "\nPress any key to continue :\n" ;
            _getwche() ;
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
                    cout << "\n\n    Matched!!! \n" << endl ;
                    return i;
                }    
            }
            return -1 ;
        }

        void printStatus()
        {
            cout << endl ;
            cout << name << "  ID- " << ID << "    Phone : " << phoneNo << endl ;
            cout << "Room : " << roomNo << "   Fooding - " << fooding.package << endl ;
            cout << "Total : " << total << "    Due : " << due << endl << endl ;
            cout << "Press any key to continue :\n" ;
            _getwche() ;
        }

        void checkOut( )
        {
            int payment = 0 ;
            char ch = 'N' ;
            getAccount() ;
            cout << "Wanna pay now ? Y/N " ;
            cin >> ch ;
            if( ch == 'Y' )
            {
                cout << "Amount want to pay : " ;
                cin >> payment ;
                due -= payment ;
            }
            if( due > 0 )
            {
                cout << "\nCheckOut not successful...\n";
                cout << "Due : " << due ;
                cout << "\nPress any key to continue :\n" ;
                    _getwche() ;
            }
            else
            {
                if( due != 0 ) 
                {
                    cout << "The change in return is " << fabs(due) << endl ;
                    due = 0 ;
                }
                cout << "Checkout Successful .. \n" << endl ;
                fooding.package = "null" ;
                Room room;
                room.roomNo = roomNo;
                room.checkOut( room ) ;
                roomNo = 0 ;
                total = 0 ;

                cout << "If you please leave a review ? Y/N " ;
                cin >> ch ;
                if( ch == 'Y' )
                {
                    message() ;
                }
            } 

        }

        void message()
        {
            string Message ;
            cout << "Enter your message : " ;
            getchar() ;
            getline( cin ,Message ) ;

            fstream my_file ;
            my_file.open( "messages.txt", ios::app );
            
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                my_file << endl << Message ;
            }
            my_file.close() ;
        }

        void changePassword()
        {
            string newPass="a", renewPass="";
            
            while ( newPass != renewPass )
            {
                cout << "Enter New password : " ;
                cin >> newPass ;
                cout << "Enter New password again : " ;
                cin >> renewPass ;
                if( newPass != renewPass ) cout << "Password didn't match..Try again..\n" ;
            } 
            
            password = newPass ;
            cout << "\n\n    !!! Password changed successfully !!!\n\n" ;
            cout << "Press any key to continue :\n" ;
            _getwche() ;

        }
        
};