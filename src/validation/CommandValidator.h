#pragma once

#include<iostream>
#include <vector>

#include <string>
using namespace std;

class CommandValidator{
public:
  CommandValidator();
  static bool validateSet(const vector<string>& tokens);
  static bool validateGet(const vector<string>& tokens);
  static bool validateDel(const vector<string>& tokens);
  static bool validateExists(const vector<string>& tokens);
  static bool validateSize(const vector<string>& tokens);
  
  static bool validateExpire(const vector<string>& tokens);
  static bool validateTTL(const vector<string>& tokens);
  static bool validateLPUSH(const vector<string>& tokens);
  static bool validateLPOP(const vector<string>& tokens);
  static bool validateRPUSH(const vector<string>& tokens);
  static bool validateRPOP(const vector<string>& tokens);
  
  static bool validateHGET(const vector<string>& tokens);
  static bool validateHSET(const vector<string>& tokens);
  static bool validateHDEL(const vector<string>& tokens);
  static bool validateHGETALL(const vector<string>& tokens);

};