#include <stdio.h>

void calculateSpan(int price[], int n, int span[]) {
    int stack[n];  
    int top = -1;

    
    span[0] = 1;
    stack[++top] = 0;

    for (int i = 1; i < n; i++) {
    
        while (top >= 0 && price[stack[top]] <= price[i]) {
            top--;
        }

        if (top < 0)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];

        stack[++top] = i;
    }
}

int main() {
    int price[] = {100, 80, 90, 120};
    int n = sizeof(price) / sizeof(price[0]);
    int span[n];

    calculateSpan(price, n, span);

    printf("Stock spans: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
    printf("\n");

    int price2[] = {10, 4, 5, 90, 120, 80};
    int n2 = sizeof(price2) / sizeof(price2[0]);
    int span2[n2];

    calculateSpan(price2, n2, span2);

    printf("Stock spans: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", span2[i]);
    }
    printf("\n");

    return 0;
}
