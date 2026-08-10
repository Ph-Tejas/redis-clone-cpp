#include "LPOPCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;


LPOPCommand :: LPOPCommand(StorageEngine& engine):engine(engine){



}

string LPOPCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateLPOP(tokens)){
        return "INVALID COMMAND\n";
        
    }

    return engine.lpop(tokens[1])+"\n";


}