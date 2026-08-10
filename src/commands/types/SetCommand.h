#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class SetCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    SetCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
