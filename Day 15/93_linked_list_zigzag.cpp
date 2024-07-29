/*
should be of the form a < b > c < d > e < f …
Link: https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/
Method: 
Time Complexity: O(n)
Space Complexity: O(n)
*/

// Rearrange the linked list in zig zag way
// initially flag = 1
node* zigzag(node* head, bool flag)
{
    if (!head || !head->next)
        return head;
    if (flag == 1) {
        if (head->data > head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
    else {
        if (head->data < head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
}