/*
Link: https://leetcode.com/problems/max-value-of-equation/description/
Method: Priority Queue
Time Complexity: O(n)
Space Complexity: O(n) extra
*/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // (yi + yj) + |xi - xj|
        // since it is sorted based on x and j>i
        // |xi - xj| = -xi + xj
        // therefore we get (yi - xi) + (yj + xj)
        // constratint -> xj - xi <= k

        // so now if we are at index j, then for all 1,2......(j-1) we need to find
        // the max value of (yi-xi) since for a point j, (yj + xj) will remain constant
        // we also need to check the constraint

        // for largest value - use priority quey (max heap)

        // PQ for storing (yi-xi) and xi 
        priority_queue<pair<int, int>> pq;

        int ans = INT_MIN;

        for(int i = 0; i<points.size(); i++) {

            // remove those pairs where xj-xi > k
            while(!pq.empty() && (points[i][0] - pq.top().second)>k) {
                pq.pop();
            }

            // update the ans
            if(!pq.empty()) {
                int currAns = points[i][0]+points[i][1]+pq.top().first;
                ans = max(ans, currAns);
            }

            // insert the difference
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};