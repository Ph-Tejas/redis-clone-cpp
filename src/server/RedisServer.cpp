
#include "RedisServer.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

using namespace std;
RedisServer::RedisServer(CommandParser& parser,
                         CommandHandler& handler)
    : parser(parser),
      handler(handler)
{

}
void RedisServer::handleClient(int clientSocket)
{
    while(true)
    {
        char buffer[1024];

        int bytesReceived = ::recv(
            clientSocket,
            buffer,
            sizeof(buffer) - 1,
            0
        );

        if(bytesReceived <= 0)
        {
            cout << "Client Disconnected\n";
            break;
        }
        if(buffer[0]=='E' && buffer[1]=='X' && buffer[2]=='I' && buffer[3]=='T'){
          cout << "Client Disconnected\n";
          break;
        }

        buffer[bytesReceived] = '\0';

        auto tokens = parser.parse(buffer);

        string response = handler.execute(tokens);

        response += "\n";

        ::send(
            clientSocket,
            response.c_str(),
            response.size(),
            0
        );
    }

    close(clientSocket);
}
void RedisServer::start()
{
  int serverSocket = ::socket(AF_INET, SOCK_STREAM, 0);

  if(serverSocket == -1)
  {
    //   cout << "Socket Creation Failed\n";
      return;
  }
//   cout << "Socket Created Successfully!\n";

  sockaddr_in serverAddress;




  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(6379);
  serverAddress.sin_addr.s_addr = INADDR_ANY;






  if(::bind(serverSocket,
          (sockaddr*)&serverAddress,
          sizeof(serverAddress)) == -1)
  {
    //   cout << "Bind Failed\n";
      close(serverSocket);
      return;
  }

//   cout << "Bind Successful!\n";



  if(::listen(serverSocket, 5) == -1)
  {
    //   cout << "Listen Failed\n";
      close(serverSocket);
      return;
  }

//   cout << "Server is Listening...\n";




//   cout << "Waiting for a client...\n";

  while(true)
    {
        int clientSocket =
            ::accept(serverSocket, nullptr, nullptr);

        if(clientSocket == -1)
            continue;

        cout << "Client Connected\n";

        thread clientThread(
                &RedisServer::handleClient,
                this,
                clientSocket
            );
            
            clientThread.detach();
    }

  close(serverSocket);







}
