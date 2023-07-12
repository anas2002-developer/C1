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

int main(){
	int arr[100];
	int size;
	cout<<"Enter size of array :";
	cin>>size;
	cout<<"Enter "<<size<<" elements of array = ";
	//int size=sizeof(arr)/sizeof(int);
	for(int i=0;i<size;i++)
	cin>>arr[i];

	for(int i=1;i<size;i++){				
		int current=arr[i];					//for traversig
		int j=i-1;							//sorted array
		while(j>=0 && current<arr[j]){
			arr[j+1]=arr[j];
			j--;
			}
			arr[j+1]=current;
		}
	printarr(arr,size);
}
