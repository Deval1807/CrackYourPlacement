/*
Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
Method: if child, save the next and make the curr->next to child and its end of next to saved next
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(0);
        ListNode* second = new ListNode(0);
        ListNode* f = first;
        ListNode* s = second;
        ListNode* curr = head;

        while(curr != NULL){
            if(curr->val < x){
                f->next = curr;
                f = f->next;
            }else{
                s->next = curr;
                s = s->next;
            }
            curr = curr->next;
        }
        f->next = second->next;
        s->next = NULL;
        return first->next;

    }
};