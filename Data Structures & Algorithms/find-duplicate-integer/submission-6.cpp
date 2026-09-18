class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1; // since array consist of numbers in range [1,n], where n+1 is the size of the array

        while(low<high){
            int mid = low + (high-low)/2; //this specific technique to reduce chance of overflow

            int count=0;
            for(int num : nums){
                if(num<=mid) {
                    count += 1;
                }
            }
            if(count > mid){
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
