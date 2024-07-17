/*
Link: https://leetcode.com/problems/game-of-life/
Method: Brute force
Time Complexity: O(n*n*8)
Space Complexity: O(1) extra
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> directions = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};

        int m = board.size();
        int n = board[0].size();

        // First pass - find the neighbours
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int liveCount = 0;

                // check neighbours
                for(auto direction: directions) {
                    int newx = i + direction.first;
                    int newy = j + direction.second;

                    if(newx>=0 && newx<m && newy>=0 && newy<n && abs(board[newx][newy])==1) {
                        liveCount++;
                    }
                }

                // now we have the no of live neighbours for board[i][j]
                // apply all the rules
                if(board[i][j] == 1 && (liveCount<2 || liveCount>3)) {
                    // board will be dead in next state
                    board[i][j] = -1;
                }
                if(board[i][j] == 0 && liveCount == 3) {
                    // board will be live in next state
                    board[i][j] = 2;
                }
            }
        }

        // Second pass - update
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == -1) board[i][j]=0;
                if(board[i][j] == 2) board[i][j]=1;
            }
        }
    }
};