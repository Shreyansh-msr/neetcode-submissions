class Solution {
    private:
    int sum = 0;
    int target = 0;

    public:
    vector<vector<int>> combinationSum(const vector<int> &nums, int target) {
        this->sum = 0;
        this->target = target;
        vector<vector<int>> res;
        vector<int> subarr;
        job(nums, 0, subarr, res);
        return res;
    }

    private:
    void job(const vector<int> &nums, int index, vector<int> &subarr, vector<vector<int>>&res) {

        if(index >= nums.size() || sum > target) return;

        if(sum == target) {
            res.push_back(subarr); // creates a deepcopy and push it at back of the result
            return;
        }

        int curr= nums[index];

        sum = sum + curr;
        subarr.push_back(curr);
        job(nums, index, subarr, res);

        // undo the job -> backtracking
        sum = sum -curr;
        subarr.pop_back();
        job(nums, index+1, subarr, res);
    }
};
