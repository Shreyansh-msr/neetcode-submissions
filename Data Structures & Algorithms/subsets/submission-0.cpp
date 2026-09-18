class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() ==0 ) return {{}};

        int curr = nums[0];
        // remove the first element
        swap(nums[0], nums.back());
        nums.pop_back();

        vector<vector<int>> arr = subsets(nums);
        int s = arr.size();

        for(int i =0; i<s; i++)
        {
            vector<int> s = arr[i];
            s.push_back(curr);
            arr.push_back(s);
        }

        return arr;
    }
};
