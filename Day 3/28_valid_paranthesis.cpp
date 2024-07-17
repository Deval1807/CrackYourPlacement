/*
Link: https://leetcode.com/problems/valid-parentheses/description/
Method: Stack 
Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    bool isValid(string s) {
        
        if(s.size()==1) return false;

        stack<char> st;
        
        for(char c: s) {
            if(c == '(' || c == '{' || c== '[') st.push(c);
            else if(c == ')') {
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            }
            else if(c == '}') {
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            }
            else{
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            }
        }

        return st.empty();
    }
};