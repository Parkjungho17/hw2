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
    printf("������ %d �϶�\n\n", MAX_SIZE);
    start = (double)clock() / CLOCKS_PER_SEC;
    ExchangeSort(arr, n);                     
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("ExchangeSort ���� �ð� :%lf\n", (end - start));
    
    //MergeSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    MergeSort(arr, 0, n - 1);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("MergeSort    ���� �ð� :%lf\n", (end - start));
    
    //QuickSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    QuickSort(arr, 0, n - 1);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("QuickSort    ���� �ð� :%lf\n", (end - start));
    
    //HeapSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    HeapSort(arr, n);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("HeapSort     ���� �ð� :%lf\n", (end - start));

    //RadixSort
    Setarr(Mainarr);
    start = (double)clock() / CLOCKS_PER_SEC;
    RadixSort(arr, n);
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("RadixSort    ���� �ð� :%lf\n", (end - start));
    

    //printf("Sort : ");
    //PrintArr(arr, n);
    


    return 0;
}