#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void insertionsort(int arr[],int size){

    for (int i = 1; i < size; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[],int size){
    printf("sorted elements are : ");
    for (int i = 0; i < size; i++)
    { 
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void selectionsort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        int min=i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[min]>arr[j]){
                min=j;
         }

        
        }
        if(min!=i){
            swap(&arr[i],&arr[min]);
        }
    }
}
void bubblesort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j <size-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
            
        }
    }
}
void merge(int arr[], int s, int mid, int e) {
    int i, j, k;
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[s + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = s;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *arr,int s,int e){
    if (s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int partition(int *arr,int s ,int e){
    int pivot=arr[s];
    int i=s;
    int j=e;
    int cnt=0;
    for (int i = s+1; i<=e; i++)
    {
        if (arr[i]<=pivot)
        {
            cnt++;
        }
    }
    int pivotindex=s+cnt;
    swap(&arr[pivotindex],&arr[s]);
        
    while (i<pivotindex && j>pivotindex)
    {
        while (arr[i]<pivot)
            {
                i++;
            }
        while (arr[j]>pivot)
        {
                j--;
        }

       if (i<pivotindex && j>pivotindex)
            {
                swap(&arr[i++],&arr[j--]);
            }    
    }
    return pivotindex;

}

void quicksort(int*arr,int s,int e){
    if(s>=e){
    return;
    }
    int loc=partition(arr,s,e);
    quicksort(arr,s,loc-1);
    quicksort(arr,loc+1,e);
    
}
void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int arr[]={14,12,1,0,1456,78,44,24};
    int size=sizeof(arr)/sizeof(arr[0]);
    int choice;
    printf("Choose a sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertionsort(arr, size);
            break;
        case 2:
            selectionsort(arr, size);
            break;
        case 3:
            bubblesort(arr, size);
            break;
        case 4:
            mergesort(arr, 0, size - 1);
            break;
        case 5:
            quicksort(arr, 0, size - 1);
            break;
        case 6:
            heapsort(arr, size);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    display(arr, size);

    return 0;
}

