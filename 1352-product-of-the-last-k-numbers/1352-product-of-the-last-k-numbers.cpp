#include <vector>

class ProductOfNumbers {
private:
    // prefix_prod[i] stores the cumulative product of elements since the most recent 0
    std::vector<int> prefix_prod;

public:
    ProductOfNumbers() {
        // Reserve capacity for up to 40,000 calls to eliminate dynamic heap reallocations
        prefix_prod.reserve(40001);
        prefix_prod.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            // Any subarray spanning across a 0 has a product of 0; reset the prefix chain
            prefix_prod.clear();
            prefix_prod.push_back(1);
        } else {
            prefix_prod.push_back(prefix_prod.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = static_cast<int>(prefix_prod.size());
        
        // Since prefix_prod holds (count_since_zero + 1) elements, if k >= n,
        // at least one of the last k numbers was 0
        if (k >= n) {
            return 0;
        }
        
        return prefix_prod.back() / prefix_prod[n - 1 - k];
    }
};