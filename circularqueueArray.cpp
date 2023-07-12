#include<iostream>
using namespace std;

class circularqueueArray{
	int arr[5];
	int front;
	int back;
	public:
	int lencount;
	int size;					//if not defined default value is 1
	circularqueueArray(){
		size=0;
		lencount=0;
		front=-1;
		back=-1;
		for(int i=0;i<5;i++){
			arr[i]=0;
			size++;
		}
	}
	
	//operations:
	
	bool isEmpty(){
		return (front==-1);
	}
	bool isFull(){
		return (back+1)%size==front;
	}	
	void enqueue(int x){
		if (isFull()){
			cout<<"OVERFLOW"<<endl;
		}
		else{
			lencount++;
			back=(back+1)%size;
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
		if (front==back){
			int poped=arr[front];
			front=-1;
			back=-1;
			lencount--;
			cout<<endl<<"Element dequeued is ";
			return poped;
		}
		else{
			lencount--;
			int poped=arr[front];
			arr[front]=0;
			front=(front+1)%size;
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
		if (pos-1>size-1 || pos<1){					//wrong if whole queue is not traversed					//pos-1 = ind
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
		if (back>=front){
			for(int i=front;i<=back;i++){
			cout<<arr[i]<<" ";}
		}
		else{
	
		for(int i=0;i<=back;i++){
			cout<<arr[i]<<" ";
		}
		for(int i=front;i<size;i++){
			cout<<arr[i]<<" ";
		}
	}
	}
	int length(){
		return lencount;
	}
};

int main(){
	circularqueueArray obj;
	cout<<obj.isEmpty();
	cout<<obj.dequeue();
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	cout<<obj.dequeue();
	cout<<obj.dequeue();
	cout<<obj.dequeue();
	cout<<obj.dequeue();
	obj.enqueue(5);
	obj.enqueue(10);
	obj.enqueue(15);
	obj.update(20,5);
	cout<<obj.peek();
	obj.traverse();
	cout<<endl<<"Length="<<obj.length()<<endl;
}
