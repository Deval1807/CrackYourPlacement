/*
Link: https://leetcode.com/problems/spiral-matrix/
Method: traverse for all elements. keep 4 pointer top right botton and left and traverse that row/col
Time Complexity: o(m*n)
Space Complexity: O(m*n) for storing
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int top = 0,  bottom = m-1;
        int left = 0, right = n-1;
        int count = 0;
        int total = m*n;

        vector<int> ans;

        // traverse for all the elements
        while(count < total) {
            // top row
            for(int i = left; i<=right; i++) {
                if(count >= total) break;
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;

            // right col
            for(int i = top; i<= bottom; i++) {
                if(count >= total) break;
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;

            // bottom row
            for(int i = right; i>=left; i--) {
                if(count >= total) break;
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;

            // left col
            for(int i = bottom; i>=top; i--) {
                if(count >= total) break;
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }
};