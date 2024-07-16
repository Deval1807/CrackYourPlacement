/*
Link: https://leetcode.com/problems/subarray-sum-equals-k/
Method: Prefix Sum
Time Complexity: O(n)
Space Complexity: o(n) extra
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Prefix sum technique
        // at a point if the Prefix Sum is S, and we want to know how many subarrays are there till
        // that point with sum k
        // we will find how many previously have sum S-k

        int prefixSum = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0]=1;

        for(int i = 0; i<nums.size(); i++) {
            prefixSum+=nums[i];
            if(mp.find(prefixSum-k) != mp.end()) {
                ans+=mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }

        return ans;
    }
};