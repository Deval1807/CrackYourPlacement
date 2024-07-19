/*
Link: https://www.geeksforgeeks.org/problems/word-wrap1646/1
Method: DP
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        int i, j;
        int currlen;
        int cost;
        
        //Initializing dp and ans vectors.
        vector<int>dp(n, 0);
        vector<int>ans(n, 0);
        dp[n - 1] = 0;
        ans[n - 1] = n - 1;
        
        //Calculating dp values from right to left.
        for (i = n - 2; i >= 0; i--)
        {
            currlen = -1;
            dp[i] = INT_MAX;
            
            //Calculating cost for current line wrappings.
            for (j = i; j < n; j++)
            {
                currlen += (nums[j] + 1);
                
                //If current line length exceeds the limit, break.
                if (currlen > k)
                    break;
                
                //Calculating cost for current wrapping.
                if (j == n - 1)
                    cost = 0;
                else
                    cost = (k - currlen) * (k - currlen) + dp[j + 1];
                
                //Updating dp and ans vectors.
                if (cost < dp[i]) {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }
        int res = 0;
        i = 0;
        
        //Calculating final result by summing up the costs.
        while (i < n) {
            int pos = 0;
            
            //Calculating positions for current line wrappings.
            for (int j = i; j < ans[i] + 1; j++) {
                pos += nums[j];
            }
            
            //Calculating cost of extra spaces.
            int x = ans[i]-i;
            if(ans[i]+1 != nums.size())
                res += (k - x - pos)*(k - x - pos);
            
            //Updating i to next line wrapping.
            i = ans[i] + 1;
        }
        
        //Returning the final result.
        return res;
    } 
};