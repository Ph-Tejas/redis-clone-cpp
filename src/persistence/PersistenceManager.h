#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class PersistenceManager{
 

  public:
  PersistenceManager();
    void appendCommand(const std::string& command);
    
    vector<string> loadCommands();



};