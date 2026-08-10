#include "RPOPCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;


RPOPCommand :: RPOPCommand(StorageEngine& engine):engine(engine){



}

string RPOPCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateRPOP(tokens)){
        return "INVALID COMMAND\n";
       
    }
    

    return engine.rpop(tokens[1])+"\n";


}