#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include "../ICommand.h"

using namespace std;


class CommandFactory;

class CommandHandler {
public:
    CommandFactory& factory;

    CommandHandler(CommandFactory& factory);

    string execute(const vector<string>& tokens);

};