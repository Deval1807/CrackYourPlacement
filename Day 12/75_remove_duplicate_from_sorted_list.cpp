/*
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
Method: traverse simply and delete
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        if(head == NULL) return head;

        while(temp->next != NULL) {
            if(temp->val == temp->next->val) {
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }

        return head;
    }
};