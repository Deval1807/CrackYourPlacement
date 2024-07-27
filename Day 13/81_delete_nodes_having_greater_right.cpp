/*
Link: https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
Method: recursive
Time Complexity: O(n)
Space Complexity: O(n) recursive stack space
*/

class Solution {
public:
    Node* compute(Node* head) {
        if (head->next == nullptr) {
            return head;
        }
        
        head->next = compute(head->next);
        if (head->data < head->next->data) {
            return head->next;
        }
        
        return head;
    }
};