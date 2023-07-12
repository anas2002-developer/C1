#include<iostream>
using namespace std;


void Traversal( int arr[] , int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void Insertion( int arr[] , int size ,int pos, int element){
	
	cout<<"Element (to insert): ";
	cin>>element;
	cout<<"Position : ";
	cin>>pos;
	size++;
	
	for(int i=size-1;i>=pos;i--){
		arr[i]=arr[i-1];
	}
	arr[pos-1]=element;
	Traversal(arr,size);
}

void Deletion( int arr[] , int size,int pos, int element){
	pos=-1;
	cout<<"Element (to delete): ";
	cin>>element;
	
	for(int i=0;i<size;i++){
		if(arr[i]==element){
			pos=i+1;
		}
	}
	
	if(pos>0){
		for(int i=pos-1;i<size-1;i++){
			arr[i]=arr[i+1];
		}
		size--;
	}
	else{
		cout<<"Element not found\n";
	}
	Traversal(arr,size);
}


int main(){
	int arr[]={2,4,6,8,10};
	int element,pos,size;
	size=sizeof(arr)/sizeof(int);
	
	int choice,torf=1;
    while(torf){
        cout<<endl<<endl;
        cout<<"*******************************"<<endl;
        cout<<"Operations (ARRAY):"<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Traversing"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice(1-4):";
        cin>>choice;
        switch(choice){
        	case 1:
				Insertion(arr,size,pos,element);
				size++;
				break;
			case 2:
				Deletion(arr,size,pos,element);
				size--;
				break;
			case 3:
				Traversal(arr,size);
				break;
			case 4:
				torf=0;break;
			default:
				torf=0;break;
		}
	}
	return 0;
}
