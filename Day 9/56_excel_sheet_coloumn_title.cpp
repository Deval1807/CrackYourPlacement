/*
Link: https://leetcode.com/problems/excel-sheet-column-title/
Method: take mod26 and then divide by 26
Time Complexity: O(logn)
Space Complexity: o(1)
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";
        int x = columnNumber;
        while(x){
            x--;
            int y = x%26;
            ans+=s[y];
            x/=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};