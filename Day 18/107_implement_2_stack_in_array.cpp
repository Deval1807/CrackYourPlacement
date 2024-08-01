/*
Link: https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1
Method: 
Time Complexity: O(1)
Space Complexity: O(n) 
*/

// The idea is to start two stacks from two extreme corners of arr[].
// stack1 starts from the leftmost element, the first element in stack1 is
// pushed at index 0. The stack2 starts from the rightmost corner, the first
// element in stack2 is pushed at index (n-1). Both stacks grow (or shrink)
// in opposite direction. To check for overflow, all we need to check is for
// space between top elements of both stacks.
class twoStacks {
    int *arr;
    int size;
    int top1, top2;

  public:
    twoStacks(int n = 100) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // if there is space between the top of both stacks
        // we push the element at top1+1.
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // if there is space between the top of both stacks
        // we push the element at top2-1.
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        // if top1==-1, stack1 is empty so we return -1 else we
        // return the top element of stack1.
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else
            return -1;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        // if top2==size of array, stack2 is empty so we return -1 else we
        // return the top element of stack2.
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        } else
            return -1;
    }
};
