/*
Link: https://leetcode.com/problems/4sum/
Method: iterete over i and j and for each pair {i,j} use 2 pointers to get total 4 numbers
Time Complexity: O(n^3)
Space Complexity: o(1) extra
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        int i,j,k,l;
        int n = nums.size();
        long long sum;

        sort(nums.begin(), nums.end());

        for(i = 0; i<n; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(j=i+1; j<n; j++) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                k = j+1;
                l = n-1;

                while(k < l) {
                    sum = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];

                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k],nums[l]};
                        ans.push_back(temp);

                        k++;
                        l--;

                        // check for duplicates
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--; 
                    }
                }
            }
        }

        return ans;
    }
};