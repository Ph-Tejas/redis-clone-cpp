#include "LRUCache.h"

LRUCache::LRUCache(int capacity)
    : capacity(capacity)
{
}

void LRUCache::access(const string& key)
{
    auto it = position.find(key);

    if(it != position.end())
        order.erase(it->second);

    order.push_front(key);
    position[key] = order.begin();
}

string LRUCache::evict()
{
    if(order.empty())
        return "";

    string key = order.back();

    order.pop_back();
    position.erase(key);

    return key;
}

void LRUCache::remove(const string& key)
{
    auto it = position.find(key);

    if(it == position.end())
        return;

    order.erase(it->second);
    position.erase(it);
}

bool LRUCache::contains(const string& key)
{
    return position.find(key) != position.end();
}
bool LRUCache::isFull()
{
    return (int)position.size() >= capacity;
}