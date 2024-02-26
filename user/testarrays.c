#include "kernel/types.h"
#include "user/user.h"
#include "arrays.h"
#include "arrays.c" 


// test file
int main()
{
	// test insertion sort
	int testarray[] = {1, 4, 18, 3, 34, 6, 7, 4, 9};
	
	
	printf("Original: ");
	print_array(testarray, 9);
	printf("Sorted: ");
	sort_int_array(testarray, 9);
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
	int arr_size = 5;
	print_array(arr, arr_size);
	delete_at_index(&arr, 2, &arr_size);
	print_array(arr, arr_size); // should print the array without 3	

	// test add at index
	add_at_index(&arr, 3, 2, &arr_size);
	print_array(arr, arr_size); // should print the array with 3

	// test array intersection
	int intersection_size = 0;
	int *intersection = array_intersection(arr, testarray, 5, 9, &intersection_size);
	print_array(intersection, intersection_size); // should print 1, 3 ,4
	

	


  
  return 0;
}
