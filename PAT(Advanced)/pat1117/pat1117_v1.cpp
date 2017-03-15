#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>	// memset
using namespace std;

// Macros
#define ElementType int	// Type-independent, somewhat.
#define MAX_SIZE 100001
#define RESULT_MIGHT_NOT_EXIST 0	// What if there's not one?
#define CASE_NUM 5

// Function declarations
void quick_sort(ElementType* array, int begin, int end);
int get_eddington_number(ElementType* arr, int num);

int main() {
	ifstream cin("pat1117.in");

	int N;
	int* dist;
	int caseNum = CASE_NUM;
	
	while (caseNum--) {
		cin >> N;
		dist = new int[N];
		for (int i = 0; i < N; ++i) {
			cin >> dist[i];
		}

		//quick_sort(dist, 0, N);
		sort(dist, dist + N);

		cout << get_eddington_number( dist, N ) << endl;

		delete[] dist;
	}

	return 0;
}


// Tip: parameter 'end' means a last DEAD position of a container(array).
void quick_sort(ElementType* array, int begin, int end) {
	if (end - begin <= 1) return;	// Terminate, if number less than 1.

	int low = begin;
	int high = end - 1;
	int pivot = array[low];	// Take a pivot, and meantime that position is useless(for others to fill in).

	while (low < high) {
		while (low < high && array[high] >= pivot) --high;
		array[low] = array[high];
		while (low < high && array[low] < pivot) ++low;
		array[high] = array[low];
	}

	// Loop end, meantime there is 'low'=='high'.
	array[low] = pivot;

	// Recursively sorting, partitionally.
	quick_sort(array, begin, low);
	quick_sort(array, low + 1, end);
}

int get_eddington_number(ElementType* arr, int num) {
	int answer = 0;
	int idx = -1;
	for (; answer <= num; ++answer) {
		while (idx + 1 < num && answer >= arr[idx + 1]) {
			++idx;
		}
		if (num - 1 - idx == answer) {
			return answer;
		}
	}
	return RESULT_MIGHT_NOT_EXIST;
}
