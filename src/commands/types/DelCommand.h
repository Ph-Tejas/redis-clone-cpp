#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class DelCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    DelCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
