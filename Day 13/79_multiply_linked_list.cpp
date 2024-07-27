/*
Link: https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1
Method: get 2 numbers as int and multiply
Time Complexity: O(n)
Space Complexity: O(1)
*/

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1 = 0, num2 = 0;
        int mod = 1000000007;
        while (first || second) {
            if (first) {
                num1 = ((num1 * 10) % mod + (first->data) % mod) % mod;
                first = first->next;
            }
            if (second) {
                num2 = ((num2 * 10) % mod + second->data % mod) % mod;
                second = second->next;
            }
        }

        return (num1 % mod * num2 % mod) % mod;
    }
};