#include<iostream>
#include<vector>
#include <string>
#include "CommandValidator.h"

bool CommandValidator:: validateSet(const vector<string>& tokens){
  return tokens.size()!=3;
}
bool CommandValidator:: validateGet(const vector<string>& tokens){
  return tokens.size()!=2;
}
bool CommandValidator:: validateDel(const vector<string>& tokens){
  return tokens.size()!=2;
}
bool CommandValidator:: validateExists(const vector<string>& tokens){
  return tokens.size()!=2;
}
bool CommandValidator:: validateSize(const vector<string>& tokens){
  return tokens.size()!=1;
}
bool CommandValidator:: validateExpire(const vector<string>& tokens){
  return tokens.size()!=3;
}
bool CommandValidator:: validateTTL(const vector<string>& tokens){
  return tokens.size()!=2;
}

bool CommandValidator::validateLPUSH(const vector<string>& tokens){
  return tokens.size()!=3;
}
bool CommandValidator::validateLPOP(const vector<string>& tokens){
  return tokens.size()!=2;
}
bool CommandValidator::validateRPUSH(const vector<string>& tokens){
  return tokens.size()!=3;
}
bool CommandValidator::validateRPOP(const vector<string>& tokens){
  return tokens.size()!=2;
}

bool CommandValidator::validateHGET(const vector<string>& tokens){
  return tokens.size()!=3;
}
bool CommandValidator::validateHSET(const vector<string>& tokens){
  return tokens.size()!=4;
}
bool CommandValidator::validateHDEL(const vector<string>& tokens){
  return tokens.size()!=3;
}
bool CommandValidator::validateHGETALL(const vector<string>& tokens){
  return tokens.size()!=2;
}
