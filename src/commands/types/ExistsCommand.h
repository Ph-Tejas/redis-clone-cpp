#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;
class CommandValidator;
class ExistsCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    ExistsCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
