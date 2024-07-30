/*
Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
Method: Extra array
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
       vector<int>v;
       Node *curr = root;
       while(curr!=NULL){
           Node *temp = curr;
           while(temp!=NULL){
               v.push_back(temp->data);
               temp = temp->bottom;
           }
           curr=curr->next;
       }
       sort(v.begin(), v.end());
       Node *head = new Node(v[0]);
       Node *curr1 = head;
       for(int i=1;i<v.size();i++){
           curr1->bottom = new Node(v[i]);
           curr1 = curr1->bottom;
       }
       return head;
    }
};