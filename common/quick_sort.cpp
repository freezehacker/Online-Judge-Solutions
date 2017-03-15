#include <iostream>
#include <cstring>	// memcpy
#include <fstream>
#include <algorithm>	// sort
using namespace std;

#define ElementType int	// Type-independent, somewhat.

// Parameter 'end' means a last DEAD position of a container(array)
void quick_sort(ElementType* array, int begin, int end) {
	if (end - begin <= 1) return;	// Terminate, if number less than 1.


	int low = begin;
	int high = end - 1;

	int pivot = array[low];	// Take a pivot, and meantime that position is useless(for others to fill in).

	while (low < high) {

		while (low < high && array[high] >= pivot) 
			--high;
		array[low] = array[high];

		while (low < high && array[low] < pivot) 
			++low;
		array[high] = array[low];

	}

	// Loop end, meantime there is 'low'=='high'.
	array[low] = pivot;

	// Recursively sorting, partitionally.
	quick_sort(array, begin, low);
	quick_sort(array, low + 1, end);
}


// Note: ElementType must implement the operator, by default or by overloading.
void printArray(ElementType* arr, int num) {
	for (int i = 0; i < num; ++i) {
		cout << arr[i];
		if (i == num - 1) {
			cout << endl;
		} else {
			cout << ",";
		}
	}
}

// Note: this may need a callback function to compare some special type.
bool isArrayEqual(ElementType* a, int aNum, ElementType* b, int bNum) {
	if (aNum != bNum) {	// Make sure the number is equal firstly.
		return false;
	}

	for (int i = 0; i < bNum; ++i) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}


int main() {
	int N = 10;
	int a[N] = { 7,9,3,2,4,5,3,6,4,-1 };
	//int a[N] = {3,2,1,1};
	int b[N];
	memcpy(b, a, N * sizeof(int));	// Now a and b is equal.(but not the same)


	cout << "Before sorting: ";
	printArray(a, N);

	quick_sort(a, 0, N);	// Right way to call this sorting function.

	cout << "After sorting: ";
	printArray(a, N);
	

	// Check the function.
	sort(b, b + N);
	cout << "Right answer: ";
	printArray(b, N);
	if ( isArrayEqual( a, N, b, N ) ) {
		cout << "Right, maybe!" << endl;
	} else {
		cout << "Wrong quick-sorting function!Please check!" << endl;
	}


	return 0;
}
