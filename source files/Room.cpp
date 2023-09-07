#include<bits/stdc++.h>
using namespace std ;

//#include "Clients.cpp"

class Room
{
    public :
        int roomNo ;
        string bed ;
        string condition ;
        bool availableStatus;
        //Clients resider;

        Room()
        {
            
        }

        vector < Room > rooms ;

        void booking( Room room )
        {
            int i = room.roomMatch( room ) ;
            rooms[i].availableStatus = false ;
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
        }

        void showRoomList()
        {
            for( int i=0 ; i < rooms.size() ; i++ )
            {
                if ( rooms[i].availableStatus )
                {
                    cout << rooms[i].roomNo << " : " << rooms[i].bed << "-" << rooms[i].condition << endl ;
                } 
            }
        }
};