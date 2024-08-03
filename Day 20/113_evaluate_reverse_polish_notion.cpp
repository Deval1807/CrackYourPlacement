/*
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
Method: Stack
Time Complexity: O(n)
Space Complexity: O(n) 
*/

class Solution {
public:
    // use stack

    long solve(stack<long> &st, char op) {
        
        long num2 = st.top();
        st.pop();
        long num1 = st.top();
        st.pop();  
              
        if(op == '+') return num1 + num2;
        if(op == '-') return num1 - num2;
        if(op == '*') return num1 * num2;
        return num1 / num2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(int ind = 0; ind<tokens.size(); ind++) {
            if(tokens[ind].size()==1 && tokens[ind][0] < 48) {
                    long ans = solve(st, tokens[ind][0]);
                    st.push(ans);              
            }else{
                st.push(stoi(tokens[ind]));
            }
        }
        return st.top();
    }
};