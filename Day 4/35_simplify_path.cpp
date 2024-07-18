/*
Link: https://leetcode.com/problems/simplify-path/
Method: stack
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string dir;

        while(getline(ss, dir, '/')) {
            if(dir == "." || dir.empty()) {
                continue;
            }else if(dir == "..") {
                if(!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(dir);
            }
        }

        string ans = "/";
        for(int i = 0; i<stack.size(); i++) {
            ans += stack[i];
            if(i < stack.size()-1) {
                ans += "/";
            }
        }
        

        return ans;
    }
};