#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <unordered_map>
#include <mutex>
#include "../cache/LRUCache.h"
#include "../persistence/PersistenceManager.h"

using namespace std;

class StorageEngine {
private:
    PersistenceManager &persistence;
    unordered_map<string, string> data;
    unordered_map<string, deque<string>> lists;
    unordered_map<string,unordered_map<string,string>> hashes;
    
    unordered_map<string,time_t> expiry;
    mutex mtx;
    LRUCache lru;
    
    bool isExpired(const string &key);
    void replayCommand(const string& command);
public:
    StorageEngine(PersistenceManager &p);

    void cleanupExpiredKeys();
    
    void set(const string &key, const string &value);

    bool exists(const string &key);

    string get(const string &key);

    bool del(const string &key);

    int get_size();

    bool expire(const string &key,const string &value);

    
    long long ttl(const string &key);

    void lpush(const string& key, const string& value);

    void rpush(const string& key, const string& value);

    string lpop(const string& key);

    string rpop(const string& key);

    void hset(const string& key,const string& field,const string& value);

    string hget(const string& key,const string& field);

    bool hdel(const string& key,const string& field);

    unordered_map<string,string>hgetall(const string& key);



};