#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include "../../storage/StorageEngine.h"
#include "../../ICommand.h"
#include "CommandFactory.h"
#include "../types/SetCommand.h"
#include "../types/GetCommand.h"
#include "../types/SizeCommand.h"
#include "../types/ExistsCommand.h"
#include "../types/DelCommand.h"
#include "../types/ExpireCommand.h"
#include "../types/TTLCommand.h"

#include "../types/LPUSHCommand.h"
#include "../types/LPOPCommand.h"
#include "../types/RPOPCommand.h"
#include "../types/RPUSHCommand.h"


#include "../types/HSETCommand.h"
#include "../types/HGETCommand.h"
#include "../types/HDELCommand.h"
#include "../types/HGETALLCommand.h"


using namespace std; 

unordered_map<string, unique_ptr<ICommand>> CommandFactory::createCommands;
CommandFactory::CommandFactory(StorageEngine& engine):engine(engine){
  createCommands["SET"] = make_unique<SetCommand>(engine);
  createCommands["GET"] = make_unique<GetCommand>(engine);
  createCommands["SIZE"] = make_unique<SizeCommand>(engine);
  createCommands["EXISTS"] = make_unique<ExistsCommand>(engine);
  createCommands["DEL"] = make_unique<DelCommand>(engine);
  createCommands["EXPIRE"] = make_unique<ExpireCommand>(engine);
  createCommands["TTL"] = make_unique<TTLCommand>(engine);
  createCommands["LPUSH"] = make_unique<LPUSHCommand>(engine);
  createCommands["RPUSH"] = make_unique<RPUSHCommand>(engine);
  createCommands["LPOP"] = make_unique<LPOPCommand>(engine);
  createCommands["RPOP"] = make_unique<RPOPCommand>(engine);


  createCommands["HSET"] = make_unique<HSETCommand>(engine);
  createCommands["HGET"] = make_unique<HGETCommand>(engine);
  createCommands["HDEL"] = make_unique<HDELCommand>(engine);
  createCommands["HGETALL"] = make_unique<HGETALLCommand>(engine);


  
  
}




