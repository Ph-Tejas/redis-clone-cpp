#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class HSETCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    HSETCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
