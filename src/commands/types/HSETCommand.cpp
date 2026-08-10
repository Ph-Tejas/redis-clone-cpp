#include "HSETCommand.h"
#include "../../storage/StorageEngine.h"

#include "../../validation/CommandValidator.h"
#include <iostream>

using namespace std;



HSETCommand :: HSETCommand(StorageEngine& engine):engine(engine){



}

string HSETCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateHSET(tokens)){
        return "INVALID COMMAND\n";
        
    }

    engine.hset(tokens[1],tokens[2],tokens[3]);

    return "OK\n";

}