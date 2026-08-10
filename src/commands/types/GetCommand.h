#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class GetCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    GetCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
