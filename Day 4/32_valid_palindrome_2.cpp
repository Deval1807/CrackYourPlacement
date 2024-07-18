/*
Link: https://leetcode.com/problems/valid-palindrome-ii/description/
Method: check with 2 pointers and if not match, try again by jumping 1 char
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    bool check1CharJump (string s, int i, int j) {
        while(i<=j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0; 
        int j = s.size()-1;

        while(i<=j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }else {
                return check1CharJump(s, i+1, j) || check1CharJump(s, i, j-1);
            }
        }

        return true;
    }
};

