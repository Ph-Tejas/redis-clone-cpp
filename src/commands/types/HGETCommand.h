#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class HGETCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    HGETCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
