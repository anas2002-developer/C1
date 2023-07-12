#include<iostream>
using namespace std;

class dequeArray{
	int arr[5];
	int front;
	int back;
	public:
	int lencount;
	int size;					//if not defined default value is 1
	dequeArray(){
		front=-1;
		back=-1;
		size=0;
		lencount=0;
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
	void enqueuefront(int x){
		if (isFull()){
			cout<<"OVERFLOW"<<endl;
		}
		else{
			front=(front-1)%size;
			if(front<0){
				front=size-1;
			}
			arr[front]=x;
			lencount++;
		}
		
	}
	void enqueueback(int x){
		if (isFull()){
			cout<<"OVERFLOW"<<endl;
		}
		else{
			back=(back+1)%size;
			arr[back]=x;
			if(front==-1){
				front++;
			}
			lencount++;
		}
	}
	int dequeueback(){
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		if (front==back){
			int poped = arr[back];
			arr[back]=0;
			front=-1;
			back=-1;
			lencount--;
			cout<<"\ndequeued element ->";
			return poped;
		}
		else{
			int poped = arr[back];
			arr[back]=0;
			back=(back-1)%size;
			if (back<0){
				back=size-1;
			}
			lencount--;
			cout<<"\ndequeued element ->";
			return poped;
		}
	}
	int dequeuefront(){
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		if (front==back){
			int poped = arr[front];
			arr[front]=0;
			front=-1;
			back=-1;
			lencount--;
			cout<<"\ndequeued element ->";
			return poped;
		}
		else{
			int poped = arr[front];
			arr[front]=0;
			front=(front+1)%size;
			cout<<"\ndequeued element ->";
			lencount--;
			return poped;
		}
	}
	int peekfront(){
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
	int peekback(){
		cout<<endl;
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		else{
			cout<<"element at back->";
			return arr[back];
		}
	}
	void update(int x, int pos){
		cout<<endl;
		if (pos-1>size || pos<1){						//pos-1 = ind
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
	dequeArray obj;
	cout<<obj.isEmpty()<<endl<<endl;
	cout<<obj.dequeuefront();
	cout<<obj.dequeueback();
	cout<<endl<<endl;
	obj.enqueuefront(1);
	obj.enqueueback(2);
	obj.enqueuefront(3);
	obj.enqueueback(4);
	obj.enqueueback(6);
	obj.enqueueback(6);
	cout<<obj.dequeuefront();
	cout<<obj.dequeuefront();
	cout<<obj.dequeueback();
	cout<<obj.dequeueback();
	cout<<obj.dequeueback();
	cout<<obj.dequeuefront();
	obj.enqueuefront(3);
	obj.enqueueback(4);
	obj.enqueueback(6);
	obj.enqueueback(6);
	obj.enqueuefront(5);
	obj.update(20,5);
	cout<<obj.peekback();
	cout<<obj.peekfront();
	obj.traverse();
	cout<<endl<<"Length="<<obj.length()<<endl;
}
