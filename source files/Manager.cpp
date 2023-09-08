#include<bits/stdc++.h>
using namespace std ;

class Manager
{
    private:
        string ID;
        string password;

    public:

        void employeeList()
        {
            cout << "\n\n    Employee list : \n-----------------\n" ;
            ifstream my_file;
            my_file.open( "EmployeeList.txt", ios::in );
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                string line;

                while ( getline(my_file, line)) 
                {
                    cout << line << endl;
                }

            }

            my_file.close();
        }

        void Record()
        {
            cout << "\n\n----------\nRecord:\n---------\n\n" ;
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
                    if ( my_file.eof() ) break;
				        
                    my_file >> id >> Pass >> Name >> Phone >> Food >> Room >> Total >> Due ;

                    cout << id << " - " << Name << " Phone : " << Phone << endl ;
                   
                }
            }

            my_file.close();
        }
        

        void seeMessages()
        {
            cout << "\n\nInbox:\n---------\n\n" ;
            ifstream my_file;
            my_file.open( "messages.txt", ios::in );
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                string line;

                while ( getline(my_file, line)) 
                {
                    cout << line << endl;
                }

            }

            my_file.close();
        }

        void clientList()
        {
            cout << "\n--------------\nCurrent Clients: \n-------------\n" ;
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
                    if ( my_file.eof() ) break;
				        
                    my_file >> id >> Pass >> Name >> Phone >> Food >> Room >> Total >> Due ;

                    if( Room != 0 )cout << id << " - " << Name << " Phone : " << Phone << endl ;
                   
                }
            }

            my_file.close();
        
        }

        bool login(  )
        {
            int n = 3 , ID;
            bool match = false;
            string Password ;
            while ( n-- )
            {   
                getchar() ;
                cout << "Please enter ID : " ;
                cin >> ID ;
                cout << "Please enter password : " ;
                cin >> Password ;
                match = matchIDPass( ID, Password );
                if( match ) break;
                if( n != 0 ) cout << "Incorrect ID or Password. Try again.\n" ;
            }
          
            return match ;              
        }

        bool matchIDPass( int ID, string Password )
        {
            ifstream my_file;
            string realPass;
            int realID;
            my_file.open( "manager.txt", ios::in );
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                my_file >> realID >> realPass ;
            }

            my_file.close();

            if ( ID == realID && Password == realPass )
            {
                return true;
            }
            else return false ;
        }

        void duesCheck()
        {
            int totalDue = 0;
            vector <int> dues ;
            vector <int> ids ;

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
                    if ( my_file.eof() ) break;
				        
                    my_file >> id >> Pass >> Name >> Phone >> Food >> Room >> Total >> Due ;

                    totalDue += Due ;
                    dues.push_back ( Due ) ;
                    ids.push_back( id );

                }
            }
            my_file.close();

            sorting( dues, ids );
            
            cout << "Total Due : " << totalDue << endl ;

        }

        void sorting( vector <int> dues , vector <int> ids )
        {
            int temp ;
            for ( int i = 0; i < dues.size(); i++ )
            {
                for( int j = i ; j < dues.size()-1 ; j++ )
                {
                    if( dues[j] < dues[j+1] )
                    {
                        temp = dues[j+1];
                        dues[j+1] = dues[j] ;
                        dues[j] = temp ;
                        temp = ids[j+1];
                        ids[j+1] = ids[j] ;
                        ids[j] = temp ;
                    }
                }
            }
            
            for ( int i = 0; i < dues.size(); i++ )
            {
                if( dues[i] > 0 ) cout << ids[i] << " - " << dues[i] << endl ;
            }
            
        }

};

// int main()
// {
//     Manager m;
//     m.clientList();
//     m.employeeList();
//     m.Record();
//     m.seeMessages();
// }