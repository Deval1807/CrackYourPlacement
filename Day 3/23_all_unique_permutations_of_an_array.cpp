/*
Link: https://leetcode.com/problems/permutations/
      https://leetcode.com/problems/permutations-ii/
      https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/0
Method: Recursion
Time Complexity: O(n! * nlogn)
Space Complexity: O(n)
*/


class Solution {
public:

    // In Place!!

    void recSwap(int ind, set<vector<int>>& ans, vector<int>& nums) {

        // base case - when index reaches nums size
        if(ind == nums.size()) {
            // push back the current permutation
            ans.insert(nums);
            return;
        }

        // for each index, all the elements can be at that index
        for(int i = ind; i<nums.size(); i++) {
            swap(nums[ind], nums[i]);
            recSwap(ind+1, ans, nums);

            // simple backtrack
            // while going back, again put the original value
            swap(nums[ind], nums[i]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // set will store in sorted order as well as take care of duplicates!!
        set<vector<int>> ans;
        recSwap(0, ans, nums);
        vector<vector<int>> vectorAns(ans.begin(), ans.end());
        return vectorAns;
    }
};