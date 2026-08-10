#include "RPUSHCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;


RPUSHCommand :: RPUSHCommand(StorageEngine& engine):engine(engine){



}

string RPUSHCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateRPUSH(tokens)){
        return "INVALID COMMAND\n";
      
    }

    engine.rpush(tokens[1],tokens[2]);
    return "OK\n";


}