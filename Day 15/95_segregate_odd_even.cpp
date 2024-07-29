/*
Link: https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
Method: 2 separate ll and then merge
Time Complexity: O(n)
Space Complexity: O(1)
*/

// Function to segregate even and odd nodes.
void segregateEvenOdd(struct Node** head_ref)
{
    // Starting node of list having even values.
    Node* evenStart = nullptr;
    
    // Ending node of even values list.
    Node* evenEnd = nullptr;
    
    // Same for the odd list.
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;
    
    // Node to traverse the list.
    Node* currNode = *head_ref;

    while (currNode != nullptr) {
        int val = currNode->data;

        // If current value is even, add it to even values
        // list.
        if (val % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }

        // If current value is odd, add it to odd values
        // list.
        else {
            if (oddStart == nullptr) {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }

        // Move head pointer one step in forward direction
        currNode = currNode->next;
    }

    // If either odd list or even list is empty, no change
    // is required as all elements are either even or odd.
    if (oddStart == nullptr || evenStart == nullptr)
        return;

    // Add odd list after even list.
    evenEnd->next = oddStart;
    oddEnd->next = nullptr;

    // Modify head pointer to starting of even list.
    *head_ref = evenStart;
}