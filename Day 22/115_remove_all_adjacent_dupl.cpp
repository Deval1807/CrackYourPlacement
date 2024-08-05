/*
Link: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1
Method: Stack - store the character and its freq
Time Complexity: O(n)
Space Complexity: O(n) 
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack to store pairs of (character, count)
        vector<pair<char, int>> stack;
        for(auto&c : s){
            if(!stack.empty() && stack.back().first == c){
                // Increment the count if the top of the stack has the same character
                stack.back().second++;
            }else{
                // Push new character with count 1
                stack.push_back({c, 1});
            }
            // If the count reaches k, remove it from the stack
            if(stack.back().second == k){
                stack.pop_back();
            }
        }
        string result;
        for(auto&p : stack){
            result.append(p.second, p.first);
        }
        return result;
    }
};