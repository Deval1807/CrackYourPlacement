/*
Link: https://leetcode.com/problems/sort-colors/
Method: Dutch National Flag Algo (DNF)
Time Complexity: O(n)
Space Complexity: o(1)
*/

class Solution {
public:
    // DNF -> 
    // 0 - low-1    -> 0
    // low - mid-1  -> 1
    // mid - high   -> 0/1/2 , unsorted
    // high+1 - n-1 -> 2
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid<=high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};