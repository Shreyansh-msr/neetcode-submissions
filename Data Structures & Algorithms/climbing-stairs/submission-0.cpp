class Solution {
public:
    int climbStairs(int n) {
        memo.clear();
        return backTrack(n);
    }
private:
    unordered_map<int, int> memo;
    int backTrack(int n) {
        if(memo.find(n) != memo.end()) return memo[n];
        if(n<0) return 0;
        if(n==0) return 1;
        return memo[n] = backTrack(n-1)+backTrack(n-2);;
    }
};
