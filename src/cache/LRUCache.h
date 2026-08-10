#pragma once

#include <unordered_map>
#include <list>
#include <string>

using namespace std;

class LRUCache
{
private:
    int capacity;

    list<string> order;

    unordered_map<string, list<string>::iterator> position;

public:
    LRUCache(int capacity);

    void access(const string& key);
    string evict();
    void remove(const string& key);
    bool contains(const string& key);
    bool isFull();
};