// Sorting/Searching algorithms
// Union/Intersection of 2 arrays
// Deleting/Adding at index


void insertion_sort(int* arr, int size) {
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
