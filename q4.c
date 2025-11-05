#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 5000

char stack[MAX];
int top = -1;


void push(char c) {
    stack[++top] = c;
}


char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}


int isRightAssociative(char op) {
    return (op == '^') ? 1 : 0;
}


void infixToPostfix(char* s) {
    char result[MAX];
    int k = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        
        if (isalnum(c)) {
            result[k++] = c;
        }
        
        else if (c == '(') {
            push(c);
        }
        
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                result[k++] = pop();
            }
            pop(); 
        }
        
        else {
            while (top != -1 && precedence(peek()) > 0) {
                if ((isRightAssociative(c) == 0 && precedence(c) <= precedence(peek())) ||
                    (isRightAssociative(c) == 1 && precedence(c) < precedence(peek()))) {
                    result[k++] = pop();
                } else {
                    break;
                }
            }
            push(c);
        }
    }

    
    while (top != -1) {
        result[k++] = pop();
    }

    result[k] = '\0';
    printf("%s\n", result);
}


int main() {
    char s[MAX];
    scanf("%s", s);
    infixToPostfix(s);
    return 0;
}
