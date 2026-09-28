#include <unordered_map>
#include <list>

class LFUCache {
private:
    using ListIterator = std::list<std::pair<int, int>>::iterator;

    std::unordered_map<int, std::list<std::pair<int, int>>> frequencyList;
    std::unordered_map<int, ListIterator> cache;
    std::unordered_map<int, int> keyFreq;

    size_t capacity = 0;
    int minFreq = 0;

    void touch(int key)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            int val = it->second->second;
            int currFreq = keyFreq[key];

            auto &oldList = frequencyList[currFreq];
            oldList.erase(it->second);
            if (oldList.empty())
            {
                frequencyList.erase(currFreq);
                if (minFreq == currFreq)
                {
                    minFreq++;
                }
            }

            keyFreq[key] = currFreq + 1;
            frequencyList[currFreq + 1].emplace_front(key, val);
            cache[key] = frequencyList[currFreq + 1].begin();
        }
        
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
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
            result = iterator->second->second;
            touch(key);
        }

        return result;
    }
    
    void put(int key, int value) 
    {
        auto iterator = cache.find(key);

        if (iterator != cache.end())
        {
            iterator->second->second = value;
            touch(key);
        }
        else
        {
            if (cache.size() == capacity)
            {
                auto &listToDelete = frequencyList[minFreq];
                auto pairToDelete = listToDelete.back();
                int keyToDelete = pairToDelete.first;
                listToDelete.pop_back();
                if (listToDelete.empty())
                {
                    frequencyList.erase(minFreq);
                }
                cache.erase(keyToDelete);
                keyFreq.erase(keyToDelete);
            }
            
            frequencyList[1].emplace_front(key, value);
            cache[key] = frequencyList[1].begin();
            keyFreq[key] = 1;
            minFreq = 1;
        }
    }
};