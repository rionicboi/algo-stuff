#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void merge(int array[], int left, int mid,
           int right,int& c)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne= 0, 
        indexOfSubArrayTwo= 0; 
    int indexOfMergedArray= left; 
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            c++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            c++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        c++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        c++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
int mergeSort(int array[], int begin, int end,int& c)
{
    if (begin >= end)
        return -1; 
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid,c);
    mergeSort(array, mid + 1, end,c);
    merge(array, begin, mid, end,c);
    return c;
}
 
void printArray(int A[], int size,int c)
{
    cout<<size<<"|"<<c<<endl;
}
//void printArray(int arr[], int size) {
//  for (int i = 0; i < size; i++)
//    cout << arr[i] << " ";
//  cout << endl;
//}
int main()
{
	ofstream file;
    file.open("mergeData.csv", ios::out);
	cout<<"No. of elements || No. of comparisons "<<endl;
	for(int j=0; j<100; j++)
	{
		int n;
		int *arr;
		int c=0;
		n=30+rand()%970;
		arr=new int[n];
		
		for(int i=0; i<n; i++)
		{
			arr[i]=30+rand()%970;
		}
		cout<<endl;
		int x=mergeSort(arr,0,n,c);
		if(x!=-1)
	       printArray(arr,n,c);
	    file << n << "," << x << "\n";
	}
	file.close();
	return 0;
}

