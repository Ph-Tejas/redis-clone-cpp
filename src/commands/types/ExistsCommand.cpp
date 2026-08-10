#include "ExistsCommand.h"
#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;



ExistsCommand :: ExistsCommand(StorageEngine& engine):engine(engine){



}

string ExistsCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateExists(tokens)){
        return "INVALID COMMAND\n";
        
    }

    return to_string(engine.exists(tokens[1]))+"\n";


}