#include <iostream>
using namespace std;

void MaxHeap(int arr[], int len ) {
	for (int i = 1; i < len; i++) {
		int c = i;
		while (c != 0) {
			int root = (c - 1) / 2;
			if (arr[root] < arr[c]) {
				int temp = arr[root];
				arr[root] = arr[c];
				arr[c] = temp;
			}
			c = root;
		}
		
		if (i%3 == 0 or i == 1) {
			cout << "Sort: ";
			for (int j = 0; j < len; j++) {
				cout << arr[j] << " ";
			}
			cout << endl;
		}
		else {
			cout << "." << endl;
		}
	}
	cout << endl;
	cout << "MaxHeap: ";
	for (int j = 0; j < len; j++) {	
		cout << arr[j] << " ";
	}

}

void Ascendingsorting(int arr[], int len) {
	int k = 0;
	for (int i = len - 1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		int root = 0;
		int c = 1;
		while ( c < i ) {
			c = 2 * root + 1;
			if (arr[c] < arr[c + 1] && c < i - 1) {
				c++;
			}
			if (arr[root] < arr[c] && c < i) {
				int temp = arr[root];
				arr[root] = arr[c];
				arr[c] = temp;
			}
			root = c;
		}
		
		if(k % 2 == 0 or k == 0){
			cout << "Sort: ";
			for (int j = 0; j < len; j++) {
				cout << arr[j] << " ";
			}
			cout << endl;
		}
		else {
			cout << " . ";
			cout << endl;
		}
		k++;
	}
	cout << endl;
	cout << "sortingHeap: ";
	for (int j = 1; j < len; j++) {
		cout << arr[j] << " ";
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

	MaxHeap(data, len);
	cout << endl;
	Ascendingsorting(data, len);

	return 0;

	

}
