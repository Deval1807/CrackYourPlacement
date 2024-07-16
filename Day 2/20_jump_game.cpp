/*
Link: https://leetcode.com/problems/jump-game/description/
Method: Greedy - keep a track of max index we can reach
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for(int i = 0; i<nums.size(); i++) {

            // we keep the condition of (i<=maxIncex)
            // as for that index some previous number should have reached before
            if(i<=maxIndex) maxIndex = max(maxIndex, i+nums[i]);
            if(maxIndex >= nums.size()-1) return true;
        }
        return false;
    }
};

