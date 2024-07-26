/*
Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
Method: traverse and add val, multiply by 2 if not last
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
    int getDecimalValue(ListNode* head) {
        int i=0;
        ListNode *ptr=head;
        while(ptr!=nullptr)
        {
            i+=ptr->val;
            ptr=ptr->next;
            if(ptr!=nullptr)
                 i=i*2;
        }
        return i;
    }
};