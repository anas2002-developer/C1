#include<iostream>
using namespace std;

class queueArray{
	int arr[5];
	int front;
	int back;
	public:
	int size=0;					//if not defined default value is 1
	queueArray(){
		front=-1;
		back=-1;
		for(int i=0;i<5;i++){
			arr[i]=0;
			size++;
		}
	}
	
	//operations:
	
	bool isEmpty(){
		return (front==-1 || front>back);
	}
	bool isFull(){
		return back==size-1;
	}	
	void enqueue(int x){
		if (isFull()){
			cout<<"OVERFLOW"<<endl;
		}
		else{
			back++;
			arr[back]=x;
			if(front==-1){
				front++;
			}
		}
	}
	int dequeue(){
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		else{
			int poped=arr[front];
			arr[front]=0;
			front++;
			cout<<endl<<"Element dequeued is ";
			return poped;
		}
	}
	int peek(){
		cout<<endl;
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		else{
			cout<<"element at front->";
			return arr[front];
		}
	}
	void update(int x, int pos){
		cout<<endl;
		if (pos-1>back || pos<1){						//pos-1 = ind
			cout<<"position out of bound"<<endl;
		}
		else{
			arr[pos-1]=x;
		}
	}
	void traverse(){
		cout<<endl<<endl<<"queue = ";
		if (isEmpty()){
			cout<<"UNDERFLOW";}
		for(int i=front;i<=back;i++){
			cout<<arr[i]<<" ";
		}
	}
	int length(){
		return back-front+1;
	}
};

int main(){
	queueArray obj;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	obj.enqueue(6);
	cout<<obj.dequeue();
		cout<<obj.dequeue();
	obj.traverse();
	cout<<endl<<"Length="<<obj.length()<<endl;
}
