/*
Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
Method: 2 pointers
Time Complexity: O(n)
Space Complexity: o(1) extra
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0, n = cardPoints.size();
        
        // first assign the maximum sum to be the first k elements
        for(int i = 0; i<k; i++) {
            maxSum+=cardPoints[i];
        }

        int leftIndex = k-1;
        int currSum = maxSum;

        // check for all the possibility by removing 1 element from left and adding 1 from right
        for(int i = n-1; i>=n-k; i--) {
            currSum = currSum - cardPoints[leftIndex] + cardPoints[i];
            leftIndex--;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;

    }
};