#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

# define MAX_SIZE 20000

int main()
{
    int n = MAX_SIZE;
    double start, end;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++) {
        Mainarr[i] = rand() % n + 1;

        for (int j = 0; j < i; j++) {
            if (Mainarr[i] == Mainarr[j]) {
                i--;
                break;
            }
        }
    }

    Setarr(Mainarr);
    //printf("arr  : ");
    //PrintArr(arr, n);
    
    //ExchangeSort 
    printf("랜덤값 %d 일때\n\n", MAX_SIZE);
    start = (double)clock() / CLOCKS_PER_SEC;
    ExchangeSort(arr, n);                     
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("ExchangeSort 수행 시간 :%lf\n", (end - start));
    
    //MergeSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    MergeSort(arr, 0, n - 1);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("MergeSort    수행 시간 :%lf\n", (end - start));
    
    //QuickSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    QuickSort(arr, 0, n - 1);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("QuickSort    수행 시간 :%lf\n", (end - start));
    
    //HeapSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    HeapSort(arr, n);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("HeapSort     수행 시간 :%lf\n", (end - start));

    //RadixSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    RadixSort(arr, n);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("RadixSort    수행 시간 :%lf\n", (end - start));
    

    //printf("Sort : ");
    //PrintArr(arr, n);
    


    return 0;
}