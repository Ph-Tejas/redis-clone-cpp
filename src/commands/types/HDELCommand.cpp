#include "HDELCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;


HDELCommand :: HDELCommand(StorageEngine& engine):engine(engine){



}

string HDELCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateHDEL(tokens)){
        return "INVALID COMMAND\n";
        
    }

    return to_string(engine.hdel(tokens[1],tokens[2]))+"\n";


}