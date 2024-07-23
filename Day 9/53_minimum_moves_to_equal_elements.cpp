/*
Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
Method: find the median and take the difference
Time Complexity: O(nlogn)
Space Complexity: o(1)
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums[nums.size()/2];

        int ans = 0;

        for(auto num: nums) ans+= abs(mid-num);

        return ans;
    }
};