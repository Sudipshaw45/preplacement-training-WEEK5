#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return; 

    newNode->data = x;
    newNode->next = top; 
    top = newNode;        
}

int pop() {
    if (top == NULL) {
        return -1; 
    }
    int val = top->data;
    struct Node* temp = top;
    top = top->next;   
    free(temp);       
    return val;
}

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

int main() {
    int queries1[][2] = {{1,2}, {1,3}, {2,0}, {1,4}, {2,0}};
    int n1 = sizeof(queries1) / sizeof(queries1[0]);
    stackOperations(queries1, n1);

    int queries2[][2] = {{2,0}, {1,4}, {1,5}, {2,0}};
    int n2 = sizeof(queries2) / sizeof(queries2[0]);
    stackOperations(queries2, n2);

    return 0;
}
