/*
Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
Method: Sort and binary search in between a specific range
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

// the minimum ans will be when m==n so the ans will be arr[n-1]
// the max ans will be when only 1 student and he will get all book
// so the ans will be sum of all

// use binary search in this range and try optimising


class Solution {
  public:
    // function to check if the current minimum is feasible or not
    bool checkPossibility(int arr[], int n, int m, long long int curMin) {
        int studentsRequired = 1;
        long long curSum = 0;
        
        // traverse
        for(int i = 0; i<n; i++) {
            // if current no of pages are greater than curMin - false
            if(arr[i] > curMin) return false;
            
            // counting no of student req to distribute curMin pages
            if(curSum + arr[i] > curMin) {
                studentsRequired++;
                curSum = arr[i];
                
                // if required students get greater than n - false
                if(studentsRequired > m) return false;
            }
            else {
                curSum+=arr[i];
            }
        }
        return true;
    }
  
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n) return -1;
        
        sort(arr, arr+m);
        
        if(m==n) {
            return arr[n-1];
        }
        
        long long sum = 0;
        
        for(int i=0; i<n; i++) {
            sum+=arr[i];
        }
        
        long long low = arr[n-1], high = sum;
        long mid, ans = INT_MAX;
        
        while(low<=high) {
            mid = (low+high)/2;
            
            // check if it possible to distribute books by using mid as cureent minimum
            if(checkPossibility(arr, n, m, mid)) {
                ans = min(ans, mid);
                
                // keep optimizing
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        
        return ans;
        
    }
};