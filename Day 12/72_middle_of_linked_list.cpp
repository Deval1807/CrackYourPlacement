/*
Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
Method: 2 pointers - fast and slow
Time Complexity: O(n)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        /*
        int ct = 0;
        ListNode* temp = head;
        while(temp!=NULL) {
            ct++;
            temp = temp->next;
        }
        for(int i = 0; i < (ct)/2; i++) {
            head = head->next;
        }
        return head;
        */

        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};