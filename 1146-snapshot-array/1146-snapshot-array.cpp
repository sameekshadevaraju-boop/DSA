#include <vector>
#include <algorithm>
#include <climits>

class SnapshotArray {
private:
    int snap_id;
    // For each index, store a list of pairs: {snapshot_id, value}
    std::vector<std::vector<std::pair<int, int>>> history;

public:
    SnapshotArray(int length) {
        snap_id = 0;
        history.resize(length);
        // Initialize each index with value 0 at snapshot 0
        for (int i = 0; i < length; ++i) {
            history[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        // If an entry for the current snap_id already exists, update it
        if (history[index].back().first == snap_id) {
            history[index].back().second = val;
        } else {
            // Otherwise, append a new state for the current snap_id
            history[index].push_back({snap_id, val});
        }
    }
    
    int snap() {
        // Increment snap_id and return the previous snapshot ID
        return snap_id++;
    }
    
    int get(int index, int target_snap_id) {
        // Use binary search (upper_bound) to find the latest value at or before target_snap_id
        auto it = std::upper_bound(
            history[index].begin(), 
            history[index].end(), 
            std::make_pair(target_snap_id, INT_MAX)
        );
        --it; // Step back to get the element with the largest snapshot ID <= target_snap_id
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */