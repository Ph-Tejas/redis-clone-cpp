#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class ExpireCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    ExpireCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
