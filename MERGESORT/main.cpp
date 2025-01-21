#include<iostream>
#include<stdlib.h>
using namespace std;
class List
{
	int a[10];
	int maxSize;
	public:
	int size;
	List()
	{
		maxSize=10;
		size=0;
	}
	void getList();
	void printList();
	void MergeSort(int,int);
	void Merge(int,int,int);

};
void List::getList()
{
	int n;
	cout<<"\nEnter n:";
	cin>>n;
	if(n>maxSize)
	{
		cout<<"\nMax size="<<maxSize;
		exit(0);
	}
	else
	{
		cout<<"\nEnter array elements :";
		int i;
		for(i=0;i<n;i++)
			cin>>a[i];
		size=n;
	}
}
void List::printList()
{
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
}
void List::MergeSort(int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		Merge(low,high,mid);
	}
}
void List::Merge(int low,int high,int mid)
{
	int i,j,k;
	int b[10];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i=i+1;
			k=k+1;
		}
		else
		{
			b[k]=a[j];
			j=j+1;
			k=k+1;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i=i+1;
		k=k+1;
	}
       while(j<=high)
	{
		b[k]=a[j];
		j=j+1;
		k=k+1;

	}

	for(int x=low;x<k;x++)
		a[x]=b[x];
}

int main()
{
	List l;
	l.getList();
	cout<<"\nArray Elements are:";
	l.printList();
	l.MergeSort(0,l.size-1);
	cout<<"\nAfter Sorting:\n";
	l.printList();
}
