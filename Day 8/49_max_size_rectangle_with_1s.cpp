/*
Link: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
Method: DP - use dynamic programming to get the maximum height of the rectangle that ends at the cell.
Time Complexity: O(m*n)
Space Complexity: O(n)
*/

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> left(n, 0);     // for left boundary
    vector<int> right(n, n);    // for right boundary
    vector<int> height(n, 0);
    int maxArea = 0;

    for (const auto& row : matrix) {
        int curLeft = 0, curRight = n;

        // Update height array
        for (int j = 0; j < n; j++) {
            if (row[j] == '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        // Update left boundary array
        for (int j = 0; j < n; j++) {
            if (row[j] == '1') {
                left[j] = max(left[j], curLeft);
            } else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        // Update right boundary array
        for (int j = n - 1; j >= 0; j--) {
            if (row[j] == '1') {
                right[j] = min(right[j], curRight);
            } else {
                right[j] = n;
                curRight = j;
            }
        }

        // Calculate maximum area for each cell
        for (int j = 0; j < n; j++) {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }

    return maxArea;
}
