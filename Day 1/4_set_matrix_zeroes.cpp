/*
Link: https://leetcode.com/problems/set-matrix-zeroes/
Method: use the 1st row and col of the matrix itself to keep track of zeroes with 1 extra variable for overalapping [0][0]
Time Complexity: O(n*m)
Space Complexity: o(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // keep track of zeroes in row in col[0]
        // keep track of zeroes in col in row[0]
        // both overlap and [0][0] - extra 1 variable

        int col0 = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        // marking
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    // mark ith row
                    matrix[i][0] = 0;
                    
                    // mark jth col
                    if(j!=0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        // update matrix (except for 0th row and 0th col)
        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // update the 0th row
        if(matrix[0][0] == 0) {
            for(int j = 0; j<m; j++) {
                matrix[0][j] = 0;
            }
        }

        // update the oth col
        if(col0 == 0) {
            for(int i = 0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};