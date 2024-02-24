#include "kernel/types.h"
#include "user/user.h"
//#include "arrays.h"
#include "arrays.c" 


// test file
int main()
{
	// test insertion sort
	int testarray[] = {1, 4, 18, 3, 2, 6, 7, 4, 9};
	
	
	printf("Original: ");
	print_array(testarray, 9);
	printf("Sorted: ");
	insertion_sort_int(testarray, 9);
	print_array(testarray, 9);

	// test binary search
	printf("Find 7: %d\n", binary_search(testarray, 7, 9)); // returns 6, the index of 7
	printf("Find 8: %d\n", binary_search(testarray, 8, 9)); // returns -1 (not in array)

	// test delete at index
	int *arr = (int *)malloc(5 * sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	print_array(arr, 5);
	delete_at_index(&arr, 2, 5);
	print_array(arr, 4); // should print the array without 3

	


  
  return 0;
}
