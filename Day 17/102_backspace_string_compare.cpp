/*
Link: https://leetcode.com/problems/backspace-string-compare/description/
Method: push into stack, whenever '#' , pop, compare at last
Time Complexity: O(n)
Space Complexity: O(n) 
*/

class Solution {
public:

    string newStr(string s){
        string news="";
        stack<char> st;
        for(auto c:s){
            if(c!='#'){
                st.push(c);
            }else if(!st.empty()){
                st.pop();
            }
        }

        while(!st.empty()){
            news = st.top() + news;
            st.pop();
        }

        return news;
    }

    bool backspaceCompare(string s, string t) {
        string s1 = newStr(s);
        string s2 = newStr(t);

        return s1==s2;
    }
};