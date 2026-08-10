#include "TTLCommand.h"
#include "../../storage/StorageEngine.h"

#include "../../validation/CommandValidator.h"
#include <iostream>

using namespace std;



TTLCommand :: TTLCommand(StorageEngine& engine):engine(engine){



}

string TTLCommand::execute(const vector<string> &tokens)
{
    if(CommandValidator::validateTTL(tokens))
    {
        return "INVALID COMMAND\n";
        
    }

    return to_string(engine.ttl(tokens[1])) + "\n";
}