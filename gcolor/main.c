#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the starting index: ");
    int start;
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid index. Index must be within the array bounds.\n");
    } else {
        printf("Array elements starting from index %d:\n", start);

        // Use a single loop to print elements in a circular manner
        for (int i = start; ; i = (i + 1) % n) {
            printf("%d ", arr[i]);

            // Stop the loop when we reach the element before the starting index
            if (i == (start == 0 ? n - 1 : start - 1)) {
                break;
            }
        }

        printf("\n");
    }

    return 0;
}
