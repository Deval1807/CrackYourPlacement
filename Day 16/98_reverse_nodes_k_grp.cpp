/*
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
Method: find the kth element and reverse the first k element and than next is the kth element
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

    ListNode* reverseLinkedList(ListNode* curr) {
        ListNode* prev = NULL;
        ListNode* currNext;
        while(curr!=NULL) {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* curr, int k) {
        k-=1;
        while(curr != NULL && k > 0){
            k--;
            curr = curr->next;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp!=NULL) {
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == NULL) {
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseLinkedList(temp);
            
            //if first group set head to the newHead
            if(temp==head) {
                head = kthNode;
            }else {
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};