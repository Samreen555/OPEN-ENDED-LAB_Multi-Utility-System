#include "Sorting.h"
#include <iostream>
using namespace std;

// Helper function for Merge Sort
void merge(int arr[], int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        swaps++;
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
        swaps++;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
        swaps++;
    }

    delete[] L;
    delete[] R;
}

void Sorting::mergeSort(int arr[], int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

// Helper function for Quick Sort
int partition(int arr[], int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        comparisons++;
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void Sorting::quickSort(int arr[], int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}
