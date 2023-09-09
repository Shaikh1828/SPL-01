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
            roomNo = 0;
            bed = "" ;
            condition = "";
            availableStatus = true;
        }

        Room( int initialize )
        {
            roomsUpdate() ;
        }

        int getResiderID()
        {
            return this->residerID;
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
                int Roomnum, Price , Resider;
                bool status;

                while ( 1 ) 
                {
                    Room roomCreate;
                    if ( my_file.eof() )
				        break;
                    my_file >> Roomnum >> Bed >> Condition >> status >> Price >> Resider ;
                    roomCreate.roomNo = Roomnum;
                    roomCreate.bed = Bed ;
                    roomCreate.condition = Condition ;
                    roomCreate.availableStatus = status ;
                    roomCreate.price = Price ;
                    roomCreate.residerID = Resider ;
                    
                    rooms.emplace_back( roomCreate );
                }
            }

            my_file.close();
        }

        void updateBack()
        {
            ofstream my_file ;
            string str ;
            my_file.open( "rooms.txt", ios::trunc );
            
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                for ( int i = 0; i < rooms.size(); i++ )
                {   
                    if( i > 0 ) my_file << endl ;
                    my_file << rooms[i].roomNo << " " << rooms[i].bed << " " << rooms[i].condition << " " 
                    << rooms[i].availableStatus << " " << rooms[i].price << " " << rooms[i].getResiderID() ;
                }
                
            }
            my_file.close() ;
            
        }

        void setResiderID( int id )
        {
            residerID = id ;
        }

        bool booking( Room room, int ID )
        {
            int i = roomMatch( room ) ;
            if( i != -1 )
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
            int previousRoomIdx = roomMatch(previous) ;
            rooms[ previousRoomIdx ].availableStatus = true ;
            rooms[ previousRoomIdx ].residerID = 0 ;
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
            return -1;
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

        void checkOut( Room room )
        {
            int index = roomMatch( room );
            rooms[index].availableStatus = true ;
            rooms[index].setResiderID( 0 ) ;
        }
};

// int main()
// {
//     Room r1(1);
//     r1.showRoomList();
// }