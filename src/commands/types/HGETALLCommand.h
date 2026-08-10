#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class HGETALLCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    HGETALLCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
