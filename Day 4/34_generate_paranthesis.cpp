/*
Link: https://leetcode.com/problems/generate-parentheses/
Method: dfs and backtracking
Time Complexity: O(2^n)
Space Complexity: O(n)
*/

class Solution {
public:

    void dfs(int n, int leftCount, int rightCount, vector<char>& output, vector<string>& res) {
        // base case - count of left and right = n
        if(leftCount >= n && rightCount>=n) {
            string ansStr(output.begin(), output.end());
            res.push_back(ansStr);
        }

        if(leftCount < n) {
            output.push_back('(');
            dfs(n, leftCount+1, rightCount, output, res);

            // backtrack
            output.pop_back();
        }

        if(rightCount < leftCount) {
            output.push_back(')');
            dfs(n, leftCount, rightCount+1, output, res);

            // backtrack
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<char> output;

        dfs(n, 0, 0, output, result);
        return result; 
    }
};