#include <iostream>
using namespace std;

void Selection(int arr[], int len) {
	int key=NULL;
	for (int i = 0; i < len; i++) {
		int smallest = 1000;
		for (int j = i; j < len; j++) {
			if (smallest > arr[j]) {
				smallest = arr[j];
				key = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[key];
		arr[key] = temp;
		cout << "Sort: ";
		for (int k = 0; k < len; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;	
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

	Selection(data, len);

	cout << endl;
	cout << "result: ";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	return 0;
}
