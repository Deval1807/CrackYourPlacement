/*
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
Method: If selling on ith day - keep track of min cost till (i-1)th day
Time Complexity: O(n)
Space Complexity: o(1)
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minCost = prices[0];

        for(int i = 1; i<n; i++) {
            minCost = min(minCost, prices[i-1]);

            maxProfit = max(maxProfit, prices[i]-minCost);
        }
        return maxProfit;
    }
};