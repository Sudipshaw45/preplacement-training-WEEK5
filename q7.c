#include <stdio.h>

void nextLargerElement(int arr[], int n, int result[]) {
    int stack[n]; 
    int top = -1;

  
    for (int i = n - 1; i >= 0; i--) {
        
        while (top >= 0 && stack[top] <= arr[i]) {
            top--;
        }

        if (top >= 0)
            result[i] = stack[top];
        else
            result[i] = -1;

        stack[++top] = arr[i];
    }
}

int main() {
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];

    nextLargerElement(arr, n, result);

    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    int arr2[] = {6, 8, 0, 1, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2[n2];

    nextLargerElement(arr2, n2, result2);

    printf("Next Greater Elements:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    return 0;
}
