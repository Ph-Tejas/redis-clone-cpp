#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class LPUSHCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    LPUSHCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
