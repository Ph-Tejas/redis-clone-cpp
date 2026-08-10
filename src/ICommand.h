#pragma once

#include <vector>
#include <string>
using namespace std;

class ICommand {
public:

    virtual string execute(const vector<string>& tokens) = 0;

    virtual ~ICommand() = default;
};