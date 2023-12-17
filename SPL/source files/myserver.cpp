#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <iostream>
#include <vector>
#include<algorithm>
#include <fstream>
#include <thread>
#include <mutex>
#include "myhelper/myhelper.cpp"
#include "mysocket/mysocket.cpp"

using namespace std;

mutex mtx;

string CaToStr( const char* a )
{
    string s(a);
 
    return s;
}

void serverThread(MyHelper helper, MySocket &serverSocket, int new_socket, string argDir)  
{
   string command, buffer, message;
   do
   {
      command = serverSocket.recvMessage(new_socket);

      if (command == "1")
      {
         string sender = serverSocket.recvMessage(new_socket);   
         cout << "Working on mailing.\n" ;    //  id
         string receiver = serverSocket.recvMessage(new_socket);    
         cout << message << endl;

         while (1)
         {
            buffer = serverSocket.recvMessage(new_socket);
            cout << buffer << endl ;
            if ( buffer.find( ".END.", 0 ) < 500 )
            {
               message += buffer ;
               break ;
            }
            message += buffer ;
            message += "\n" ;
         }

            string fullDir = argDir + '/' + receiver;
            int mailId ;   

            if (access(fullDir.c_str(), F_OK) == -1)     
            {
               mkdir( fullDir.c_str(), 0700 );
               cout << "Created directory " << fullDir << endl;
            }

            mtx.lock();

            mailId = helper.filesInDirectory(fullDir) + 1 ;
            string filename = fullDir + "/" + to_string(mailId) + "_"+ sender + ".txt" ;

            // while (1)
            // {
            //    if (helper.fileExists(filename))
            //    {
            //       mailId++;
            //       filename = fullDir + '/' + to_string(mailId) + ".txt";    //   1_statAsk.txt
            //    }
            //    else
            //    {
            //       break;
            //    }
            // }

            ofstream file;
            file.open(filename.c_str(), ios::out);
            file << message ;
            cout << "Mail from user " << sender << " sent to " << receiver << " at " << filename << endl;
            serverSocket.sendMessage("SENT!!\n", new_socket);
            file.close();
            mtx.unlock();
      }
      else if (command == "2")        // list & read
      {
         string user = serverSocket.recvMessage(new_socket);     
      
         string dirPath = argDir + "/" + user ;

         if ( access(dirPath.c_str(), F_OK) == -1 )
         {
            buffer = "0 mails for user " + user ;
            serverSocket.sendMessage(buffer.c_str(), new_socket);
            sleep( 1 );
         }
         else
         {
            vector<string> mails;

            mails = helper.subjectsInDirectory(dirPath);
            //sort(mails.begin(), mails.end());                  
            buffer = to_string(mails.size()) + " mails for user " + user;
            serverSocket.sendMessage(buffer.c_str(), new_socket);
            sleep( 1 );

            if (mails.size() > 0)
            {
               cout << "Sent list of mails from user " << user << " to client" << endl;
               for (unsigned int i = 0; i < mails.size(); i++)   // i = 1/0 ?
               {
                  
                  buffer = serverSocket.recvMessage(new_socket);
                  if (buffer == "OK")
                  {
                     serverSocket.sendMessage(mails[i].c_str(), new_socket);
                  }
               }
            }
         }
 
         string mailNumber = CaToStr(serverSocket.recvMessage(new_socket)) ;

         ifstream file;

         // if ( 1 )
         // {
            int mailIndex ;
            mailIndex = stoi(mailNumber) - 1 ;
            string line, fulldir;
            dirPath = argDir + "/" + user;
   
            vector<string> mails;

            // if ( mailIndex == -1 )
            // {
            //    continue ;
            // }
            

            if ( access(dirPath.c_str(), F_OK) == -1)
            {
               serverSocket.sendMessage("ERR - user INBOX is empty\0", new_socket);
            }
            else
            {
        
               mails = helper.filenamesInDirecotry(dirPath);

               if ( mailIndex < mails.size())
               {
                  fulldir = dirPath + '/' + mails[mailIndex];
                  mtx.lock();
                  file.open(fulldir.c_str());
                  if (file.is_open())
                  {
                     cout << "Sent email " << mails[mailIndex] << " informaiton from user " << user << " to client" << endl;
                     serverSocket.sendMessage("OK", new_socket);
                     while ( getline(file, line) )
                     {
                        line = line + '\n';
                        buffer = serverSocket.recvMessage(new_socket);
                        if (buffer == "OK")
                        {
                           serverSocket.sendMessage(line.c_str(), new_socket);
                        }
                     }
                  }
                  else
                  {
                     serverSocket.sendMessage("ERR - cannot open mail file\0", new_socket);
                  }
                  file.close();
                  mtx.unlock();
               }
               else
               {
                  serverSocket.sendMessage("ERR - mail does not exist\0", new_socket);
               }
            }
         // }
         // else
         // {
         //    serverSocket.sendMessage("ERR - mail number is not an integer\0", new_socket);
         // }
      }
      else if ( command == "3" )
      {
         cout << "Client exited from Messaging Portal." << endl ;
      }
      // else
      // {
      //    serverSocket.sendMessage("ERR - mail number is not an integer\0", new_socket);
      // }  

   } 
   while (command != "3");                  
   
   cout << "Client disconnected" << endl;
   close(new_socket);
}

int main( )
{
   MyHelper helper;
   int port = 8800 ;
   string mailbox = "/media/shaikh/STUDY/SPL/source files/MailBoxServer" ;                              // argv[2]

   MySocket serverSocket( port );
   serverSocket.createSocket( );
   serverSocket.bindSocket( );
   serverSocket.listenSocket( );

   int new_socket;

   cout << "Waiting for connections..." << endl;
   while (1)
   {
      new_socket = serverSocket.acceptNewConnection();

      thread( serverThread, helper, ref(serverSocket), new_socket, mailbox ).detach();
   }
   return EXIT_SUCCESS;
}