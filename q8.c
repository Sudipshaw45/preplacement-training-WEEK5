#include <stdio.h>


int knows(int mat[][1000], int a, int b) {
    return mat[a][b];
}

int celebrity(int mat[][1000], int n) {
    int stack[1000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    while (top > 0) {
        int a = stack[top--];
        int b = stack[top--];

        if (knows(mat, a, b)) {
           
            stack[++top] = b;
        } else {
           
            stack[++top] = a;
        }
    }

    if (top < 0) return -1;

    int cand = stack[top];

    
    for (int i = 0; i < n; i++) {
        if (i != cand) {
            
            if (mat[cand][i] == 1 || mat[i][cand] == 0) {
                return -1;
            }
        }
    }

    return cand;
}

int main() {
    int n = 3;
    int mat[1000][1000] = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };

    int result = celebrity(mat, n);
    if (result == -1)
        printf("No Celebrity Found\n");
    else
        printf("Celebrity is Person %d\n", result);

    // Another example
    int mat2[1000][1000] = {
        {1, 1},
        {1, 1}
    };
    int n2 = 2;

    result = celebrity(mat2, n2);
    if (result == -1)
        printf("No Celebrity Found\n");
    else
        printf("Celebrity is Person %d\n", result);

    return 0;
}
