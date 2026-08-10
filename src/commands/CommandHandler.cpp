
#include <iostream>
#include "CommandHandler.h"
#include "factory/CommandFactory.h"

using namespace std;


CommandHandler::CommandHandler(CommandFactory& factory): factory(factory){
  
  
}

string CommandHandler::execute(const vector<string>& tokens) {
    if(tokens.empty())return "";
    auto it = factory.createCommands.find(tokens[0]);

    if (it == factory.createCommands.end()) {
        return "UNKNOWN COMMAND\n";
    }

    string response;

    try {
        response = it->second->execute(tokens);
    }
    catch (const exception& e) {
        return "ERR: " + string(e.what()) + "\n";
    }

    return response;
}

