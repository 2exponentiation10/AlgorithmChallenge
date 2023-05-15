#include <iostream>
#include <time.h>
using namespace std;
const int MAX = 100;
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int partition(int* data, int start, int end) {
    int pivot = data[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (data[j] <= pivot) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[end]);

    return i + 1;
}

void quickSort(int* data, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(data, start, end);
        printArray(data, 10);
        quickSort(data, start, pivotIndex - 1);
        quickSort(data, pivotIndex + 1, end);
    }
}

int main() {
    srand(time(0));
    int arr[MAX];
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Original data: ";
    printArray(arr, 20);

    cout << "Sorting process: " << endl;
    quickSort(arr, 0, 20 - 1);

    cout << "Sorted data: ";
    printArray(arr, 20);

    return 0;
}
