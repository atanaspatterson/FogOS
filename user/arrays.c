#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include <stddef.h>
#include <limits.h>


void sort_int_array(int* arr, int size) {
	if (arr == NULL)
		return;
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
	if (arr == NULL)
		return -1;
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
	if (arr == NULL)
		return;
	for (int i = 0; i < size; i++) {
    	printf("%d ", arr[i]);
	}
	printf("\n");
}

void delete_at_index(int** arr, int index, int *size) {
	if (arr == NULL)
		return;
    if (index < 0 || index >= *size) {
        printf("Invalid index\n");
        return;
    }

    int* new_arr = (int*)malloc((*size - 1) * sizeof(int));
    if (new_arr == NULL) {
    	printf("malloc() could not be called\n");
        return;
    }

	// copy the first part until the index to delete, then skip in and copy the rest
    memcpy(new_arr, *arr, index * sizeof(int));
    memcpy(new_arr + index, *arr + index + 1, (*size - index - 1) * sizeof(int));

    free(*arr);
	*size = *size - 1;
    *arr = new_arr;
}

void add_at_index(int** arr, int value, int index, int *size) {
	if (arr == NULL)
		return;
    if (index < 0 || index > *size) {
        printf("Invalid index.\n");
        return;
    }

    int* new_arr = (int*)malloc((*size + 1) * sizeof(int));
    if (new_arr == NULL) {
        printf("malloc() could not be called\n");
        return;
    }

	// copy the first part until the index, add value, then copy the second part
    memcpy(new_arr, *arr, index * sizeof(int));
    new_arr[index] = value;
    memcpy(new_arr + index + 1, *arr + index, (*size - index) * sizeof(int));
    
    free(*arr);
    *size = *size + 1;
    *arr = new_arr;
}

int* array_intersection(int* arr1, int* arr2, int size1, int size2, int *new_size) {
  if (arr1 == NULL || arr2 == NULL)
    return NULL;

  sort_int_array(arr1, size1);
  sort_int_array(arr2, size2);

  int min = size1 < size2 ? size1 : size2;
  int* intersection = (int*)malloc(sizeof(int) * min);
  if (intersection == NULL) {
    printf("malloc could not be called\n");
    return NULL;
  }

  int i = 0;
  int j = 0;
  int k = 0;
  int prev = INT_MIN;

  while (i < size1 && j < size2) {
    if (arr1[i] == arr2[j] && arr1[i] != prev) { // Check for duplicates
      intersection[k++] = arr1[i];
      prev = arr1[i];
    }

    if (arr1[i] <= arr2[j]) {
      i++;
    } else {
      j++;
    }
  }

  *new_size = k;
  return intersection;
}


int* array_union(int* arr1, int* arr2, int size1, int size2, int *new_size) {
	if (arr1 == NULL || arr2 == NULL)
		return NULL;
	sort_int_array(arr1, size1);
	sort_int_array(arr2, size2);

	int max = size1 > size2 ? size1: size2;
	int* union_arr = (int*)malloc(sizeof(int) * max);
	if (union_arr == NULL) {
		printf("malloc could not be called\n");
		return NULL;
	}

	//int i = 0; 
	int j = 0;
	int k = 0;
	int prev = INT_MIN;

	// add unique elements of arr1
	// while (i < size1) {
	// 	if (arr1[i] != prev) { // Add only unique elements from arr1
	// 		union_arr[k] = arr1[i];
	// 	    prev = arr1[i];
	// 	}
	// }

	for (int l = 0; l < size1; l++) {
		if (arr1[l] != prev) {
			union_arr[k++] = arr1[l];
			prev = arr1[l];
		}
	}
	
	// Found this algorithm online - adds unique arr2 values
	for (j = 0; j < size2; j++) {
		int found = 0;
	    for (int l = 0; l < k; l++) {
	    	if (union_arr[l] == arr2[j]) {
	        	found = 1;
	            break;
	        }
	    }
	    if (!found) {
	 	   union_arr[k++] = arr2[j];
	    }
	}
	
	*new_size = k;	    
	return union_arr;	 
}



