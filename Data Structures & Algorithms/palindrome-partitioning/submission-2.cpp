class Solution {

private:
    // optimise isPalindrome using dynamic programming
    vector<vector<int>> palin_memo;
    bool isPalindrome(string &s, int start, int end) {

        if(palin_memo[start][end] == 0) return false;
        if(palin_memo[start][end] == 1) return true;
        int left = start, right = end;
        while(start < end) {
            if(s[start] != s[end]) return palin_memo[left][right]=0;
            start++;
            end --;
        }
        return palin_memo[left][right]=1;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> combination;
        palin_memo.assign(s.size(), vector<int>(s.size(), -1));
        backtrack(s, result, combination, 0, 0);
        return result;
    }
    void backtrack(string&s, vector<vector<string>>&result, vector<string>&combination,  int start, int end) {

        if(start== s.size()) {
            result.push_back(combination);
            return;
        }
        if(end == s.size()) return;
        
        // if the current substring is a palindrome we can either push it or continue building
        if(isPalindrome(s, start, end)) {
            // case 1 : push the current substring into the combination
            combination.push_back(s.substr(start, end - start + 1));
            backtrack(s, result, combination, end+1, end + 1);
            combination.pop_back();
        }

        //case 2: 
        backtrack(s, result, combination, start, end + 1);
    }

};
