#include<bits/stdc++.h>
using namespace std ;

#include "Clients.cpp"
#include "Room.cpp"

//vector < Clients > clientList ;

class Hotel 
{
    public:
        void loginInterface();
        void signupInterface();
        void managerLogin();
        void menu()
        {
            int choice ;
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
                cin >> choice ;

                switch (choice)
                {
                    case 1:
                        cout << "    Client Log in :    \n" ;
                        loginInterface();
                        break;
                    case 2:
                        cout << "    Client Sign up :    \n" ;
                        break;
                    case 3:
                        cout << "    Manger Log in :    \n" ;
                        break;
                    case 4:
                        cout << "    Exiting from the system ..  \n" ;
                        cout << "Press any key to continue :\n" ;
                        _getwche() ;
                        break;
                    
                    default:
                        cout << "Invalid choice.\n" ;
                        cout << "Press any key to continue :\n" ;
                        _getwche() ;
                        break;
                }

                

                if( choice == 4 ) break ;
                cout << endl ;

            }
            
            
        }
};

void Hotel::loginInterface()
{
    int match;
    Clients client ;
    match = client.login( client );
    if( match != -1 )
    {
        int choice = 1 ;
        while ( choice != 8 )
        {
            cout << clientList[match].name << "-" << clientList[match].getID() << endl ;
            cout << "1. Book Room .\n\n" ;
            cout << "2. Enroll Food-package .\n\n" ;
            cout << "3. Current Status .\n\n" ;
            cout << "4. Change Room .\n\n" ;
            cout << "5. Change Food-package .\n\n" ;
            cout << "6. Change Password .\n\n" ;
            cout << "7. Check out .\n\n" ;
            cout << "8. Complains or Suggestions .\n\n" ;
            cout << "9. Log out \n\n." ;

            switch (choice)
            {
                case 1:
                { 
                    Room room( 1 );
                    clientList[match].bookRoom( );
                    break;
                }
                case 2:
                {
                    cout << "Food selection menu : \n" ;
                    clientList[match].enrollFood();
                    break;
                }
                case 3:
                {    
                    cout << "Current update :\n" ;
                    clientList[match].printStatus();
                    break;
                }
                case 4:
                {    
                    cout << "Room Changing menu :\n" ;
                    clientList[match].changeRoom( );
                    break;
                }
                case 5:
                {
                    cout << "Food-package changing menu :\n" ;
                    clientList[match].foodChange() ;
                    break;
                }
                case 6:
                {
                    cout << "4\n" ;
                    
                    break;
                }
                case 7:
                {
                    cout << "4\n" ;
                    
                    break;
                }
                case 8:
                {
                    cout << "4\n" ;
                    
                    break;
                }
                case 9:
                {
                    cout << "4\n" ;
                    
                    break;
                }
                default:
                {
                    cout << "Invalid choice.\n" ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                    break;
                }
            }
        }
        
    }
    else
    {
        cout << "Either no profile is created or Invalid ID-Password. \n" ; 
    }

}

void Hotel::signupInterface()
{

}

void Hotel::managerLogin()
{
    
}

int main ( )
{
    Hotel RoomRaccon ;
    RoomRaccon.menu();
}