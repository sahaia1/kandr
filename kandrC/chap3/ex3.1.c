#include <stdio.h>

int
binsearch(int x, int array[], int size) {
	int low, high, mid;
	low = 0;
	high = (size - 1);
	while ( low < high) {
		mid = (high + low) / 2;
		if (array[mid] >= x)
			high = mid;
		else
			low = mid + 1;
	}
	if (array[high] == x)
		return high;
	else
		return -1;
}

int
main() {
	int array[5];
	for (int i = 0; i < 5; i++)
		array[i] = i+1;
	int x = 4;
	int size = 5;
	printf("num found at position - %d\n", binsearch(x, array, size));
	return 0;
}