#include<bits/stdc++.h>
using namespace std ;

#include "Clients.cpp"

class Hotel 
{
    public:
        void menu()
        {
            int chioce ;
            while ( 1 )
            {
                cout << "\n\n" ;
                cout << "*****************************************************" ;
                cout << "\n\n                     Room Raccon              \n\n" ;
                cout << "*****************************************************" << endl;

                cout << "\n1. Client Log in ." << endl ;
                cout << "\n2. Client Sign up .(Create new account)" << endl ;
                cout << "\n3. Log in as Manager ." << endl ;
                cout << "\n3. Exit ." << endl ; 
                cout << "\nYour Choice : " ;
                cin >> chioce ;

                switch (chioce)
                {
                    case 1:
                        cout << "1\n" ;
                        break;
                    case 2:
                        cout << "2\n" ;
                        break;
                    case 3:
                        cout << "3\n" ;
                        break;
                    case 4:
                        cout << "4\n" ;
                        break;
                    
                    default:
                        cout << "Invalid choice.\n" ;
                        break;
                }
                cout << "Press any key to continue :\n" ;
                _getwche() ;
                if( chioce == 4 ) break ;
                cout << endl ;

            }
            
            
        }
};

// int main ( )
// {
//     Hotel RoomRaccon ;
//     RoomRaccon.menu();
// }