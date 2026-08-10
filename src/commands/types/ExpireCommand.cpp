#include "ExpireCommand.h"
#include "../../storage/StorageEngine.h"

#include "../../validation/CommandValidator.h"
#include <iostream>

using namespace std;



ExpireCommand :: ExpireCommand(StorageEngine& engine):engine(engine){



}

string ExpireCommand::execute(const vector<string>& tokens){
  if(CommandValidator::validateExpire(tokens))
  {
      return "INVALID COMMAND\n";
      
  }
  bool success =
      engine.expire(tokens[1],tokens[2]);

  if(success)
      return "OK\n";
  else
      return "Key not found\n";;


}