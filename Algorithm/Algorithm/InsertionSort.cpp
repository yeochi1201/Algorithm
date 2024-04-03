#include <iostream>

using namespace std;

class InsertionSort {
private:
	int* array;
public:
	InsertionSort(int* array) {
		this->array = array;
	}

	void Insert(int start, int size) {
		int i;
		int key = array[start];
		for (i = start - 1; i >= 0; i--) {
			if (key < array[i])
				array[i + 1] = array[i];
			else
				break;
		}
		array[i + 1] = key;
	}

	void Sort(int size) {
		int start = 0;
		while (start != size) {
			Insert(start, size);
			start++;
		}
	}
};