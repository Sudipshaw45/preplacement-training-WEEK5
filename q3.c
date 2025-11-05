#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000 

const char* isBalanced(char* s) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else {

            if (top == -1) return "NO";

            char last = stack[top--]; 

            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return "NO";
            }
        }
    }

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
