#include<iostream>
using namespace std;

void conquer(int arr[], int L, int M, int H,int size) {
	int merge[size];
 	int i=L;
  	int j=M+1;
  	int x=L;

  while (i<=M && j<=H) {
    if (arr[i]<=arr[j]) {
      merge[x]=arr[i];
      x++;
      i++;
    } 
	else {
      merge[x]=arr[j];
      x++;
      j++;
    }
  }

  while(i<=M) {
    merge[x]=arr[i];
    x++;
    i++;
  }

  while(j<=H) {
    merge[x]=arr[j];
    x++;
    j++;
  }

  for (int f=L;f<=H;f++) {
    arr[f]=merge[f];
  }
}

void divide(int arr[], int L, int H, int size) {
  if (L<H) {
    int M=L+(H-L)/2;
    divide(arr,L,M,size);
    divide(arr,M+1,H,size);

    conquer(arr,L,M,H,size);
  }
}

void printarr(int arr[],int size){
	cout<<"Merge Sort :"<<endl;
	for(int j=0;j<size;j++) {
    cout<<arr[j]<<" ";
  }
}
int main() {
  	int arr[]={2,4,6,8,10};
  	int size=sizeof(arr)/sizeof(int);
    divide(arr,0,size-1, size);
    printarr(arr,size);
  	return 0;
}
