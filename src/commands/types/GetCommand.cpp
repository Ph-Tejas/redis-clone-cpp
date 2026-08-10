#include "GetCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;

GetCommand :: GetCommand(StorageEngine& engine):engine(engine){



}

string GetCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateGet(tokens)){
        return "INVALID COMMAND\n";
        
    }

    return engine.get(tokens[1])+"\n";


}