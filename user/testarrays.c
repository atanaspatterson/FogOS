#include "kernel/types.h"
#include "user/user.h"
#include "arrays.h"
#include "arrays.c" 

// test file
int main()
{
  int testarray[] = {1, 4, 18, 3, 2, 6, 7, 4, 9};
  printf("Original: ");
  print_array(testarray, 9);
  printf("Sorted: ");
  insertion_sort_int(testarray, 9);
  print_array(testarray, 9);
  return 0;
}
