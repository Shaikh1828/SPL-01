#include<bits/stdc++.h>
using namespace std ;

#include "Clients.cpp"

class Manager
{
    private:
        string ID;
        string password;
    public:
        void clintList()
        {
            Clients client ;
            client.printList();
        }

        void employeeList()
        {
            cout << "\n Employee list : \n-----------\n" ;
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
            cout << "\nRecord:\n---------\n" ;
            ifstream my_file;
            my_file.open( "record.txt", ios::in );
            if ( !my_file ) 
            {
                cout << "No such file";
            }
            else 
            {
                string line, sec;
                int num;

                while ( 1 ) 
                {
                    if (my_file.eof())
				        break;
                    my_file >> line >> num >> sec ;
                    cout << line << " " << sec << " " << num << endl;
                }

            }

            my_file.close();
        }

        void seeMessages()
        {
            cout << "\nInbox:\n---------\n" ;
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

};

// int main()
// {
//     Manager m;
//     m.clintList();
//     m.employeeList();
//     m.Record();
//     m.seeMessages();
// }