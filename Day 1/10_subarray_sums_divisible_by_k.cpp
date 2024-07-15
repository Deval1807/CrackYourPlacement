/*
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
Method: Prefix sum
Time Complexity: O(n)
Space Complexity: o(n)
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Find the subarray sum using range sum -> use prefix sum
        // _________a________b____ where range is from a to b
        // range sum, r = Pb-Pa where Pi is the prefix sum (sum till i)
        // we want r%k == 0
        // thereofre (Pb-Pa)%k = 0
        // therefore Pb%k == Pa%k

        // Edge Case!! - Negative nos 
        // (-2)%6 = -2
        // OR (-2 + 6) % 6 = 4
        // we handle negative numbers by adding k and than mod

        int prefixSum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0]++;

        for(int i = 0; i<nums.size(); i++) {
            prefixSum = (prefixSum + nums[i]%k + k)%k;
            ans += mp[prefixSum];
            mp[prefixSum]++;
        }

        return ans;
    }
};
