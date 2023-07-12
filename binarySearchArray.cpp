#include <iostream>

using namespace std;
int binsearch(int array[],int element,int size){
    int low=0,high,mid;
    
    high=size-1;
    
    while(low<=high){
        mid=(low+high)/2;
        if(array[mid]>element)
        high=mid-1;
        else if(array[mid]<element)
        low=mid+1;
        else
        return mid;
    }
    return -1;
}
int main()
{
	cout<<"_________BINARY SEARCH__________"<<endl;
    int array[]={40,5,20,25,10,30},element,size,ind;
    cout<<"Enter element to be searched=";
    cin>>element;
    size=sizeof(array)/sizeof(int);
    
    for (int i=0; i<size;i++)
        for (int j=0;j<size-i-1;j++)
            if (array[j]>array[j+1])
                swap(array[j],array[j+1]);
    cout<<"SORTED ARRAY:"<<endl;
    for(int i=0;i<size;i++){
    	cout<<array[i]<<" ";
	}
	cout<<endl;

    ind=binsearch(array,element,size);
    
    if (ind>=0)
    cout<<"Element found at index "<<ind;
    else
    cout<<"Element not found";
    return 0;
}

