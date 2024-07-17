/*
Link: https://leetcode.com/problems/reverse-pairs/description/
Method: Merge Sort - if we have 2 sorted arrays (which we get while doing merge sort), 
        then if kth element of arr1 if greater than 2 times of lth element of arr2,
        then we can say that all the elements after kth element will be 2 times greater than lth element
        since both arrays are sorted
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int findPairs(vector<int> &arr, int low, int mid, int high) {
        long long right = mid+1;
        long long count = 0;

        for(int i = low; i<=mid; i++) {
            while(right<=high && arr[i] > 2*(long long)arr[right]) right++;
            count += (right - (mid+1));
        }

        return count;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += findPairs(arr, low, mid, high);
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};