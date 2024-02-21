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

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
    	printf("%d ", arr[i]);
	}
	printf("\n");
}


