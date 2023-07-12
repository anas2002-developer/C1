#include<iostream>
using namespace std;

class QUEUEEEE{
	public:
	int array[5];
	int front;
	int back;
	int size;
	QUEUEEEE(){
		front=-1;
		back=-1;
		size=0;
		for(int i=0;i<5;i++){
			array[i]=0;
			size++;
		}
	}

bool isEmpty(){
	return (front==-1 || front>back);
}

bool isFull(){
	return back==size-1;
}

void push(int x){
	if(isFull()){
		cout<<"OVERFLOW/n";
	}
	else{
		back++;
		array[back]=x;
		if(front==-1){
			front++;
		}
	}
}

int pop(){
	if(isEmpty()){
		cout<<"UNDERFLOW\n";
	}
	else{
		int rmv=array[front];
		array[front]=0;
		front++;
		return rmv;
	}
}

int peek(){
	cout<<"Peek ";
	return array[front];
}

void update(int x,int pos){
	if(pos>back+1 || pos<1){
		cout<<"Position Out of Bound\n";
	}
	else{
		array[pos-1]=x;
	}
}
void traverse(){
	if(isEmpty()){
		cout<<"UNDERFLOW\n";
	}
	else{
		cout<<"QUEUEEEE-";
		for(int i=front;i<=back;i++){
			cout<<array[i]<<" ";
		}
	}
}

int length(){
	return back-front+1;
}

};

int main(){
	QUEUEEEE obj;
	obj.push(2);
	obj.push(4);
	obj.push(6);
	obj.push(8);
	obj.push(10);
	
	obj.pop();
	cout<<obj.peek()<<endl;
	obj.update(18,4);
	
	cout<<obj.length()<<endl;
	obj.traverse();
	return 0;
}
