#include "StorageEngine.h"


StorageEngine::StorageEngine(PersistenceManager &p)
    : persistence(p), lru(3)
{
    auto commands = persistence.loadCommands();

    for(const string& command : commands)
    {
        replayCommand(command);
    }

}
void StorageEngine::replayCommand(const string& command)
{
    stringstream ss(command);

    string cmd;
    ss >> cmd;

    if(cmd == "SET")
    {
        string key, value;

        ss >> key >> value;

        data[key] = value;
    }

    else if(cmd == "DEL")
    {
        string key;

        ss >> key;

        data.erase(key);
        expiry.erase(key);
    }

    else if(cmd == "EXPIREAT")
    {
        string key;
        long long timestamp;

        ss >> key >> timestamp;

        if(time(nullptr) < timestamp)
        {
            expiry[key] = timestamp;
        }
        else
        {
            data.erase(key);
            expiry.erase(key);
        }
    }

    else if(cmd == "LPUSH")
    {
        string key, value;

        ss >> key >> value;

        lists[key].push_front(value);
    }

    else if(cmd == "RPUSH")
    {
        string key, value;

        ss >> key >> value;

        lists[key].push_back(value);
    }

    else if(cmd == "LPOP")
    {
        string key;

        ss >> key;

        auto it = lists.find(key);

        if(it != lists.end() && !it->second.empty())
        {
            it->second.pop_front();

            if(it->second.empty())
                lists.erase(it);
        }
    }

    else if(cmd == "RPOP")
    {
        string key;

        ss >> key;

        auto it = lists.find(key);

        if(it != lists.end() && !it->second.empty())
        {
            it->second.pop_back();

            if(it->second.empty())
                lists.erase(it);
        }
    }

    else if(cmd == "HSET")
    {
        string key, field, value;

        ss >> key >> field >> value;

        hashes[key][field] = value;
    }

    else if(cmd == "HDEL")
    {
        string key, field;

        ss >> key >> field;

        auto it = hashes.find(key);

        if(it != hashes.end())
        {
            it->second.erase(field);

            if(it->second.empty())
                hashes.erase(it);
        }
    }
}


void StorageEngine::cleanupExpiredKeys()
{
    lock_guard lock(mtx);

    for(auto it = expiry.begin(); it != expiry.end(); )
    {
        if(time(nullptr) >= it->second)
        {
            data.erase(it->first);
            hashes.erase(it->first);
            lru.remove(it->first);

            it = expiry.erase(it);
        }
        else
        {
            ++it;
        }
    }

    
}
void StorageEngine::set(const string& key, const string& value)
{
    lock_guard lock(mtx);

    if(!lru.contains(key) && lru.isFull())
    {
        string evictedKey = lru.evict();

        data.erase(evictedKey);
        expiry.erase(evictedKey);

        persistence.appendCommand(
            "DEL " + evictedKey
        );
    }

    data[key] = value;

    lru.access(key);

    persistence.appendCommand(
        "SET " + key + " " + value
    );
}

bool StorageEngine::exists(const string &key) {
    lock_guard<mutex> lock(mtx);

    if(isExpired(key)){
        cout<<"Expired!!"<<"\n";
        return false;
    }

    return data.find(key) != data.end();
}

string StorageEngine::get(const string& key)
{
    lock_guard<mutex> lock(mtx);

    auto it = data.find(key);

    if(it == data.end())
        return "NotFound";

    if(isExpired(key))
    {
        data.erase(it);
        expiry.erase(key);
        

        return "Expired!!";
    }
    lru.access(key);


    return it->second;
}

bool StorageEngine::del(const string &key) {
    lock_guard<mutex> lock(mtx);

    auto it = data.find(key);

    if(it == data.end())
        return false;

    data.erase(it);
    expiry.erase(key);
    lru.remove(key);

    persistence.appendCommand(
        "DEL " + key
    );



    return true;

}

int StorageEngine::get_size() {
    lock_guard<mutex> lock(mtx);
    return data.size();
}

bool StorageEngine::expire(const string& key, const string& value)
{
    lock_guard lock(mtx);

    if(data.find(key) == data.end())
        return false;

    long long expireAt = time(nullptr) + stoll(value);

    expiry[key] = expireAt;

    persistence.appendCommand(
        "EXPIREAT " + key + " " + to_string(expireAt)
    );

    return true;
}

bool StorageEngine::isExpired(const string &key)
{
    auto it = expiry.find(key);

    if(it == expiry.end())
        return false;

    if(time(nullptr) >= it->second)
    {
        data.erase(key);
        expiry.erase(key);
        hashes.erase(key);
        lru.remove(key);
        
        return true;
    }

    return false;
}

long long StorageEngine::ttl(const string& key)
{
    lock_guard lock(mtx);

    auto dataIt = data.find(key);

    if(dataIt == data.end())
        return -2;

    auto it = expiry.find(key);

    if(it == expiry.end())
        return -1;

    if(time(nullptr) >= it->second)
    {
        data.erase(dataIt);
        expiry.erase(it);
        hashes.erase(key);
        

        return -2;
    }

    return it->second - time(nullptr);
}

void StorageEngine::lpush(const string& key, const string& value){
    lock_guard<mutex> lock(mtx);
    lists[key].push_front(value);
    persistence.appendCommand(
        "LPUSH " + key + " " + value
    );
}

void StorageEngine::rpush(const string& key, const string& value){
    lock_guard<mutex> lock(mtx);
    lists[key].push_back(value);
    persistence.appendCommand(
        "RPUSH " + key + " " + value
    );
}

string StorageEngine::lpop(const string& key){
    lock_guard<mutex> lock(mtx);
    auto it = lists.find(key);

    if(it == lists.end() || it->second.empty())
        return "EMPTY LIST";
    string str=lists[key].front();
    lists[key].pop_front();
    persistence.appendCommand(
        "LPOP " + key
    );
    return str;
}

string StorageEngine::rpop(const string& key){
    lock_guard lock(mtx);
    auto it = lists.find(key);

    if(it == lists.end() || it->second.empty())
        return "EMPTY LIST";
    string str=lists[key].back();
    lists[key].pop_back();
    persistence.appendCommand(
        "RPOP " + key
    );
    return str;
}


void StorageEngine::hset(const string& key,const string& field,const string& value){
    lock_guard<mutex> lock(mtx);
    hashes[key][field]=value;
    persistence.appendCommand(
        "HSET " + key + " " + field + " " + value
    );
    


}
string StorageEngine::hget(const string& key,const string& field){
    lock_guard<mutex> lock(mtx);
    if(isExpired(key))return "NotFound";
    

    auto it = hashes.find(key);

    if(it != hashes.end()){
        auto fieldIt = it->second.find(field);

        if(fieldIt != it->second.end())
            return fieldIt->second;
    }
    return "Not Found!";


}
bool StorageEngine::hdel(const string& key,const string& field){
    lock_guard<mutex> lock(mtx);
    if(hashes.find(key)!=hashes.end()){
        if(hashes[key].find(field)!=hashes[key].end()){
            hashes[key].erase(field);
            persistence.appendCommand(
                "HDEL " + key + " " + field
            );
            
            return true;
        }
    }

    return false;

}
unordered_map<string,string> StorageEngine::hgetall(const string& key){
    lock_guard<mutex> lock(mtx);
    auto it = hashes.find(key);

    if(it != hashes.end()){
        return it->second;
    }
    return {};


}

