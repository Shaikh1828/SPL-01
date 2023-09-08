#include<bits/stdc++.h>
using namespace std ;

//#include "Clients.cpp"
class Room ;
vector < Room > rooms ;

class Room
{
    private:
        int residerID ;

    public :
        int roomNo ;
        string bed ;
        string condition ;
        bool availableStatus;
        int price ;
        //Clients resider;

        Room()
        {
            
        }

        Room( int initialize )
        {
            roomsUpdate() ;
        }

        void roomsUpdate()
        {
            rooms.clear();
            ifstream my_file;
            my_file.open( "rooms.txt", ios::in );
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                string Bed, Condition;
                int Roomnum, Price ;
                bool status;

                while ( 1 ) 
                {
                    Room roomCreate;
                    if (my_file.eof())
				        break;
                    my_file >> Roomnum >> Bed >> Condition >> status >> Price;
                    roomCreate.roomNo = Roomnum;
                    roomCreate.bed = Bed ;
                    roomCreate.condition = Condition ;
                    roomCreate.availableStatus = status ;
                    roomCreate.price = Price ;
                    
                    rooms.push_back( roomCreate );
                }
            }

            my_file.close();
        }

        void setResiderID( int id )
        {
            residerID = id ;
        }

        bool booking( Room room, int ID )
        {
            int i = roomMatch( room ) ;
            if( i )
            {
                rooms[i].availableStatus = false ;
                rooms[i].setResiderID( ID ) ;
                return true;
            }
            else cout << "Invalid Room Number.\n" ;
            return false ;           
        }

        void roomChanging( Room previous )
        {
            previous.availableStatus = true ;
            previous.residerID = 0 ;
        }
        
        bool isAvailable( Room room )
        {
            int i = room.roomMatch( room ) ;
            return rooms[i].availableStatus ;
        }

        int roomMatch( Room room )
        {
            for( int i=0 ; i < rooms.size() ; i++ )
            {
                if ( rooms[i].roomNo == room.roomNo )
                {
                    return i ;
                    break;
                } 
            }
            return 0;
        }

        void showRoomList()
        {
            if( rooms.size() != 0 )
            {
                cout << " Available rooms : \n" ;
                for( int i=0 ; i < rooms.size() ; i++ )
                {
                    if ( rooms[i].availableStatus )
                    {
                        cout << rooms[i].roomNo << " : " << rooms[i].bed << "-" << rooms[i].condition << " $" << rooms[i].price << endl ;
                    } 
                }
            }
                
            else
                cout << "Sorry. No Room Available.\n" ;

        }
};