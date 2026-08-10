#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class RPUSHCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    RPUSHCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
