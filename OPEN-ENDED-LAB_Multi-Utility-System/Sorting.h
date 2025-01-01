#ifndef SORTING_H
#define SORTING_H
class Sorting {
public:
	void mergeSort(int arr[], int left, int right, int& comparisons, int& swaps);
	void quickSort(int arr[], int low, int high, int& comparisons, int& swaps);

};
#endif
