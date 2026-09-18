class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int slow = 0;
        int fast = 1;
        int maxProfit = 0;

        while(fast < prices.size()){
            if(prices[fast] > prices[slow]){
                maxProfit = max(maxProfit, prices[fast] - prices[slow]);
                fast ++;
            }
            else{
                slow = fast;
                fast++;
            }
        }
        return maxProfit;
    }
};
