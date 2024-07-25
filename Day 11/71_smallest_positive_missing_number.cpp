/*
Link: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
Method: in question
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Intuition:
The idea is to use array elements as an index. To mark the presence of an element x, change the value at the index x to negative. But this approach doesn’t work if there are non-positive (-ve and 0) numbers. So segregate positive from negative numbers as the first step and then apply the approach.

Example:
Input array: [2,-1,-3,4,4,7]

Array after segregation: [2,4,4,7]. We ignore the negative integers.
To mark the presence of integer 2 we do arr[2-1]=-arr[2-1]. We do this only if arr[in] is positive initially. 
For 4 we do arr[4-1]=-arr[4-1].
Array after all operations = [2, -4, 4, -7]
So, the value at index 0 is positive. So 1 is the minimum positive number not present in the array. 
*/

class Solution
{
    public:
    //Function that puts all non-positive (0 and negative) numbers on left 
    //side of arr[] and return count of such numbers.
    int segregateArr (int arr[], int n) 
    { 
    	int j = 0, i; 
    	for(i = 0; i < n; i++) 
    	{ 
    	    if(arr[i] <= 0) 
    	    { 
    	        //changing the position of negative numbers and 0.
    	        swap(arr[i], arr[j]); 
    	        //incrementing count of non-positive integers.
    	        j++; 
    		} 
    	}
    	return j; 
    } 
    
    //Finding the smallest positive missing number in an array 
    //that contains only positive integers.
    int findMissingPositive(int arr[], int n)
    {
        
        //marking arr[i] as visited by making arr[arr[i]-1] negative. 
        //note that 1 is subtracted because indexing starts from 0 and 
        //positive numbers start from 1.
        for(int i=0; i<n; i++) 
        {
    	    if(abs(arr[i]) - 1 < n && arr[ abs(arr[i]) - 1] > 0) 
    	    arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1]; 
        } 
        
        for(int i=0; i<n; i++)
        {
            if (arr[i] > 0)
            {
                //returning the first index where value is positive. 
                // 1 is added because indexing starts from 0. 
    	        return i+1; 
            }
        }
        return n+1; 
    } 
    
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        //first separating positive and negative numbers. 
        int shift = segregateArr(arr, n); 
        
        //shifting the array to access only positive part.
        //calling function to find result and returning it.
        return findMissingPositive(arr+shift, n-shift); 
    } 
};
