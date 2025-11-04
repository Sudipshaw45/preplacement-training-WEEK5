#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000   // maximum length of bracket string

// Function to check if brackets are balanced
const char* isBalanced(char* s) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        // if opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else {
            // if closing bracket but stack is empty
            if (top == -1) return "NO";

            char last = stack[top--]; // pop

            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return "NO";
            }
        }
    }

    // if stack is empty → balanced
    return (top == -1) ? "YES" : "NO";
}

int main() {
    int n;
    scanf("%d", &n);
    char s[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }

    return 0;
}
