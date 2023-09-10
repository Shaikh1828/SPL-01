#include<bits/stdc++.h>
using namespace std ;

#include "Clients.cpp"
#include "Manager.cpp"

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
                updateAll() ;
               
                cout << "\n\n" ;
                cout << "*****************************************************" ;
                cout << "\n\n                     Room Raccoon              \n\n" ;
                cout << "*****************************************************" << endl;

                cout << "\n1. Client Log in ." << endl ;
                cout << "\n2. Client Sign up .(Create new account)" << endl ;
                cout << "\n3. Log in as Manager ." << endl ;
                cout << "\n4. Exit ." << endl ; 
                cout << "\nYour Choice : " ;
                cin >> choice ;

                switch (choice)
                {
                    case 1:
                    {
                        Clients client(1);
                        cout << "\n\n     Client Log in :     \n\n" ;
                        loginInterface();
                        break;
                    }
                    case 2:
                    {
                        cout << "\n\n      Client Sign up :     \n\n" ;
                        cout << " Creating a profile to enroll... \n " ;
                        signupInterface();
                        break;
                    }
                    case 3:
                    {
                        cout << "\n\n      Manger Log in :    \n\n" ;
                        managerLogin() ;
                        break;
                    }
                    case 4:
                        cout << "\n\n    Exiting from the system ..  \n\n" ;
                        cout << "Press any key to continue :\n" ;
                        _getwche() ;
                        break;
                    
                    default:
                        cout << "\n\nInvalid choice.\n\n" ;
                        cout << "Press any key to continue :\n" ;
                        _getwche() ;
                        break;
                }

                if( choice == 4 ) break ;
                cout << endl ;

                sendBackUpdate();

            }
            
        }


        void updateAll()
        {
            Clients client( 1 );
            Room room( 1 );
            FoodPackage food( 1 );
        }

        void sendBackUpdate()
        {
            Clients client;
            Room room;
            client.updateBack();
            room.updateBack();
        }
};

void Hotel::loginInterface()
{
    int match;
    Clients client ;
    updateAll();
    match = client.login( client );
    if( match != -1 )
    {
        int choice = 1 ;
        while ( choice != 9 )
        {
            updateAll();
            cout << "\n\n" ;
            cout << "*****************************************************" ;
            cout << "\n\n                     Room Raccoon              \n\n" ;
            cout << "*****************************************************" << endl;
            cout << "\n\n Client : " << clientList[match].name << "  -  " << clientList[match].getID() << endl << endl ;
            cout << "-----------------------------------------------------\n\n" ;
            cout << "1. Book Room .\n\n" ;
            cout << "2. Enroll Food-package .\n\n" ;
            cout << "3. Current Status .\n\n" ;
            cout << "4. Change Room .\n\n" ;
            cout << "5. Change Food-package .\n\n" ;
            cout << "6. Change Password .\n\n" ;
            cout << "7. Check out .\n\n" ;
            cout << "8. Complains or Suggestions .\n\n" ;
            cout << "9. Log out .\n\n" ;

            cout << "Enter your choice : " ;
            cin >> choice ;

            switch ( choice )
            {
                case 1:
                { 
                    if( clientList[match].roomNo == 0 )
                        clientList[match].bookRoom( );
                    else
                    {
                        cout << "\n\nA room is already booked..\nGo to Change room..\n\n" ;
                        cout << "Press any key to continue :\n" ;
                        _getwche() ;
                    }
                    break;
                }
                case 2:
                {
                    if( clientList[match].fooding.package.size() < 6 )
                    {
                        cout << "\n\n   Food selection menu : \n\n" ;
                        clientList[match].enrollFood();
                    }
                    else 
                    {
                        cout << "\n\nA package is already enrolled..\nGo to Change food package.\n\n" ;
                        cout << "Press any key to continue :\n" ;
                        _getwche() ;
                    }                       
                    break;
                }
                case 3:
                {    
                    cout << "\n\nCurrent update :\n\n" ;
                    clientList[match].printStatus();
                    break;
                }
                case 4:
                {    
                    cout << "\n\n    Room Changing menu :\n" ;
                    clientList[match].changeRoom( );
                    break;
                }
                case 5:
                {
                    cout << "\n\n    Food-package changing menu :\n\n" ;
                    clientList[match].foodChange() ;
                    break;
                }
                case 6:
                {
                    char ch;
                    cout << "!!!  Password Changing Menu  !!!\n\n" ;
                    cout << "Enter \'C\' to continue : ";
                    cin >> ch ;
                    if( ch == 'C' )
                    {
                        clientList[match].changePassword() ;
                    }
                    break;
                }
                case 7:
                {
                    cout << "\n\nAll Due must be paid before checkout.\n\n" ;
                    clientList[match].checkOut();
                    break;
                }
                case 8:
                {
                    cout << "\n\n    Complain or suggestion box :\n\n" ;
                    clientList[match].message() ;
                    break;
                }
                case 9:
                {
                    cout << "\n\n    Logged out from your profile ..!\n\n" ;
                    cout << "Press any key to continue :\n\n" ;
                    _getwche() ;
                    break;
                }
                default:
                {
                    cout << "\n\n    Invalid choice. \n\n" ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                    break;
                }
            }

            sendBackUpdate();
        }
        
    }
    else
    {
        cout << "\n\n!!! Either no profile is created or Invalid ID-Password.  !!!\n\n" ; 
        cout << "Press any key to continue :\n" ;
        _getwche() ;
    }

}

void Hotel::signupInterface()
{
    updateAll();
    cout << "\n\n" ;
    cout << "*****************************************************" ;
    cout << "\n\n                     Room Raccoon              \n\n" ;
    cout << "*****************************************************" << endl;

    cout << "\n\n Sign up informtions : \n\n" ; 
    Clients newClient;
    newClient.signUp( );
    cout << "Press any key to continue :\n" ;
    _getwche() ;
    sendBackUpdate();
}

void Hotel::managerLogin()
{
    Manager manager;
    
    if( manager.login() )
    {
        int choice = 1 ;
        while ( choice != 6 )
        {
            updateAll();
            cout << "\n\n" ;
            cout << "*****************************************************" ;
            cout << "\n\n                     Room Raccoon              \n\n" ;
            cout << "*****************************************************" << endl;
            cout << "\n\n       Manager Control  \n------------------------------\n\n"  ;
            cout << "1. Current Client List .\n\n" ;
            cout << "2. Current Employee List .\n\n" ;
            cout << "3. Total dues .\n\n" ;
            cout << "4. Messages .\n\n" ;
            cout << "5. Record of all clients .\n\n" ;
            cout << "6. Log out .\n\n" ;

            cout << "Enter your choice : " ;
            cin >> choice ;

            switch ( choice )
            {
                case 1:
                { 
                    manager.clientList() ;
                    cout << "\n\n" ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                    
                    break;
                }
                case 2:
                {
                    manager.employeeList() ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                             
                    break;
                }
                case 3:
                {  
                    cout << "\n\nThe Dues list : \n\n " ;  
                    manager.duesCheck();
                    cout << "\n\nPress any key to continue :\n" ;
                    _getwche() ;
                    break;
                }
                case 4:
                {    
                    manager.seeMessages() ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                    break;
                }
                case 5:
                {    
                    manager.Record() ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                    break;
                }
                case 6:
                {
                    cout << "\n\n  Logging out from the Manager system ..  \n\n" ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                    break;
                }
                default:
                {
                    cout << "\n\nInvalid choice.\n\n" ;
                    cout << "Press any key to continue :\n" ;
                    _getwche() ;
                    break;
                }

            }
        }
    }
}