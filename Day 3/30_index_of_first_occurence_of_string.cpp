/*
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
Method: Sliding window (substring)
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // STL
        // return haystack.find(needle);

        // sliding window of needle size
        if(needle.size() > haystack.size()) return -1;
        
        for(int i = 0; i<=haystack.size()-needle.size(); i++) {
            if(haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }

        return -1;
    }
};