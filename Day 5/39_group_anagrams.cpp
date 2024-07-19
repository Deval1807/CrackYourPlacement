/*
Link: https://leetcode.com/problems/group-anagrams/
Method: map - sort the word and use as key
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());     // eat -> aet
            mp[word].push_back(x);              // aet: [eat, tea, ate]
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};