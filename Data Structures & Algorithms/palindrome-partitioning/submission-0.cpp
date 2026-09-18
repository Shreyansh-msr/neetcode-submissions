class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end --;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> combination;
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
