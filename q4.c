#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 5000

// Stack for operators
char stack[MAX];
int top = -1;

// Push to stack
void push(char c) {
    stack[++top] = c;
}

// Pop from stack
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Peek top of stack
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Check precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Check associativity: returns 1 if right-to-left, 0 if left-to-right
int isRightAssociative(char op) {
    return (op == '^') ? 1 : 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* s) {
    char result[MAX];
    int k = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // If operand, add to output
        if (isalnum(c)) {
            result[k++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                result[k++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
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

    // Pop remaining operators
    while (top != -1) {
        result[k++] = pop();
    }

    result[k] = '\0';
    printf("%s\n", result);
}

// Driver code
int main() {
    char s[MAX];
    scanf("%s", s);
    infixToPostfix(s);
    return 0;
}
