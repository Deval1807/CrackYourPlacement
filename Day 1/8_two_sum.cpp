/*
Link: https://leetcode.com/problems/two-sum/description/
Method: Hashmap and checking
Time Complexity: O(n)
Space Complexity: o(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Brute force
        vector<int>v;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
        */

        // Hashing - O(n) but space O(n) - best for our que

        // Sort and 2 pointers - O(nlogn + n) space O(1) - better for
        // yes no type (is their a pair which exist such that) sum = target

        unordered_map<int, int>mp;
        int ind1, ind2;
        for(int i = 0; i<nums.size(); i++) {
            int n1 = nums[i];
            int req = target - n1;

            if(mp.find(req) != mp.end()){
                ind1 = i;
                ind2 = mp[req];
            }
            
            mp[nums[i]] = i;
        }
        return {ind1, ind2};
    }
};