class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         unordered_map<char, int> m1;
        for(int i=0; i<s1.size(); i++) m1[s1[i]]++;

        for(int i=0; i<s2.size() - s1.size() + 1; i++)
        {
            unordered_map<char, int> m2;
            for(int j=0; j<s1.size(); j++) m2[s2[i+j]]++;

            if(m1==m2) return true;
        }
        return false;
    }
};
