#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class TTLCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    TTLCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
