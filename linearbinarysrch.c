#include <stdio.h>
#include <stdbool.h>

int linearSearch(int array[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            return i+1;
        }
    }
    return -1;
}

int binarySearch(int array[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == key) {
            return mid+1; 
        }

        if (array[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; 
}



int main() {
    int arr[] = {1, 2, 5, 11, 12, 15, 178, 522, 600, 700, 720, 1000};
    int key;
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice, result;
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);

    }
    printf("\n");
    printf("_____________________\n\n");
    printf("1. Linear search \n");
    printf("2. Binary search \n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the element you want to search: ");
            scanf("%d", &key);
            result = linearSearch(arr, size, key);
            if (result != -1) {
                printf("Element %d found at positon %d in the array.\n", key, result);
            } else {
                printf("Element %d not found in the array.\n", key);
            }
            break;
        case 2:
            printf("Enter the element you want to search: ");
            scanf("%d", &key);
            result = binarySearch(arr, 0, size - 1, key);
            if (result != -1) {
                printf("Element %d found at position %d in the array.\n", key, result);
            } else {
                printf("Element %d not found in the array.\n", key);
            }
            break;
        default:
            break;
    }

    return 0;
}
