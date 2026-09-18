class Solution {
private:
    int size = 0;
    int sum = 0;
    int target = 0;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->sum = 0; // Explicitly reset for multiple runs
        this->target = target;
        this->size = candidates.size();
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> combination;
        dfs(candidates, 0, combination, result);
        return result;
    }
private:
    void dfs(const vector<int> &nums, int index, vector<int>& combination, vector<vector<int>>& result) {
        // 1. Always check for success FIRST
        if(sum == target) {
            result.push_back(combination);
            return;
        }

        // 2. Then check for out-of-bounds or failure
        if(index >= size || sum > target) {
            return;
        }

        int curr = nums[index];
        
        // Take the current element
        sum += curr;
        combination.push_back(curr);
        dfs(nums, index + 1, combination, result);
        
        // Leave the current element (undo steps)
        sum -= curr;
        //preventing the duplicates
        combination.pop_back();
        while(index + 1 < size && nums[index] == nums[index + 1]) {
            index += 1;
        }
        dfs(nums, index + 1, combination, result); //next (different)
    }
};
