#include "CommandParser.h"

#include <sstream>
using namespace std;
vector<string> CommandParser::parse(const string &line){
    vector<string> tokens;

    stringstream ss(line);

    string token;

    while(ss >> token){
        tokens.push_back(token);
    }

    if(!tokens.empty()){
        for(auto &ch : tokens[0]){
            ch = toupper(ch);
        }
    }

    return tokens;
}
