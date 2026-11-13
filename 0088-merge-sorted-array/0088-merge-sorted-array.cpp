#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;     // Pointer for the last valid element in nums1
        int j = n - 1;     // Pointer for the last element in nums2
        int k = m + n - 1; // Pointer for the very end of nums1 (the combined space)
        
        // Merge from the back to avoid overwriting existing elements in nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If there are remaining elements in nums2, copy them over
        // (Any remaining elements in nums1 are already in their correct sorted positions)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};