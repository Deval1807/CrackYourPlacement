/*
Link: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
Method: multiply all the towards the left in 1 pass and all towards the right in 2nd pass
Time Complexity: O(n)
Space Complexity: o(n) for storing ans
*/

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        // Allocate memory for product array andinitialise it by 1
        vector<long long int> vec(n, 1ll);
        if (n == 1) 
        {
            return vec;
        }
        
        // In this loop temp will store the product of values on the left side of nums[i]
        long long temp = 1ll;
        for(int i = 0;i < n;i++) 
        {
            vec[i] *= temp;
            temp *= nums[i];
        }
        
        // In this loop temp will store the product of values on the right side of nums[i]
        temp = 1ll;
        for(int i = n - 1;i >= 0;i--)
        {
            vec[i] *= temp;
            temp *= nums[i];
        }
        
        
        return vec;
    }