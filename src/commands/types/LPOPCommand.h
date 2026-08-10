#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class LPOPCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    LPOPCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
