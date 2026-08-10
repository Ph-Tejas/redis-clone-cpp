#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class RPOPCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    RPOPCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
