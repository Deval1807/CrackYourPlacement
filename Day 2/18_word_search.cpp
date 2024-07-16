/*
Link: https://leetcode.com/problems/word-search/
Method: dfs
Time Complexity: O(m*n*4^l) where l is the length of the word
Space Complexity: recursive stack space
*/

class Solution {
public:

    bool dfs(int i, int j, int ind, vector<vector<char>>& board, string word) {
        
        // base case - traversed the word completely
        if(ind == word.size()) return true;

        // out of bounds
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;

        // compare word
        if(word[ind] != board[i][j]) return false;

        // mark the current element as visited
        char curr = board[i][j];
        board[i][j] = ' ';

        // traverse
        bool ans = dfs(i-1, j, ind+1, board, word) ||
                   dfs(i+1, j, ind+1, board, word) ||
                   dfs(i, j-1, ind+1, board, word) ||
                   dfs(i, j+1, ind+1, board, word);
        
        // put back the curr 
        board[i][j] = curr;

        return ans;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0] && dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};