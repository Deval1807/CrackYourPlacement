/*
Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
Method: since elements are from 1 to n - take the element as index and make the nums[index] negative, for duplicate it will already be negative
Time Complexity: O(n)
Space Complexity: o(n) to store ans O(1) extra to compute
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++) {
            int index = abs(nums[i])-1;
            if(nums[index] < 0) ans.push_back(index+1);
            nums[index] = -nums[index];
        }
        return ans;
    }
};