#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int selectionSort(int arr[], int size) {
	int cmp = 0;
	int minVal, minIndex,temp;
	for (int i = 0; i < size; i++) {
			minVal = arr[i];
			minIndex = i;
			for (int j = i + 1; j < size; j++) {
				if (arr[j] < minVal) {
					minVal = arr[j];
					minIndex = j;
				}
				cmp++;
			}
			temp = arr[i];
			arr[i] = minVal;
			arr[minIndex] = temp;
	}
	return cmp;
}
int main() {
	int size, cmp;
    int *arr;
    ofstream file;
    file.open("selectSortData.csv", ios::out);
	
    for (int i = 0; i < 100; i++) {
        size = (rand() % 1000) + 30;
        arr = new int[size];
        for (int j = 0; j < size; j++) {
            arr[j] = (rand() % 100);
        }
        cmp = selectionSort(arr, size);
        cout << "Size = " << size << " | Comparisons = " << cmp << endl;
        file << size << "," << cmp << "\n";
    }
    file.close();
    return 0;
}
