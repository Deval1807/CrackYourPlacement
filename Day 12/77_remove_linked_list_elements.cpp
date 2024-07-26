/*
Link: https://leetcode.com/problems/remove-linked-list-elements/
Method: First delete the intial nodes with value of "val" and then traverse simply and delete
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
    ListNode* removeElements(ListNode* head, int value) {
        
        // remove the initial nodes with value
        while(head) {
            if(head->val == value) head=head->next;
            else break;
        }

        if(head==NULL) return head;

        ListNode* temp = head;
        while(temp->next!=NULL) {
            if(temp->next->val == value) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;

    }
};