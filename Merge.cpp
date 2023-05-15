#include <iostream>;
using namespace std;
int result[20]; 
int len = 20;
void Merge(int arr[], int start, int center, int end){
	int i = start;
	int j = center + 1;
	int k = start;

	while (i <= center && j <= end) {
		if (arr[i] <= arr[j]) {
			result[k] = arr[i];
			i++;
		}
		else {
			result[k] = arr[j];
			j++;
		}
		k++;
	}
	if (i > center) {
		for (int q = j ; q <= end; q++) {
			result[k] = arr[q];
			k++;
		}
	}
	else {
		for (int p = i; p <= center; p++) {
			result[k] = arr[p];
			k++;
		}
	}

	for (int e = start; e <= end; e++) {
		arr[e] = result[e];
	}

}

void sort(int arr[], int start, int end) {
	if (start < end) {
		int center = (start + end) / 2;
		sort(arr, start, center);
		sort(arr, center + 1, end);
		Merge(arr, start, center, end);
	}

	cout << "sorting: ";
	for (int i = start; i <= end; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}

		

int main() {
	int data[20];
	for (int i = 0; i < len; i++) {
		data[i] = rand() % 100;
	}
	cout << "data: ";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	cout << endl;

	sort(data, 0, len - 1);

	cout << endl;
	cout << "result: ";
	for (int i = 0; i < len; i++) {
		cout << data[i] << " ";
	}
	return 0;
}