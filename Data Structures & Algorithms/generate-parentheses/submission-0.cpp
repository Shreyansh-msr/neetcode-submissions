class Solution {
private:
    vector<string> result;
    string wff = "";
    int n;
    
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        // Start the recursion with 0 open and 0 close brackets
        backTrack(0, 0); 
        
        return result; // Don't forget to return the answer!
    }

    void backTrack(int open, int close) {
        // Base case: if we've used n open and n close brackets, we    have a valid string
        if (close == n && open == n) {
            result.push_back(wff);
            return;
        }

        // Branch 1: Add an open bracket (only if we haven't used all n yet)
        if (open < n) {
            wff.push_back('(');
            backTrack(open + 1, close); // Recurse
            wff.pop_back();             // Backtrack
        }

        // Branch 2: Add a close bracket (only if it matches an unmatched open bracket)
        if (close < open) {
            wff.push_back(')');
            backTrack(open, close + 1); // Recurse
            wff.pop_back();             // Backtrack
        }
    }
};