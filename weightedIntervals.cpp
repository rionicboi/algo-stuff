#include<iostream>
//#include"job.h"
#include"mergeSort.h"
using namespace std;
int findLastConflictingJob(Job *J, int n)
{
	for(int i=n-1; i>=0; i--)
	{
		if(J[i].finish<=J[n].start)
			return i;
	}
	return -1;
}
int findMaxProfit(Job* J,int size)
{
	mergeSort(J, 0, size-1, size);
	int n=size;
	if(n==0)
	{
		return 0;
	}
		int maxWeight[n];
		maxWeight[0]=J[0].weight;
		for(int i=1; i<n; i++)
		{
			int index=findLastConflictingJob(J,i);
			int incl=J[i].weight;
			if(index!=-1)
			{
				incl+=maxWeight[index];
			}
			maxWeight[i]=max(incl,maxWeight[i-1]);
		}
		return maxWeight[n-1];
}
	
int main()
{
	Job* J;
	int size;
	cout<<"Enter the number of Jobs"<<endl;
	cin>>size;
	J=new Job[size];
	for(int i=0; i<size; i++)
	{
		cout<<"Enter the start time of job "<<i+1<<endl;
		cin>>J[i].start;
		cout<<"Enter the finish time of job "<<i+1<<endl;
		cin>>J[i].finish;
		cout<<"Enter the weight of job"<<i+1<<endl;
		cin>>J[i].weight;
	}
    cout << "The maximum profit is " << findMaxProfit(J,size)<<endl;
    cout<<"The jobs are: "<<endl;
    /*for(int i=0; i<size; i++)
    {
    	cout<<J[i].start<<" "<<J[i].finish<<" "<<J[i].weight<<endl;
	}*/
}
