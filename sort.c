#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"



void ExchangeSort(int arr[], int n) {
    int temp = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Merge(int arr[], int left, int m, int right) {

    int i = left;
    int j = m + 1;
    int k = left;

    while (i <= m && j <= right) {
        if (arr[i] <= arr[j])
            Merge_sorted[k++] = arr[i++];
        else
            Merge_sorted[k++] = arr[j++];
    }

    if (i > m) {
        for (int l = j; l <= right; l++)
            Merge_sorted[k++] = arr[l];
    }
    else {
        for (int l = i; l <= m; l++)
            Merge_sorted[k++] = arr[l];
    }


    for (int l = left; l <= right; l++) {
        arr[l] = Merge_sorted[l];
    }
}


void MergeSort(int arr[], int left, int right) {
    int m;

    if (left < right) {
        m = (left + right) / 2;
        MergeSort(arr, left, m);
        MergeSort(arr, m + 1, right);
        Merge(arr, left, m, right);
    }
}

int Partition(int arr[], int left, int right) {
    int p;
    int temp;
    int low;
    int high;

    low = left;
    high = right + 1;
    p = arr[left];

    do {
        do {
            low++;
        } while (low <= right && arr[low] < p);


        do {
            high--;
        } while (high >= left && arr[high] > p);


        if (low < high) {
            SWAP(arr[low], arr[high], temp);
        }
    } while (low < high);


    SWAP(arr[left], arr[high], temp);


    return high;
}

void QuickSort(int arr[], int left, int right) {

    if (left < right) {
        int q = Partition(arr, left, right);

        QuickSort(arr, left, q - 1);
        QuickSort(arr, q + 1, right);
    }

}

void heap_swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heap(int arr[], int n, int i) {

    int c = 2 * i + 1;


    if (c < n - 1 && arr[c] < arr[c + 1])
        c++;


    if (c < n && arr[i] < arr[c])
        heap_swap(arr, i, c);


    if (c < n / 2)
        heap(arr, n, c);
}

void HeapSort(int arr[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heap(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        heap_swap(arr, i, 0);
        heap(arr, i, 0);
    }

}

void RadixSort(int arr[], int n) {
    int result[MAX_SIZE];
    int max = 0;
    int exp = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    while (max / exp > 0) {
        int bucket[10] = { 0 };

        for (int i = 0; i < n; i++)
            bucket[arr[i] / exp % 10]++;

        for (int i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            result[--bucket[arr[i] / exp % 10]] = arr[i];
        }
        for (int i = 0; i < n; i++) arr[i] = result[i];
        exp *= 10;
    }
}





void PrintArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void Setarr(int a[]) {
    int n = MAX_SIZE;
    for (int i = 0; i < n; i++) {
        arr[i] = a[i];
    }
}