/*
Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // brute -> extra space

        // optimised -> in place

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val > l2->val) swap(l1, l2);

        ListNode* ans = l1;

        while(l1 != NULL && l2 != NULL) {
            ListNode* temp = NULL;
            while(l1 != NULL && (l1->val <= l2->val)) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }

        return ans;
    }
};