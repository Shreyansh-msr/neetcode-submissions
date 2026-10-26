class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(sum + nums[i] > 0) {
                sum += nums[i];
                max_sum = max(max_sum, sum);
            }
            else {
                max_sum = max(max_sum, nums[i]);
                sum = 0; // reset for the next subarray
            }
        }
        return max_sum;
    }
};
