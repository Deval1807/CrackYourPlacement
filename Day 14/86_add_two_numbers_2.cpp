/*
Link: https://leetcode.com/problems/add-two-numbers-ii/
Method: reverse both the linked list and then add (since we cannot traverse the LL from behind), finally reverse the ans string to get the desired result
Time Complexity: O(n)
Space Complexity: O(n)
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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse both and then add
        // reverse the ans
        ListNode* rev1 = reverse(l1);
        ListNode* rev2 = reverse(l2);
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        int carry = 0;

        while(rev1 || rev2 || carry) {
            int sum = 0;
            if(rev1) {
                sum += rev1->val;
                rev1 = rev1->next;
            }
            if(rev2) {
                sum += rev2->val;
                rev2 = rev2->next;
            }
            sum += carry;

            carry = sum/10;

            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }

        ListNode* ans = reverse(dummy->next);

        return ans;
    }
};