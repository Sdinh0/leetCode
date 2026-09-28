#include <unordered_map>
#include <list>

class LRUCache {
private:
    using ListIterator = std::list<std::pair<int, int>>::iterator;

    std::list<std::pair<int, int>> items;
    std::unordered_map<int, ListIterator> cache;
    size_t capacity = 0;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) 
    {
        int result;
        auto iterator = cache.find(key);
        
        if (iterator == cache.end())
        {
            result = -1;
        }
        else
        {
            items.splice(items.begin(), items, iterator->second);
            result = iterator->second->second;
        }

        return result;
    }
    
    void put(int key, int value) 
    {
        auto iterator = cache.find(key);

        if (iterator != cache.end())
        {
            items.splice(items.begin(), items, iterator->second);
            iterator->second->second = value;
        }
        else
        {
            if (cache.size() == capacity)
            {
                int keyToDelete = items.back().first;
                items.pop_back();
                cache.erase(keyToDelete);
            }
            
            items.emplace_front(key, value);
            cache[key] = items.begin();
        }
        
    }
};