/*
Link: https://leetcode.com/problems/rotate-image/description/
Method: Transpose the matrix and then reverse each row
Time Complexity: O(m*n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // traverse upper triangle and transpose the matrix
        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse all the rows
        for(int i = 0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};