class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> powerSet;
        vector<int> subset = {}; //start with empty subset
        sort(nums.begin(), nums.end());
        backTrack(nums, 0, subset, powerSet);
        
        vector<vector<int>> res;
        res.reserve(powerSet.size());

        // Convert each inner set to a vector and add to the outer vector
        for (const auto& subset : powerSet) {
            res.push_back(vector<int>(subset.begin(), subset.end()));
        }
        return res;
    }

    void backTrack(const vector<int>&nums, int index ,vector<int>&subset, set<vector<int>>&powerSet) {
        powerSet.insert(subset);
        if(index == nums.size()) return;
        
        subset.push_back(nums[index]);
        backTrack(nums, index + 1, subset, powerSet);
        subset.pop_back();
        backTrack(nums, index + 1, subset, powerSet);
    }
};
