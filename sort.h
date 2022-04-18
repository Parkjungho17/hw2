#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <time.h>


# define MAX_SIZE 20000
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int Merge_sorted[MAX_SIZE];
int Mainarr[MAX_SIZE];
int arr[MAX_SIZE];

void ExchangeSort(int arr[], int n);
void Merge(int arr[], int left, int m, int right);
void MergeSort(int arr[], int left, int right);
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);
void heap_swap(int arr[], int i, int j);
void heap(int arr[], int n, int i);
void HeapSort(int arr[], int n);
void RadixSort(int arr[], int n);
void PrintArr(int arr[], int n);
void Setarr(int a[]);