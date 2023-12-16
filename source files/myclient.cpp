#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "myhelper/myhelper.cpp"
#include "mysocket/mysocket.cpp"

#include<conio.h>

#define BUF 1024
#define ipc "127.0.0.1"            
#define port 8800

using namespace std;

string caToStr( char* a )
{
    string s(a);
 
    return s;
}


void messageOption( int ClientID )
{
   
   MySocket clientSocket( ipc, port ); 
   clientSocket.createSocket();
   clientSocket.connectSocket();

   char buffer[BUF], command[BUF];

   cout << clientSocket.recvMessage() << endl;
   int choice = 1 ;

   
   while( choice != 3 )
   {
      
      cout << "\nGive any of the commands- \n1. SEND. \n2. READ. \n3. QUIT.\n-> ";
      
      cin >> choice ;         
      strcpy ( command, to_string(choice).c_str() );
      clientSocket.sendMessage(command);

      if ( strcmp( command, "1" ) == 0 )  // SENDING
      {
         string sender, receiver, mail;
   
         sender = to_string(ClientID) ;
         cout <<"\nSender ID : " << sender ;
         sender += "\0" ;
   
         strcpy( buffer, to_string( ClientID ).c_str( ) );

         clientSocket.sendMessage(buffer);
         sleep( 1 );

         cout << "\nReceiver mailID : ";

         if( ClientID == 123456 ) cin >> receiver ;    
         else
         {
            receiver = "123456\0" ;
         }                
         cout << receiver << endl ; 
                        
         strcpy( buffer, receiver.c_str() );

         clientSocket.sendMessage( receiver.c_str() );

         cout << "Type Message(type ( .END. ) to terminate) : \n" ;

         do
         {
            getline( cin, mail ) ; 

            //cout << mail << endl ;

            clientSocket.sendMessage( mail.c_str() );

         } while ( mail.find(".END.", 0 ) > 5000 ) ;
         cout << clientSocket.recvMessage() << endl;
      }
      else if ( strcmp( command, "2" ) == 0 )     // LIST + READ  :
      {  
         strcpy( buffer , to_string( ClientID ).c_str() ) ;
         
         clientSocket.sendMessage(buffer);

         string mailSubject, numberOfMails;

         numberOfMails = clientSocket.recvMessage();
         cout << numberOfMails;

         int mailAmount = stoi(numberOfMails.substr(0, numberOfMails.find(' ')) );
         int mailNo ;
         
         if ( mailAmount > 0 )
         {
            for (int i = 1; i <= mailAmount; i++)
            {
               clientSocket.sendMessage("OK");

               mailSubject = clientSocket.recvMessage();
            
               // mailSubject = mailSubject.substr(mailSubject.find('_') + 1, mailSubject.length()) + ' ' 
               //    + mailSubject.substr(0,mailSubject.find('_'));
               cout << mailSubject << endl;
            }

            
            cout << "Enter mail number you want to read:";
            cin >> mailNo ;
         }
         else  mailNo = 0 ;
         cout << endl ;

         strcpy( buffer , to_string( mailNo ).c_str() ) ;
         clientSocket.sendMessage(buffer);

         string mailOutput;
         string resp = clientSocket.recvMessage();
         cout << resp << endl;

         if (resp == "OK")
         {
            while (1)
            {
               clientSocket.sendMessage("OK\0");
               mailOutput = clientSocket.recvMessage();
               if (mailOutput == ".END.")
               {
                  break;
               }
               cout << mailOutput;
            }
         }
      }
      else if (strcmp(command, "3") == 0)
      {
         break;
      }
      else
      {
         cout << "\nUnknown command!";
      }
       
   }

}