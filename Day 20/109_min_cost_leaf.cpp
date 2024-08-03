/*
Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
Method: Just find the next greater element in the array, on the left and one right.
Refer to the problem 503. Next Greater Element II
Time Complexity: O(n)
Space Complexity: O(n) 
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : arr) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};