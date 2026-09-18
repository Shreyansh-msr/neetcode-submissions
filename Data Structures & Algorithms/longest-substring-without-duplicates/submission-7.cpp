class Solution {
public:
    int lengthOfLongestSubstring(string s) {
int slow=0;
    int fast=0;
    int n = s.size();
    int maxLen = 0;
    unordered_set<char> st = {};

    while(fast<n){
        if(st.find(s[fast]) == st.end()){
            st.insert(s[fast]);
        }
        else{
            while(s[slow] != s[fast]){ //find the duplicate character and remove all characters before it
                st.erase(s[slow]);
                slow++;
            }
            st.erase(s[slow]);
            slow++;
            st.insert(s[fast]);
        }
        maxLen = max(maxLen, fast-slow+1);
        fast++;
    }
    return maxLen;
    }
};
