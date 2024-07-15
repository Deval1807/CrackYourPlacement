/*
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
Method: Greedy! (Optimised) - if the profit is positive of i+1th day and ith day, take the trade
Method2: DP
Time Complexity: O(n)
Space Complexity: o(1)
*/


class Solution {
public:

    // int prof(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp){
    //     if(ind==n) return 0;
        
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];

    //     int profit = 0;

    //     if(buy){
    //         profit += max((-prices[ind] + prof(ind+1, 0, prices, n, dp)), 
    //                     (0 + prof(ind+1, 1, prices, n, dp)));
    //     }else{
    //         profit += max((prices[ind] + prof(ind+1, 1, prices,n, dp)),
    //                     (0 + prof(ind+1, 0, prices, n, dp)));
    //     }
    //     return dp[ind][buy] = profit;
    // }

    int maxProfit(vector<int>& prices) {
        // greedy!!!
        int sum = 0;
        for (int i = 0; i<prices.size()-1; i++){
            if(prices[i]<prices[i+1]){
                sum+=prices[i+1]-prices[i];
            }
        }
        return sum;

        // DP
        // vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
        // return prof(0,1,prices,prices.size(), dp);
    }
};