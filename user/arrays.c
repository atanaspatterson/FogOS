#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "arrays.h"
#include <stddef.h>


// insertion sort
void insertion_sort_int(int* arr, int size) {
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

int binary_search(int* arr, int target, int size) {
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

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
    	printf("%d ", arr[i]);
	}
	printf("\n");
}

// int* delete_at_index(int arr[], int index, int size) {
//   int* new_arr = (int*)malloc((size - 1) * sizeof(int));
//   if (new_arr == NULL) {
//     return NULL;
//   }
//   
//   // Copy elements before the deleted index
//   for (int i = 0; i < index; i++) {
//     new_arr[i] = arr[i];
//   }
//   
//   int j = index + 1;
// 
//   for (int i = index; i < size - 1; i++) {
//     new_arr[i] = arr[j];
//     j++;
//   }
//   // Free the original array memory
//   
//   return new_arr;
// }

void delete_at_index(int** arr, int index, int size) {
    // Check for invalid index
    if (index < 0 || index >= size) {
        printf("Invalid index\n");
        return;
    }

    // Handle edge case where size is 1
    if (size == 1) {
        free(*arr);  // Free the original array
        *arr = NULL; // Set the pointer to NULL   // Update the size
        return;
    }

    int* new_arr = (int*)malloc((size - 1) * sizeof(int));
    if (new_arr == NULL) {
    	printf("malloc() could not be called\n");
        return;
    }

    memcpy(new_arr, *arr, index * sizeof(int));
    memcpy(new_arr + index, *arr + index + 1, (size - index - 1) * sizeof(int));

    // Update the array pointer and size
    *arr = new_arr;
}

