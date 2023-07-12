#include<iostream>
using namespace std;

class CQUEUEEEE{
	public:
	int array[5];
	int front;
	int back;
	int size;
	CQUEUEEEE(){
		front=-1;
		back=-1;
		size=0;
		for(int i=0;i<5;i++){
			array[i]=0;
			size++;
		}
	}

bool isEmpty(){
	return (front==-1);
}

bool isFull(){
	return (back+1)%size==front;
}

void push(int x){
	if(isFull()){
		cout<<"OVERFLOW/n";
	}
	else{
		back=(back+1)%size;
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
		front=(front+1)%size;
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
	cout<<"C QUEUEEEE-";
	if (back>=front){
			for(int i=front;i<=back;i++){
			cout<<array[i]<<" ";}
		}
	
	else{
		for(int i=0;i<=back;i++){
			cout<<array[i]<<" ";
		}
		for(int i=front;i<size;i++){
			cout<<array[i]<<" ";
		}
	}
}

int length(){
	return size;
}

};

int main(){
	CQUEUEEEE obj;
	obj.push(2);
	obj.push(4);
	obj.push(6);
	obj.pop();
	obj.push(8);
	obj.push(10);
	
	obj.push(100);
	
	obj.traverse();
	return 0;
}
