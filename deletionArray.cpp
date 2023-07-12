#include <iostream>
using namespace std;
int main() {
    int size,pos,element,arr[100];
    cout<<"Arrary Size=";
    cin>>size;
    
    cout<<"Array elements :";
    for(int i=0;i<size;i++)
	{
    cin>>arr[i];
    }
    
    cout<<"Enter element(to be deleted)=";
    cin>>element;
    
    for(int i=0;i<size;i++)
	{
    	if(arr[i]==element)
		{
			pos=i+1;
		}	
	}
	if (pos>0 && pos<=size){
	
    for(int i=pos-1;i<size-1;i++)
	{
    arr[i]=arr[i+1];
    }
    size--;
	}
	else
	{
		cout<<"Element not found";
	}
    
    cout<<"New Array :";
    for(int i=0;i<size;i++)
	{
    	cout<<arr[i]<<" ";
    }
    return 0;
}

