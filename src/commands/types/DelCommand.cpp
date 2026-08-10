#include "DelCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;


DelCommand :: DelCommand(StorageEngine& engine):engine(engine){



}

string DelCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateDel(tokens)){
        return "INVALID COMMAND\n";
        
    }

    return to_string(engine.del(tokens[1]))+"\n";


}