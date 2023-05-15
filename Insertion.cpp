#include <iostream>
using namespace std;

void Insertion(int arr[], int len) {
	for (int i = 0; i < len-1; i++) {
		int j = i;
		while (arr[j] > arr[j + 1])
		{
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
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

	Insertion(data, len);

	cout << endl;
	cout << "result: ";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	return 0;
}