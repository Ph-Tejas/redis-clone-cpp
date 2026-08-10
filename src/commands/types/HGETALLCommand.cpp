#include "HGETALLCommand.h"

#include "../../validation/CommandValidator.h"
#include "../../storage/StorageEngine.h"

#include <iostream>

using namespace std;

HGETALLCommand :: HGETALLCommand(StorageEngine& engine):engine(engine){



}

string HGETALLCommand::execute(const vector<string>& tokens){
   if(CommandValidator::validateHGETALL(tokens)){
        return "INVALID COMMAND\n";
        
    }

    unordered_map<string,string> mp=engine.hgetall(tokens[1]);
    string response="";
    for(auto &val:mp){
      response =val.first+" "+val.second+"\n";
      

    }
    return response;

}