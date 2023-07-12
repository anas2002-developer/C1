#include<iostream>
using namespace std;

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void printarr(int arr[],int size){
	for(int i=0;i<size;i++)
	cout<<arr[i]<<" ";
}

int partition(int arr[], int L, int H){
	int pivot=arr[H];
	int pivotindex=L;
	
	for(int i=L;i<H;i++){
		if(arr[i]<pivot){
			swap(&arr[i],&arr[pivotindex]);
			pivotindex++;
		}
	}
	swap(&arr[pivotindex],&arr[H]);
	return pivotindex;
}
void QuickSort(int arr[], int L, int H){
 if(L<H)
 {
 int p = partition(arr, L, H);
 QuickSort(arr, L, (p-1));  //Left partition
 QuickSort(arr, (p+1), H);  //Right partition
 }
}
 
int main()
{
	int arr[100];
	int size;
	cout<<"Enter size of array :";
	cin>>size;
	cout<<"Enter "<<size<<" elements of array = ";
	//int size=sizeof(arr)/sizeof(int);
	
	for(int i=0;i<size;i++)
	cin>>arr[i];
 
 	QuickSort(arr,0,(size-1));
 
 	printarr(arr,size);
 	return 0;
}
