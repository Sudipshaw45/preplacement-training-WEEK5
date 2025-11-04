#include <stdio.h>
#define MAX 100   

struct MyStack {
    int arr[MAX];
    int top;
};


void initStack(struct MyStack *s) {
    s->top = -1;
}

void push(struct MyStack *s, int x) {
    if (s->top == MAX - 1) {
        return;
    }
    s->arr[++(s->top)] = x;
}

int pop(struct MyStack *s) {
    if (s->top == -1) {
        return -1;  
    }
    return s->arr[(s->top)--];
}

void stackOperations(int oper[], int n) {
    struct MyStack s;
    initStack(&s);

    for (int i = 0; i < n; i++) {
        if (oper[i] == 1) {
            i++;
            push(&s, oper[i]);
        }
        else if (oper[i] == 2) {
            printf("%d ", pop(&s));
        }
    }
    printf("\n");
}

int main() {
    int oper1[] = {1, 2, 1, 3, 2, 1, 4, 2};
    int n1 = sizeof(oper1) / sizeof(oper1[0]);
    stackOperations(oper1, n1);  

    int oper2[] = {2, 1, 4, 1, 5, 2};
    int n2 = sizeof(oper2) / sizeof(oper2[0]);
    stackOperations(oper2, n2); 

    return 0;
}
