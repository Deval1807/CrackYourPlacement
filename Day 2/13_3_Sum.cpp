/*
Link: https://leetcode.com/problems/3sum/
Method: iterete over i and for each i use 2 pointers to get total 3 numbers
Time Complexity: O(n^2)
Space Complexity: o(1) extra
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;

        int n = arr.size();
        int j, k;
        int sum = 0;

        sort(arr.begin(), arr.end());

        for(int i = 0; i<n; i++) {

            if(i>0 && arr[i] == arr[i-1]) continue;

            j = i+1;
            k = n-1;

            while(j < k) {
                sum = arr[i] + arr[j] + arr[k];

                if(sum<0) j++;
                else if(sum > 0) k--;
                else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    // check for duplicates
                    while(j<k && arr[j] == arr[j-1]) j++;
                    while(j<k && arr[k]==arr[k+1])k--;
                }
            }
        }

        return ans;
    }
};