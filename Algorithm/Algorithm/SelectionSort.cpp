#include <iostream>

using namespace std;

class SelectionSort {
private:
	int* array;
public:
	SelectionSort(int* array) {
		this->array = array;
	}

	void Exchange(int aidx, int bidx) {
		int temp = array[aidx];
		array[aidx] = array[bidx];
		array[bidx] = array[aidx];
	}

	void Select(int size) {
		int cur = 1;
		int idx = 0;
		while (cur < size) {
			if (array[cur] < array[idx])
				Exchange(cur, idx);
			idx++;
			cur++;
		}
	}

	void Sort(int size) {
		int idx;
		for (int i = 0; i < size - 1; i++) {
			idx = i;
			for (int j =i+1; j < size; j++) {
				if (array[idx] > array[j]) {
					idx = j;
				}
			}
			Exchange(i, idx);
		}
	}
};