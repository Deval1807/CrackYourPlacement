/*
Link: https://leetcode.com/problems/online-stock-span/description/
Method: Just like daily temperature problem
Time Complexity: O(n)
Space Complexity: O(n) 
*/

class StockSpanner {
public:

    stack<pair<int, int>> s;

    StockSpanner() {}
    
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */