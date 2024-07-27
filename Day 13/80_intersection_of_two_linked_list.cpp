/*
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
Method: when you reach end in 1 LL, go to the start of next LL
Time Complexity: O(n)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2) {
            temp1 = temp1==NULL ? headB : temp1->next;
            temp2 = temp2==NULL ? headA : temp2->next;
        }
        return temp1;
    }
};