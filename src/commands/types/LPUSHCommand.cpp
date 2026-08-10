#include "LPUSHCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;


LPUSHCommand :: LPUSHCommand(StorageEngine& engine):engine(engine){



}

string LPUSHCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateLPUSH(tokens)){
        return "INVALID COMMAND\n";
       
    }

    engine.lpush(tokens[1],tokens[2]);
    return "OK\n";


}