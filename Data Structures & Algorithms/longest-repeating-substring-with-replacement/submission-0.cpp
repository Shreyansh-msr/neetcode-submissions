class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l=0, res=0;
        vector<int> count(26, 0); //frequency of characters in the current window
        for(int r=0; r<n; r++){
            count[s[r]-'A']++; //update the frequency of current char
            int maxF = *max_element(count.begin(), count.end());
            while( r - l + 1 - maxF > k)
            {
                count[s[l]-'A']--;
                l++;
                maxF = *max_element(count.begin(), count.end());
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
