#pragma once

#include "../parser/CommandParser.h"
#include "../commands/CommandHandler.h"

class RedisServer
{
private:
    CommandParser& parser;
    CommandHandler& handler;
   

public:
    RedisServer(CommandParser& parser,
                CommandHandler& handler);

    void start();
    void handleClient(int clientSocket);
};