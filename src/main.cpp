#include <iostream>
#include <thread>
#include "storage/StorageEngine.h"
#include "commands/factory/CommandFactory.h"
#include "commands/CommandHandler.h"
#include "parser/CommandParser.h"
#include "server/RedisServer.h"



using namespace std;

int main(){
    PersistenceManager persistence;
    StorageEngine engine(persistence);
    CommandFactory factory(engine);

    CommandHandler handler(factory);

    CommandParser parser;
    bool stop=false;

    thread cleanupThread([&engine,&stop](){
        while(!stop){
            engine.cleanupExpiredKeys();
            this_thread::sleep_for(chrono::minutes(10));
        }
    });
    string line;

    
    RedisServer server(parser,handler);
    server.start();
    
    cleanupThread.join();

    return 0;
}