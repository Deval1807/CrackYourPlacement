/*
Link: https://leetcode.com/problems/add-binary/description/
Method: use carry and traverse and add with 2 pointers on 2 numbers
Time Complexity: O(n)
Space Complexity: o(1)
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int carry = 0;
        int i = a.size()-1, j = b.size()-1;

        while(i >= 0 || j >= 0 || carry) {
            if(i >= 0) {
                carry += a[i]-'0';
                i--;
            }
            if(j >= 0) {
                carry += b[j]-'0';
                j--;
            }
            // add 1 if addition is 1 or 0 if 2 and 1 will go to carry 
            ans += (carry%2 + '0');
            carry /= 2;
        }

        // reverse the string to get the final ans
        reverse(ans.begin(), ans.end());
        return ans;
    }
};