#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class HDELCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    HDELCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
