#include "HGETCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;

HGETCommand :: HGETCommand(StorageEngine& engine):engine(engine){



}

string HGETCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateHGET(tokens)){
        return "INVALID COMMAND\n";
        
    }

    return engine.hget(tokens[1],tokens[2])+"\n";


}