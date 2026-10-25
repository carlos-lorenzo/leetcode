#include <cstddef>
#include <unordered_map>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 47.76709%



// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// 
// Implement the LRUCache class:
// 
// 
// 	LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// 	int get(int key) Return the value of the key if the key exists, otherwise return -1.
// 	void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// 
// 
// The functions get and put must each run in O(1) average time complexity.
// 
//  
// Example 1:
// 
// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]
// 
// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= capacity <= 3000
// 	0 <= key <= 10⁴
// 	0 <= value <= 10⁵
// 	At most 2 * 10⁵ calls will be made to get and put.
// 
 

class LRUCache {

    struct alignas(64) TrackerNode {
        int key;
        int older_idx;
        int newer_idx;
    };

    struct alignas(64) MapNode {
        int value;
        int lru_idx;
    };

public:
    LRUCache(int capacity) {
        data_map_.reserve(capacity);
        lru_tracker_.resize(capacity, {-1, -1, -1});
        size_ = 0;
        capacity_ = capacity;

        // Defaulting to values outside of vector
        fresh_idx = capacity;
        stale_idx = capacity;
    }
    
    int get(int key) {
        auto it = data_map_.find(key);
        if (it == data_map_.end()) {
            return -1; // Key not found
        }

        // Dereference the iterator to unpack the map's key and node
        auto& [map_key, map_node] = *it; 
        

        auto value = map_node.value;
        auto lru_idx = map_node.lru_idx;

        // If the read key was the one that hadn't been read in the most amount of time, set the new stale as the previous' stale next index
        if (stale_idx == lru_idx) {
            stale_idx = lru_tracker_[lru_idx].newer_idx;
            lru_tracker_[stale_idx].older_idx = -1;
        }
        
        
        // Set the previous' freshest newer index as the newly read value
        lru_tracker_[fresh_idx].newer_idx = lru_idx;

        // Set the previous' freshest older index the newly reads older index
        lru_tracker_[fresh_idx].older_idx = lru_tracker_[lru_idx].older_idx;

        // The the newly reads older new index as the previous fresh index
        lru_tracker_[lru_tracker_[lru_idx].older_idx].newer_idx = fresh_idx;

        lru_tracker_[lru_idx].older_idx = fresh_idx;
        lru_tracker_[lru_idx].newer_idx = -1;

        fresh_idx = lru_idx;
        


        return value;
    }
    
    void put(int key, int value) {
        if (size_ < capacity_) {
            lru_tracker_[size_] = {key, fresh_idx, -1};
            lru_tracker_[size_-1].newer_idx = size_;
            data_map_[key] = {value, size_};
            ++size_;
            return;
        }
        // Delete stale data
        data_map_.erase(lru_tracker_[stale_idx].key);
        // Setting new stale index
        auto new_stale_idx = lru_tracker_[stale_idx].newer_idx;
        lru_tracker_[new_stale_idx].older_idx = -1;

        // overwritting stale lru entry with newer entry
        lru_tracker_[stale_idx] = {key, fresh_idx, -1};
        auto new_lru_index = stale_idx;
        stale_idx = new_stale_idx;

        // Set new fresh index
        lru_tracker_[fresh_idx].newer_idx = new_lru_index;
        fresh_idx = new_lru_index;

        data_map_[key] = {value, new_lru_index};

    }


private:

    // <key, <index in lru, value>>
    unordered_map<int, MapNode> data_map_{};

    // <key, index of next newest in lru>
    vector<TrackerNode> lru_tracker_{};

    int size_ = 0;
    int capacity_ = 0;

    // Fresh: latest value (ie latest added/read)
    int fresh_idx = 0;

    // Stale: value that has gone the longest since it was read/added
    int stale_idx = 0;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
