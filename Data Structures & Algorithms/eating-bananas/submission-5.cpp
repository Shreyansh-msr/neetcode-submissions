class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
sort(piles.begin(), piles.end());
        int k = 1;
        while(true){
            long long nh = 0;
            for(int i=0; i<piles.size(); i++) nh += (piles[i]+k-1)/k; //trick for ceil division
            if(nh<=h) return k;
            k++;
        }
    }
};
