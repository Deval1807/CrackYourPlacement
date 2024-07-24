/*
Link: https://www.geeksforgeeks.org/problems/permutations-in-array1747/1
Method: sort 1 array in ascending and other in descending and compare
Time Complexity: O(nlogn)
Space Complexity: o(1)
*/

class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Your code goes here
        sort(a, a+n);
        sort(b, b+n, greater<int>());
        
        for(int i = 0; i<n; i++) {
            if(a[i]+b[i] < k) return false; 
        }
        
        return true;
    }
};