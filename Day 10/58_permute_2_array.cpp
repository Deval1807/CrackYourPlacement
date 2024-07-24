/*
Link: https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/
Method: sort 1 array in ascending and sort other one in descending and than check
Time Complexity: O(nlogn)
Space Complexity: o(1)
*/

bool isPossible(int a[], int b[], int n, int k)
{
    // Sort the array a[] in decreasing order.
    sort(a, a + n);

    // Sort the array b[] in increasing order.
    sort(b, b + n, greater<int>());

    // Checking condition on each index.
    for (int i = 0; i < n; i++)
        if (a[i] + b[i] < k)
            return false;

    return true;
}
