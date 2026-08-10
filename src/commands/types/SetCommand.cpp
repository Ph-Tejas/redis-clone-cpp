#include "SetCommand.h"
#include "../../storage/StorageEngine.h"

#include "../../validation/CommandValidator.h"
#include <iostream>

using namespace std;



SetCommand :: SetCommand(StorageEngine& engine):engine(engine){



}

string SetCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateSet(tokens)){
        return "INVALID COMMAND\n";
        
    }

    engine.set(tokens[1],tokens[2]);

    return "OK\n";

}