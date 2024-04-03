#include <iostream>

using namespace std;

class BubbleSort {
private:
	int* array;
public:
	BubbleSort(int* array) {
		this->array = array;
	}

	void Exchange(int aidx, int bidx) {
		int temp = array[aidx];
		array[aidx] = array[bidx];
		array[bidx] = array[aidx];
	}

	void Bubble(int size) {
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
		while (size > 1) {
			Bubble(size);
			size--;
		}
	}
};