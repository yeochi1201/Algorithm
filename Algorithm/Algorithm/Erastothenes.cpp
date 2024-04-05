#include <iostream>

using namespace std;

class Erastothenes {
private:
	bool* primeArray;
	int num;
public:
	Erastothenes(int n) {
		primeArray = new bool[n + 1];
		num = n;
		for (int i = 0; i < num; i++) {
			primeArray[i] = true;
		}
	}

	void Calc() {
		for (int i = 2; i <= num; i++) {
			if (primeArray[i] == true) {
				for (int j = i*2; j <= num; j+=i) {
					primeArray[j] = false;
				}
			}
		}
	}
};