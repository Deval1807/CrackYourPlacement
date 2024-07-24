/*
Link: https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
Method: binary search
Time Complexity: O(logn)
Space Complexity: o(1)
*/

int ceilSearch(int arr[], int low, int high, int x)
{
 
    // base condition if length of arr == 0 then return -1
    if (sizeof(arr) / sizeof(arr[0]) == 0) {
        return -1;
    }
    int mid;
 
    // this while loop function will run until condition not
    // break once condition break loop will return start and
    // ans is low which will be next smallest greater than
    // target which is ceiling
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}