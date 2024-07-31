/*
Link: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
Method: stack 
Time Complexity: O(n)
Space Complexity: O(n) 
*/

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        
        //iterating over the given string.
        for (int i = 0; i<S.size(); ++i)
        {
            //if current character is an operand, we push it to the stack.
            if (isdigit(S[i]))
                st.push(S[i] - '0');
    
            //else current character is an operator.
            else
            {
                //we pop and store the values of first two elements of stack.
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                
                //we perform required operation and push the result in stack.
                switch (S[i])
                {
                 case '+': st.push(val2 + val1); break;
                 case '-': st.push(val2 - val1); break;
                 case '*': st.push(val2 * val1); break;
                 case '/': st.push(val2 / val1); break;
                }
            }
        }
        //returning the top element of the stack.
        return st.top();
    }
};