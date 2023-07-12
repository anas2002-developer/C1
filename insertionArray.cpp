
#include <iostream>
using namespace std;
int main(){
    int size,pos,element,arr[100];
    
    cout<<"Arrary Size=";
    cin>>size;
    
    cout<<"Array elements :";
    for(int i=0;i<size;i++)
	{
    cin>>arr[i];
    }
    
    cout<<"Enter element=";
    cin>>element;
    cout<<"Position=";
    cin>>pos;
    
	size++;
    for(int i=size-1;i>=pos;i--)
	{
    arr[i]=arr[i-1];
    }
    
    arr[pos-1]=element;

    
    
    cout<<"New Array :";
    for(int i=0;i<size;i++)
	{
    cout<<arr[i]<<" ";
    }
    return 0;
}

