/*
Link: https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
Method: Sort and check for windows of m size
Time Complexity: O(nlogn)
Space Complexity: o(1)
*/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(), a.end());
        
        long long minDiff = INT_MAX;
        int ind = 0;
        
        for(int i = m-1; i<n; i++) {
            minDiff = min(minDiff, a[i]-a[ind]);
            ind++;
        }
        return minDiff;
    
    }   
};