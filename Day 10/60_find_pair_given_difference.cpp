/*
Link: https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1
Method: set for storing
Time Complexity: O(n)
Space Complexity: o(n)
*/

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        unordered_set<int> st;
        
        for (int i = 0; i < n; ++i) {
            if (st.find(arr[i] + x) != st.end() ||
                st.find(arr[i] - x) != st.end()) {
                return 1;
            }
            st.insert(arr[i]);
        }
        return -1;
    }
};