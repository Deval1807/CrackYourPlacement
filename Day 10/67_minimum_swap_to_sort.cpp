/*
Link: https://www.geeksforgeeks.org/problems/minimum-swaps/1
Method: compare the original with sorted, use a map to store the indexes
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int ans = 0;
	    int n = nums.size();
	    
	    vector<int>sorted(nums.begin(), nums.end());
	    
	    sort(sorted.begin(), sorted.end());
	    
	    // map to store the index of original array
	    map<int, int> mp;
	    
	    for(int i = 0; i<n; i++) {
	        mp[nums[i]] = i;
	    }
	    
	    for(int i = 0; i<n; i++) {
	        // check wether the current element is at current position or not
	        if(nums[i] != sorted[i]) {
	            ans++;
	            
	            // since the current element is not at right position, swap it 
	            // with its position refering from sorted array
	            // update the map accordingly
	            int x = nums[i];
	            swap(nums[i], nums[mp[sorted[i]]]);
	            
	            mp[x]=mp[sorted[i]];
	            mp[sorted[i]]=i;
	        }
	    }
	    
	    return ans;
	}
};