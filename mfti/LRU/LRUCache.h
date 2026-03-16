#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;

    using Node = std::pair<int, int>;
    std::list<Node> cache;

    std::unordered_map<int, std::list<Node>::iterator> map;

public:
    explicit LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);
};

#endif
