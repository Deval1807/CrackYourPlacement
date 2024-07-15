/*
Link: https://leetcode.com/problems/container-with-most-water/
Method: 2 pointers
Time Complexity: O(n)
Space Complexity: o(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxArea = 0;

        while(left<=right) {
            int currArea = ((right-left) * min(height[left], height[right]));
            maxArea = max(maxArea, currArea);
            
            if(height[left] < height[right]) {
                left++;
            }else {
                right--;
            }
        }

        return maxArea;
    }
};