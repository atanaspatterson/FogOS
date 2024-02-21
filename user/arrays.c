#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "arrays.h"

// insertion sort
void insertion_sort_int(int arr[], int size) {
	for (int i = 1; i < size; i++) {
    	int curr = arr[i];
   		int j = i - 1;
    	while (j >= 0 && arr[j] > curr) {
      		arr[j + 1] = arr[j];
      		j = j - 1;
   		}
    	arr[j + 1] = curr;
	}
}

int binary_search(int arr[], int target, int size) {
	int low = 0;
	int high = size - 1;
	
	while (low <= high) {
		int mid = ((high - low) / 2) + low;
		int currentValue = arr[mid];
		if (currentValue == target) {
			return mid;
		} if (currentValue < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
    	printf("%d ", arr[i]);
	}
	printf("\n");
}


