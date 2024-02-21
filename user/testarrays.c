#include "kernel/types.h"
#include "user/user.h"
#include "arrays.h"
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
	printf("Find 7: %d\n", binary_search(testarray, 7, 9)); // returns the index of 7
	printf("Find 8: %d\n", binary_search(testarray, 8, 9)); // returns -1 (not in array)

  

  
  return 0;
}
