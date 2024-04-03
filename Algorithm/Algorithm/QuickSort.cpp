#include <iostream>

using namespace std;

class QuickSort {
private:
	int* array;
public:
	QuickSort(int* array) {
		this->array = array;
	}

	void Exchange(int aidx, int bidx) {
		int temp = array[aidx];
		array[aidx] = array[bidx];
		array[bidx] = array[aidx];
	}

	int Partition(int start, int end) {
		int pivot = array[start];
		int low = start + 1;
		int high = end;
		while (low <= high) {
			while (array[low] < pivot) {
				low++;
			}
			while (array[high] > pivot) {
				high++;
			}
			if (low <= high) {
				Exchange(low, high);
			}
		}
		Exchange(start, high);
		return high;
	}
	void Sort(int start, int end) {
		if (start < end) {
			int pivot = Partition(start, end);

			Sort(start, pivot-1);
			Sort(pivot+1, end);
		}
	}
};