class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using quick select
        return quickSelect(nums, 0, nums.size() -1, k-1);
    }

    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[high]; // value at the last index
        int wall = low;

        for(int i = low; i < high; i++) {
            if(nums[i] > pivot) {
                swap(nums[i], nums[wall]);
                wall++;
            }
        }

        swap(nums[wall], nums[high]);
        return wall; // final position of pivot
    }

    int quickSelect(vector<int> & nums, int low, int high, int targetIndex) {
        if(low > high) return -1;

        int pivot = partition(nums, low, high);

        if( pivot == targetIndex) return nums[pivot];
        else if(pivot > targetIndex) return quickSelect(nums, low, pivot - 1, targetIndex);
        else return quickSelect(nums, pivot+1, high,  targetIndex);
    }
    

};
