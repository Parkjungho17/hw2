#include<stdio.h>
#include <stdlib.h>
#include <time.h>

# define MAX_SIZE 10

int sorted[MAX_SIZE];



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

void Merge(int list[], int left, int mid, int right) {
    
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
  
    if (i > mid) {
        for (int l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    
    else {
        for (int l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    
    for (int l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}


void MergeSort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2; 
        MergeSort(list, left, mid);
        MergeSort(list, mid + 1, right);
        Merge(list, left, mid, right);
    }
}

void PrintArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    int n = MAX_SIZE;
    double start, end;

    int* arr = malloc(sizeof(int) * n);

    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                i--;
                break;
            }
        }
    }
    printf("arr : ");
    PrintArr(arr, n);
    
    //ExchangeSort 
    /*
    start = (double)clock() / CLOCKS_PER_SEC;
    ExchangeSort(arr, n);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("ExchangeSort : ");
    PrintArr(arr, n);
    printf("프로그램 수행 시간 :%lf\n", (end - start));
    */
    //merge
    start = (double)clock() / CLOCKS_PER_SEC;
    MergeSort(arr, 0, n - 1);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("MergeSort : ");
    PrintArr(arr, n);
    printf("프로그램 수행 시간 :%lf\n", (end - start));

    free(arr);

    return 0;
}