/*
Link: https://leetcode.com/problems/maximum-product-of-three-numbers/
Method: sort and check the last 3 and the last with first 2 (for negative no)
Time Complexity: O(nlogn)
Space Complexity: o(1)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int ans1 = nums[n-1]*nums[n-2]*nums[n-3];

        // if the product of 2 big negative nos is large example
        // -8 -7 -1 1 2 2
        int ans2 = nums[0]*nums[1]*nums[n-1];
        
        if(ans1>ans2){
            return ans1;
        }
        else{
            return ans2;
        }
    }
};