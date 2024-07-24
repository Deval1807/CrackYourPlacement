/*
Link: https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/
Method: compare the original array with its sorted one and then check the subarray is decreasing or not
Time Complexity: O(nlogn)
Space Complexity: o(n)
*/

// Return true, if reversing the subarray will 
// sort the array, else return false. 
bool checkReverse(int arr[], int n) 
{ 
    // Copying the array. 
    int temp[n]; 
    for (int i = 0; i < n; i++) 
        temp[i] = arr[i]; 
  
    // Sort the copied array. 
    sort(temp, temp + n); 
  
    // Finding the first mismatch. 
    int front; 
    for (front = 0; front < n; front++) 
        if (temp[front] != arr[front]) 
            break; 
  
    // Finding the last mismatch. 
    int back; 
    for (back = n - 1; back >= 0; back--) 
        if (temp[back] != arr[back]) 
            break; 
  
    // If whole array is sorted 
    if (front >= back) 
        return true; 
  
    // Checking subarray is decreasing or not. 
    do
    { 
        front++; 
        if (arr[front - 1] < arr[front]) 
            return false; 
    } while (front != back); 
  
    return true; 
} 