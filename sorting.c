
#include <stdio.h>

#define N 8

int mergeComparisons = 0, mergeWrites = 0, mergePasses = 0;
int quickComparisons = 0, quickSwaps = 0, quickPartitions = 0;

void printArray(int a[]) {
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* MERGE SORT */
void merge(int a[], int left, int mid, int right) {
    int temp[N];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        mergeComparisons++;

        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];

        mergeWrites++;
    }

    while (i <= mid) {
        temp[k++] = a[i++];
        mergeWrites++;
    }

    while (j <= right) {
        temp[k++] = a[j++];
        mergeWrites++;
    }

    for (i = left; i <= right; i++) {
        a[i] = temp[i];
        mergeWrites++;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);

    mergePasses++;
    printf("Merge operation %d: ", mergePasses);
    printArray(a);
}

/* QUICK SORT */
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quickComparisons++;

        if (a[j] <= pivot) {
            i++;

            if (i != j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                quickSwaps++;
            }
        }
    }

    if (i + 1 != high) {
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;
        quickSwaps++;
    }

    quickPartitions++;
    printf("Partition %d (pivot %d): ",
           quickPartitions, pivot);
    printArray(a);

    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int original[N] = {
        324, 125, 456, 218, 102, 389, 275, 147
    };

    int a[N], b[N];

    for (int i = 0; i < N; i++) {
        a[i] = original[i];
        b[i] = original[i];
    }

    printf("SORTING FIXED-LENGTH IDs\n");

    printf("\nOriginal array: ");
    printArray(original);

    printf("\n--- MERGE SORT ---\n");
    mergeSort(a, 0, N - 1);

    printf("Sorted array: ");
    printArray(a);

    printf("Merge operations: %d\n", mergePasses);
    printf("Comparisons: %d\n", mergeComparisons);
    printf("Array writes: %d\n", mergeWrites);

    printf("\n--- QUICK SORT ---\n");
    quickSort(b, 0, N - 1);

    printf("Sorted array: ");
    printArray(b);

    printf("Partitions: %d\n", quickPartitions);
    printf("Comparisons: %d\n", quickComparisons);
    printf("Swaps: %d\n", quickSwaps);

    printf("\n--- COMPLEXITY ---\n");
    printf("Merge Sort: O(n log n) time, O(n) extra space\n");
    printf("Quick Sort: Average O(n log n), "
           "worst O(n^2) time\n");
    printf("Quick Sort uses O(log n) average stack space.\n");

    return 0;
}
