//LINEAR SEARCH

#include <iostream>
using namespace std;
int main()
{
	cout<<"_________LINEAR SEARCH__________"<<endl;
    int array[]={40,5,20,25,10,30},element,size,ind=-1;
    cout<<"Element to be searched=";
    cin>>element;
    size=sizeof(array)/sizeof(int);

	cout<<"UNSORTED ARRAY:"<<endl;
    for(int i=0;i<size;i++){
    	cout<<array[i]<<" ";
	}
	cout<<endl;
    for(int i=0;i<size;i++){
    	if(array[i]==element){
    		ind=i;
		}
	}
	if(ind>=0)
	cout<<"Element found at position:"<<ind+1;
	else
	cout<<"Element not found";
}

