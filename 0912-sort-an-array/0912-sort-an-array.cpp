#include <vector>

class Solution {
private:
    void merge(std::vector<int>& nums, int left, int mid, int right, std::vector<int>& temp) {
        int i = left;
        int j = mid + 1;
        int k = left;

        // Merge the two halves into the temporary vector
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Copy any remaining elements from the left half
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        // Copy any remaining elements from the right half
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // Copy the sorted elements back into the original array
        for (int p = left; p <= right; ++p) {
            nums[p] = temp[p];
        }
    }

    void mergeSort(std::vector<int>& nums, int left, int right, std::vector<int>& temp) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        
        // Recursively sort left and right halves
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);
        
        // Merge the sorted halves
        merge(nums, left, mid, right, temp);
    }

public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        std::vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};