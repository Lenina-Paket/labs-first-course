#include <stdio.h>
#include <stdlib.h>

typedef struct MyStructure {
    int key;
    int value;
} Mas;


void PrintKeys(Mas *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].key);
    }
    printf("\n");
}

void PrintValues(Mas *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}
 
void Swap(Mas *x, Mas *y) {
    Mas tmp = *x;
    *x = *y;
    *y = tmp;
}
 
int end;
void Heapify(Mas arr[], int i) {
    
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
 
    if (left < end && arr[left].key > arr[i].key) {
        largest = left;
    }
 
    if (right < end && arr[right].key > arr[largest].key) {
        largest = right;
    }
 
    if (largest != i) {
        Swap(&arr[i], &arr[largest]);
        Heapify(arr, largest);
    }
}

void BuildHeap(Mas arr[]) {
    int i = (end - 2) / 2;
    while (i >= 0) {
        Heapify(arr, i--);
    }
}
 
void Heapsort(Mas arr[], int n) {
    end = n;
    BuildHeap(arr);
    while (end != 1) {
        Swap(&arr[0], &arr[end - 1]);
        end--;
        Heapify(arr, 0);
    }
}

int BinarySearch(Mas arr[], int n, int value) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid].key == value) return arr[mid].value;
        if (arr[mid].key > value) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
 
int main(void) {
    Mas arr[10] = {};
    int n = 10;
    //int n = sizeof(arr) / sizeof(arr[0]);
    int index, ans = -1;
    int key, value;
    printf("Let's scan some elements of your elts\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &key, &value);
        arr[i].key = key;
        arr[i].value = value;
    }

    Heapsort(arr, n);

    PrintKeys(arr, n);
    PrintValues(arr, n);

    printf("Let's go to find your key!\n");
    scanf("%d", &index);
    int low = 0, high = n - 1, mid;
    ans = BinarySearch(arr, n, index);

    if (ans != -1) printf("%d\n", ans);
    else printf("No element\n");

    return 0;
}