/*
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Method: Keep an index for unique elements and update the array while traversing
Time Complexity: O(n)
Space Complexity: o(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]) continue;
            else {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};