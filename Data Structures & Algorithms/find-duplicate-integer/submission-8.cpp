class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow = 0;
        int fast = 0;

        // step 1: get inside the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // step 2: find the entrance point of the cycle

        slow = 0;
        // fast is unchanged

        do {
            slow = nums[slow];
            fast = nums[fast];
        } while(slow != fast);

        return slow;
    }
};
