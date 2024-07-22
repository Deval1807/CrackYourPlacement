/*
Link: https://www.geeksforgeeks.org/problems/print-anagrams-together/1
Method: Hash table - store all the anagrams with key of that sored word
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> mp;
        
        for(int i = 0; i<string_list.size(); i++) {
            string s = string_list[i];
            
            sort(s.begin(), s.end());
            
            mp[s].push_back(string_list[i]);
        }
        
        for(auto it: mp) {
            res.push_back(it.second);
        }
        
        return res;
    }
};