class Solution {
private:
    unordered_map<char, string> keypad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    void backtrack(int index, const string &digits, string &combination, vector<string> &result) {
        if (index == digits.size()) {
        result.push_back(combination);
        return;
    }

    string letters = keypad[digits[index]];

    combination.push_back(letters[0]);
    backtrack(index + 1, digits, combination, result);

    combination.pop_back();
    combination.push_back(letters[1]);
    backtrack(index + 1, digits, combination, result);

    combination.pop_back();
    combination.push_back(letters[2]);
    backtrack(index + 1, digits, combination, result);
    combination.pop_back();
    if (letters.size() == 4) {
        

        combination.push_back(letters[3]);
        backtrack(index + 1, digits, combination, result);
        combination.pop_back();
        
    }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        string combination = "";
        backtrack(0, digits, combination, result);
        return result;
    }
};