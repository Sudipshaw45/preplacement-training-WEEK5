#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer (head of stack)
struct Node* top = NULL;

// Function to push an element into stack
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return; // memory allocation failed

    newNode->data = x;
    newNode->next = top;  // new node points to old top
    top = newNode;        // update top
}

// Function to pop an element from stack
int pop() {
    if (top == NULL) {
        return -1; // stack empty
    }
    int val = top->data;
    struct Node* temp = top;
    top = top->next;   // move top to next node
    free(temp);        // free memory of popped node
    return val;
}

// Function to process input queries
void stackOperations(int queries[][2], int n) {
    for (int i = 0; i < n; i++) {
        if (queries[i][0] == 1) {
            push(queries[i][1]);
        } else if (queries[i][0] == 2) {
            printf("%d ", pop());
        }
    }
    printf("\n");
}

// Driver code
int main() {
    int queries1[][2] = {{1,2}, {1,3}, {2,0}, {1,4}, {2,0}};
    int n1 = sizeof(queries1) / sizeof(queries1[0]);
    stackOperations(queries1, n1);  // Output: 3 4

    int queries2[][2] = {{2,0}, {1,4}, {1,5}, {2,0}};
    int n2 = sizeof(queries2) / sizeof(queries2[0]);
    stackOperations(queries2, n2);  // Output: -1 5

    return 0;
}
