#include "SizeCommand.h"
#include "../../storage/StorageEngine.h"

#include "../../validation/CommandValidator.h"
#include <iostream>

using namespace std;



SizeCommand :: SizeCommand(StorageEngine& engine):engine(engine){



}

string SizeCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateSize(tokens)){
        return "INVALID COMMAND\n";
        
    }

    return to_string(engine.get_size())+"\n";


}