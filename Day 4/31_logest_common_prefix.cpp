/*
Link: https://leetcode.com/problems/longest-common-prefix/description/
Method: Sort and compare first and last
Time Complexity: O(nlogn)
Space Complexity: O(l) , l is the common prefix size for storing ans
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
        string ans = "";
        sort(strs.begin(), strs.end());
        string s1 = strs[0], s2 = strs[strs.size()-1];

        for(int i = 0; i<min(s1.size(), s2.size()); i++) {
            if(s1[i] != s2[i]) {
                return ans;
            }
            ans+=s1[i];
        }
        return ans;
        
    }
};

