#pragma once
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include <memory>
#include "../../storage/StorageEngine.h"
#include "../../ICommand.h"

using namespace std;


class StorageEngine;

class CommandFactory{
public:
  StorageEngine& engine;

  static unordered_map<string,unique_ptr<ICommand>>createCommands;


  CommandFactory(StorageEngine& engine);
};

