/*
Link: https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/
Method: Sort and then if odd no - middle element, even - avg of middle 2
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

int minCostToMakeElementEqual(int a[], int n)
{
 
    sort(a, a+n);

    // If there are odd elements, we choose
    // middle element
    int y;
    if (n % 2 == 1)
        y = a[n / 2];
 
    // If there are even elements, then we choose
    // the average of middle two.
    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;
 
    // After deciding the final value, find the
    // result.
    int s = 0;
    for(int i = 0; i < n; i++)
        s += abs(a[i] - y);
         
    return s;
}