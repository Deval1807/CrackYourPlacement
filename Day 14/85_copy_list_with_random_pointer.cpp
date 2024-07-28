/*
Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
Method: Map data structure
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;

        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};