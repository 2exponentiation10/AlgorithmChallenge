#include <iostream>
using namespace std;

void Bubble(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			cout << "sorting: ";
			for (int k = 0; k < len; k++) {
				cout << arr[k] <<" ";
			}
			cout << endl;
		}
	}
}


int main() {
	int data[20];
	int len = 20;

	for (int i = 0; i < len; i++) {
		data[i] = rand() % 100;
	}

	cout << "data: ";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	cout << endl;

	Bubble(data, len);

	cout << endl;
	cout << "result: ";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	return 0;
}