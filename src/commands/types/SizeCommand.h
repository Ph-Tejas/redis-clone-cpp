#pragma once
#include "../../ICommand.h"
using namespace std;
class StorageEngine;

class SizeCommand : public ICommand{
  private:
    StorageEngine& engine;

  public:
    SizeCommand(StorageEngine& engine);
    string execute(const vector<string>& tokens) override;
};
