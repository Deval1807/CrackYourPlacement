/*
Link: https://leetcode.com/problems/sort-list/description/
Method: extra array
Time Complexity: O(nlogn)
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
    ListNode* sortList(ListNode* head) {
        vector<int> temp_vec;

        ListNode *temp = head;
        while (temp != nullptr) {
            temp_vec.push_back(temp -> val);
            temp = temp -> next;
        }

        sort(temp_vec.begin(), temp_vec.end());

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp -> val = temp_vec[i++];
            temp = temp -> next;
        }

        return head;
    }
};