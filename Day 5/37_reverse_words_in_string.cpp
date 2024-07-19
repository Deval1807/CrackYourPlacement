/*
Link: https://leetcode.com/problems/reverse-words-in-a-string/
Method: reverse the whole string and reverse back each word using 2 pointers
Time Complexity: O(n)
Space Complexity: O(1) in place
*/

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0, right = 0;
        int i = 0;

        while(i<n) {
            while(i<n && s[i] == ' ') i++;
            if(i == n) break;

            while(i<n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // again reverse the word
            reverse(s.begin()+left, s.begin()+right);

            // add space
            s[right++] = ' ';

            // update left index
            left = right;
            i++;
        }
        s.resize(right-1);

        return s;
    }
};