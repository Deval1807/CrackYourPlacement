/*
Link: https://leetcode.com/problems/reorder-list/description/
Method: 2 pointers. first increase the fast pointer by n, then increase both fast and slow by 1 till fast reaches end
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // find size - go till size-n - remove
        // TC: O(2N) :(
        /*
        if(n==1 and head->next==NULL){
            head = NULL;
            return head;
        }
        int ct = 0;
        ListNode *temp = head;
        while(temp) {
            ct++;
            temp = temp->next;
        }
        if(ct==n)  {
            head = head->next;
        }else{
        int needed = ct - n;
        temp = head;
        for(int i = 0; i<needed-1; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        }
        return head;
        */
        
        // TC of O(N) (Optimised)
        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* fast = temp;
        ListNode* slow = temp;

        for(int i = 0; i<n; i++) {
            fast = fast->next;
        }
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        // return temp->next instead of head
        // to handle the edge case of n == size
        return temp->next;
    }
};