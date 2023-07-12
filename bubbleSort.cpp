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

	for(int i=0;i<size-1;i++){				//size-1 - n-1 iterations are must required
		for(int j=0;j<size-i-1;j++){		//size-i-1 - beacause we must not access last element it will be accessed by j+1 
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);	
			}
		}
	}
	printarr(arr,size);
}
