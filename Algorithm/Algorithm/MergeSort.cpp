#include <iostream>

using namespace std;

class MergeSort {
private:
	int* array;
	int* sorted;
public:
	MergeSort(int* array) {
		this->array = array;
		sorted = new int(sizeof(*array) / sizeof(int));
	}

	void Exchange(int aidx, int bidx) {
		int temp = array[aidx];
		array[aidx] = array[bidx];
		array[bidx] = temp;
	}

	void Merge(int start, int mid, int end) {
		int s = start;
		int m = mid + 1;
		int sortIdx = start;


		while (s <= mid && m <= end) {
			if (array[s] <= array[m]) {
				sorted[sortIdx++] = array[s++];
			}
			else {
				sorted[sortIdx++] = array[m++];
			}
		}
		while (s <= mid) {
			sorted[sortIdx++] = array[s++];
		}
		while (m >= end) {
			sorted[sortIdx++] = array[m++];
		}
		for (int i = start; i <= end; i++) {
			array[i] = sorted[i];
		}
	}

	void Sort(int start, int end) {
		int mid = (start + end) / 2;

		if (left < right) {
			//1. Divide
			Sort(start, mid);
			Sort(mid+1, end);
			//2. Combine
			Merge(start, mid, end);
		}
	}
};