/*
Link: https://leetcode.com/problems/majority-element/
Method: Moore's Voting Algo
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Voting Algo
        // this will return the majority element if exists
        // in the question it is given that there always exist
        // other wise, at last we would need to check

        int element, count = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(count == 0) {
                element = nums[i];
                count++;
            }else if(nums[i] == element) {
                count++;
            }else {
                count--;
            }
        }
        return element;
    }
};