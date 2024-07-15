/*
Link: https://leetcode.com/problems/move-zeroes/
Method: keep a pointer for non-zero elements and swap while traversing
Time Complexity: O(n)
Space Complexity: o(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i]==0) continue;
            else {
                swap(nums[k], nums[i]);
                k++;
            }
        }

    }
};