#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stack[1000];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int floor_div(int a, int b) {
    int res = a / b;
    if ((a < 0 && b > 0 || a > 0 && b < 0) && (a % b != 0))
        res -= 1;
    return res;
}

int evaluatePostfix(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        char *token = arr[i];

        if (!(strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
              strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
              strcmp(token, "^") == 0)) {
            push(atoi(token));
        } 
        else {  
            int b = pop();
            int a = pop();
            int res;

            if (strcmp(token, "+") == 0) res = a + b;
            else if (strcmp(token, "-") == 0) res = a - b;
            else if (strcmp(token, "*") == 0) res = a * b;
            else if (strcmp(token, "/") == 0) res = floor_div(a, b);
            else res = (int)pow(a, b);

            push(res);
        }
    }
    return stack[top];
}

int main() {
    // Example 1
    char *arr1[] = {"-8", "3", "/"};
    int n1 = 3;
    printf("Result = %d\n", evaluatePostfix(arr1, n1));  // Output: -3

    // Example 2
    char *arr2[] = {"2", "3", "1", "*", "+", "9", "-"};
    int n2 = 7;
    printf("Result = %d\n", evaluatePostfix(arr2, n2));  // Output: -4

    return 0;
}
