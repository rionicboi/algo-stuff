#include <iostream>
#include<cstdlib>
using namespace std;

void merge(int A[], int l , int mid, int r,int &c)
{
	int arr1 = mid -l +1;
	int arr2 = r - mid;
	
	int *a1 = new int[arr1];
	int *a2 = new int[arr2];
	
	cout<<"hello"<<endl;  
	for (int i = 0; i < arr1; i++)
	   {
		a1[i] = A[l + i];
	   }
    for (int j = 0; j < arr2; j++)
    	{
    	a2[j] = A[mid + 1 + j];
		}
 
    
    int indexOfa1 =0;
    int indexOfa2 =0;
    int indexOfmerge = l;

	while(arr1 > indexOfa1 && arr2> indexOfa2)
	{
		if(a1[indexOfa1]<= a2[indexOfa2])
		{
			A[arr1] = A[indexOfa1];
			indexOfa1++;

		}
		else
		{
			A[arr2] = A[indexOfa2];
			indexOfa2++;
		}
		indexOfmerge++;
	    c++;
	}
	
	 while (indexOfa1 < arr1) 
	{
        A[indexOfmerge]
            = a1[indexOfa1];
        indexOfa1++;
        indexOfmerge++;
        c++;
    }
    
      while (indexOfa2 < arr2) {
        A[indexOfmerge]
            = a2[indexOfa2];
        indexOfa2++;
        indexOfmerge++;
        c++;
    }
    delete[] a1;
    delete[] a2;
}




void mergeSort(int A[], int l, int r,int& c)
{
	if(l>=r) return;
	
	int mid = (l +r)/2;
	mergeSort(A,l,r,c);
	mergeSort(A,l,mid+1,c);
	cout<<"hello"<<endl;
	merge(A,l,mid,r,c);
	
}
void printArray(int A[], int size,int c)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " "<<c;
}


	
int main(){
    cout << "no of elements  |  no of comparision  "<< endl;
    int size;
	int *A;
	int c;
	for (int j =0; j<100;j++)
	{
		size = 30 + rand()%970;
		A= new int[size];
		
		for(int i=0; i<size;i++){
			A[i]= 30 + rand()%970;
		}
		
		c=0;
		
		mergeSort(A,0,size-1,c);
		//printArray(A,size,c);
		cout << "Size = " << size  << " | Comparisons = " << c << endl; 
	}
	return 0;
}

