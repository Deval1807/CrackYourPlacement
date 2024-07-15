/*
Link: https://leetcode.com/problems/find-the-duplicate-number/description/
Method: take ith number and considering it index, make the indexth number negative. so the for duplicate no, it will already be negative
Time Complexity: O(n)
Space Complexity: o(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++) {
            int index = abs(nums[i]);
            if(nums[index] < 0) {
                return index;
            }
            nums[index] = -nums[index];
        }
        return -1;
    }
};