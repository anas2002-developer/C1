#include <iostream>
using namespace std;
int main()
{
    int array[]={40,5,20,25,10,30},size;
    size=sizeof(array)/sizeof(int);

	cout<<"TRAVERSING ARRAY:"<<endl;
    for(int i=0;i<size;i++){
    	cout<<array[i]<<endl;
	}
}

