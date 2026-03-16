#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    std::cout << cache.get(1) << std::endl;

    cache.put(3, 30);

    std::cout << cache.get(2) << std::endl;
    std::cout << cache.get(3) << std::endl;
}
