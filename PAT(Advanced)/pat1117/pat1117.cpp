#include <iostream>
#include <fstream>
#include <cstring>	// memset
using namespace std;

// Macros
#define ElementType int	// Type-independent, somewhat.
#define MAX_SIZE 100001
#define IS_DEBUG false

// Global variables
int N;
int dist[MAX_SIZE];

// Function declarations
void quick_sort(ElementType* array, int begin, int end);
int binary_search(ElementType* list, int num, ElementType target);
int get_eddington_number(ElementType* arr, int num);

int main() {
	//ifstream cin("pat1117.in");

	cin >> N;
	//memset( dist, 0, sizeof( dist ) );
	for (int i = 0; i < N; ++i) {
		cin >> dist[i];
	}

	quick_sort(dist, 0, N);

	cout << get_eddington_number( dist, N ) << endl;
	return 0;
}


// Tip: parameter 'end' means a last DEAD position of a container(array).
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

// Return: the rightmost position whose value is just bigger than target.
int binary_search(ElementType* arr, int num, ElementType target) {
	int low_pos = 0;
	int high_pos = num - 1;

	int result_pos = -1;
	while ( low_pos <= high_pos ) {
		int middle_pos = ( low_pos + high_pos ) / 2;
		if ( target == arr[middle_pos] ) {
			result_pos = middle_pos;
			// Find the rightmost pos.
			for (int i = result_pos + 1; i < num; ++i) {
				if ( target == arr[i] ) {
					++result_pos;
				}
			}
			return result_pos;
		} else if ( target > arr[ middle_pos ] ) {
			low_pos = middle_pos + 1;
			result_pos = middle_pos;	// Just bigger pos
		} else {
			high_pos = middle_pos - 1;
		}
	}

	if (result_pos == -1) {
		return -1;
	}

	// Try to move right...
	for (int i = result_pos + 1; i < num; ++i) {
		if ( target > arr[i] ) {
			++result_pos;
		} else {
			break;
		}
	}

	return result_pos;
}

int get_eddington_number(ElementType* arr, int num) {
	int answer;
	for (answer = 0; answer <= N; ++answer) {
		int rightmost_position = binary_search( arr, num, answer );

		if (IS_DEBUG)
			cout << answer << ", rightmost position: " << rightmost_position;

		int bigger_count = N - rightmost_position - 1;

		if (IS_DEBUG)
			cout << ", count: " << bigger_count << endl;
		if (answer == bigger_count) {
			return answer;
		}
	}
	return 0;
}
