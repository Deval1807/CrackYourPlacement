/*
Link: https://leetcode.com/problems/distinct-subsequences
Method: DP
Time Complexity: O(nm)
Space Complexity: O(nm) + O(n+m)
*/

class Solution {
    int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        
        if(j==0)return 1; // patern ended => found 1 way
        if(i==0)return 0; // text ended => no way

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i-1]==t[j-1]){
            // try both cases, take and not take
            return dp[i][j] = solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
        }

        return dp[i][j]=solve(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return solve(n,m,s,t,dp);
    }
};
